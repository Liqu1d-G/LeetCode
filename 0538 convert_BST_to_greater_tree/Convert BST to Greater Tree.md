# 538. Convert BST to Greater Tree

## 题目

Given the `root` of a Binary Search Tree (BST), convert it to a Greater Tree such that every key of the original BST is changed to the original key plus sum of all keys greater than the original key in BST.

As a reminder, a binary search tree is a tree that satisfies these constraints:

+ The left subtree of a node contains only nodes with keys **less than** the node's key.

+ The right subtree of a node contains only nodes with keys **greater than** the node's key.

+ Both the left and right subtrees must also be binary search trees.

  

  Note: This question is the same as 1038: https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/



>Example 1:
>
>![img](https://assets.leetcode.com/uploads/2019/05/02/tree.png)
>
>Input: root = [4,1,6,0,2,5,7,null,null,null,3,null,null,null,8]
>Output: [30,36,21,36,35,26,15,null,null,null,33,null,null,null,8]
>
>Example 2:
>
>Input: root = [0,null,1]
>Output: [1,null,1]
>
>Example 3:
>
>Input: root = [1,0,2]
>Output: [3,3,2]
>
>Example 4:
>
>Input: root = [3,2,4,1]
>Output: [7,9,4,10]

> Constraints:
>
> + The number of nodes in the tree is in the range [0, 104].
> + -10^4^ <= Node.val <= 10^4^
> + All the values in the tree are unique.
> + root is guaranteed to be a valid binary search tree.

## 题目大意

给BST的每一个节点重新赋值，其值为所有原值比它大的节点的原值与他自己的原值之和

## 解题思路

中序的逆序遍历，得到一个降序的数组，在中序输出的位置，设置一个全局变量`sum`，来记录累加的和并赋给当前根节点。

或者设计辅助函数计算sum，然后把sum的值当作指针传进去。

## 代码

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int sum=0;
void preOrder(struct TreeNode* root)
{
    if(root==NULL)
        return;
    preOrder(root->right);
    sum+=root->val;
    root->val=sum;
    preOrder(root->left);
}

struct TreeNode* convertBST(struct TreeNode* root)
{
    preOrder(root);
    return root;
}

void Sum(struct TreeNode* root, int* ptrSum){
    if(root){
        Sum(root -> right, ptrSum);
        root -> val += *ptrSum;
        *ptrSum = root -> val;
        Sum(root -> left, ptrSum);
    }
}

struct TreeNode* convertBST2(struct TreeNode* root){
    int sum = 0;
    Sum(root, &sum);
    return root;
}


int main(void)
{
#if 1
    struct TreeNode root, n10, n11, n20, n21, n22, n23;
    root.val = 1;
    n10.val = 2;
    n11.val = 2;
    n20.val = 3;
    n21.val = 4;
    n22.val = 4;
    n23.val = 3;
    root.left = &n10;
    root.right = &n11;
    n10.left = &n20;
    n10.right = &n21;
    n11.left = &n22;
    n11.right = &n23;
    n20.left = NULL;
    n20.right = NULL;
    n21.left = NULL;
    n21.right = NULL;
    n22.left = NULL;
    n22.right = NULL;
    n23.left = NULL;
    n23.right = NULL;
#else
    struct TreeNode root, n10, n11, n21, n22;
    root.val = 1;
    n10.val = 2;
    n11.val = 2;
    n21.val = 3;
    n22.val = 4;
    root.left = &n10;
    root.right = &n11;
    n10.left = NULL;
    n10.right = &n21;
    n11.left = &n22;
    n11.right = NULL;
    n21.left = NULL;
    n21.right = NULL;
    n22.left = NULL;
    n22.right = NULL;
#endif
}
```



## 总结

LeetCode的解答过程中不能使用全局变量，因为上一组测试用例产生的结果会影响到下一组测试用例，所以最后提交的时候用的是指针。但是全局变量的做法也是对的。

> 执行用时：24 ms, 在所有 C 提交中击败了88.38%的用户
>
> 内存消耗：13.4 MB, 在所有 C 提交中击败了54.77%的用户

## 参考资料

