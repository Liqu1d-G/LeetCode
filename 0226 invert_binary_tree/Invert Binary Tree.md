# Invert Binary Tree

## 题目

Given the `root` of a binary tree, invert the tree, and return *its root*.



>Example 1:
>
>![img](https://assets.leetcode.com/uploads/2021/03/14/invert1-tree.jpg)
>
>Input: root = [4,2,7,1,3,6,9]
>Output: [4,7,2,9,6,3,1]
>
>
>
>Example 2:
>
>![img](https://assets.leetcode.com/uploads/2021/03/14/invert2-tree.jpg)
>
>Input: root = [2,1,3]
>Output: [2,3,1]
>
>
>
>Example 3:
>
>Input: root = []
>Output: []



> Constraints:
>
> The number of nodes in the tree is in the range [0, 100].
> -100 <= Node.val <= 100

## 题目大意

将除根节点外的每一个左右孩子节点互换

## 解题思路

用递归的思路，交换左右节点

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

struct TreeNode *invertTree(struct TreeNode* root)
{
    if (root == NULL) {
        return NULL;
    }
    struct TreeNode* tmp=root->left;
    root->left=root->right;
    root->right=tmp;
    invertTree(root->left);
    invertTree(root->right);
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

    invertTree(&root);
    return 0;
}

```

## 总结

写递归算法的关键是要明确函数的「定义」是什么，然后相信这个定义，利用这个定义推导最终结果，**绝不要跳入递归的细节**。

二叉树题目的一个难点就是，**如何把题目的要求细化成每个节点需要做的事情**。

最好成绩：0ms 5.9MB

## 参考资料

[递归思想](https://labuladong.gitbook.io/algo/di-yi-zhang-shou-ba-shou-shua-shu-ju-jie-gou/shou-ba-shou-shua-er-cha-shu/er-cha-shu-xi-lie-1)