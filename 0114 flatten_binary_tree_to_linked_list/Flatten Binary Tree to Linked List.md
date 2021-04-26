# Flatten Binary Tree to Linked List

## 题目

Given the root of a binary tree, flatten the tree into a "linked list":

The "linked list" should use the same TreeNode class where the right child pointer points to the next node in the list and the left child pointer is always null.
The "linked list" should be in the same order as a pre-order traversal of the binary tree.


> Example 1:
>
> ![img](https://assets.leetcode.com/uploads/2021/01/14/flaten.jpg)
>
> Input: root = [1,2,5,3,4,null,6]
> Output: [1,null,2,null,3,null,4,null,5,null,6]
>
> 
>
> Example 2:
>
> Input: root = []
> Output: []
>
> 
>
> Example 3:
>
> Input: root = [0]
> Output: [0]

> Constraints:
>
> The number of nodes in the tree is in the range [0, 2000].
> -100 <= Node.val <= 100

## 题目大意

把所有右子树连接到同一父节点的左子树上，组成一个可以从根节点通过右子树遍历的链表

## 解题思路

关键在于先把根节点的左右子树拉平，先不要去想细节，直接通过递归实现，然后再对已经拉平的左右子树进行操作。

然后先用临时变量储存左右子树，再把左子树置空放到右子树的位置上，再遍历找到当前的叶子节点，连上原先的右子树。

## 代码

```c
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void flatten(struct TreeNode* root){
    if(root == NULL || (root->left == NULL&&root->right==NULL)) return;
    
    flatten(root->left);
    flatten(root->right);
    
    if(root->left){
        struct TreeNode *p = root->left;
        while(p->right) p = p->right;

        p->right = root->right;
        root->right = root->left;
        root->left = NULL;
    }
    
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

    invertTree(&root);
    return 0;
}

```

## 总结

按照思路写出来一直报错，在找原左子树叶子节点是溢出，原因是可能本来左子树就不存在，所以应该先检查左子树是否存在。

这题是后序遍历框架，关键在于**先不管原理如何，相信函数就是能完成**，然后先利用函数将左右子树拉平，再进行原理上的细节操作。

最好成绩：4ms  6.5MB

## 参考资料



