# Construct Binary Tree from Inorder and Postorder Traversal

## 题目

Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree and postorder is the postorder traversal of the same tree, construct and return the binary tree



>Example 1:
>
>![img](https://assets.leetcode.com/uploads/2021/02/19/tree.jpg)
>
>Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
>Output: [3,9,20,null,null,15,7]
>
>
>
>Example 2:
>
>Input: inorder = [-1], postorder = [-1]
>Output: [-1]
>
>
>

> Constraints:
>
> + 1 <= inorder.length <= 3000
> + postorder.length == inorder.length
> + -3000 <= inorder[i], postorder[i] <= 3000
> + inorder and postorder consist of unique values.
> + Each value of postorder also appears in inorder.
> + inorder is guaranteed to be the inorder traversal of the tree.
> + postorder is guaranteed to be the postorder traversal of the tree.

## 题目大意

通过中序和后序数组还原二叉树

## 解题思路

和105题相同

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

struct TreeNode *build(int* inorder,int start1,int end1,int* postorder,int start2,int end2)
{
    if(start1>end1||start2>end2)
        return NULL;
    struct TreeNode *root=(struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val=postorder[end2];
    int i;
    for(i=start2;inorder[i]!=root->val;i++);
    int leftsize=i-start1; int rightsize=end1-i;
    root->left=build(inorder,start1,i-1,postorder,start2,end2-1-rightsize);
    root->right=build(inorder,i+1,end1,postorder,end2-rightsize,end2-1);
    return root;
}

struct TreeNode* buildTree(int* inorder, int inorderSize,int* postorder,int postordersize)
{
    return build(inorder,0,inorderSize-1,postorder,0,postordersize-1);
}

int main(void)
{
    int postorder[]={9,15,7,20,3},inorder[]={9,3,15,20,7};
    struct TreeNode *p=buildTree(inorder,5,postorder,5);
    return 0;
}

```



## 总结

> 执行用时：12 ms, 在所有 C 提交中击败了94.43%的用户
>
> 内存消耗：11.4 MB, 在所有 C 提交中击败了89.72%的用户



## 参考资料

