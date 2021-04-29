# Construct Binary Tree from Preorder and Inorder Traversal

## 题目

Given two integer arrays `preorder` and `inorder` where `preorder` is the preorder traversal of a binary tree and `inorder` is the inorder traversal of the same tree, construct and return *the binary tree*.

 

> Example 1:
>
> ![img](https://assets.leetcode.com/uploads/2021/02/19/tree.jpg)
>
> Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
> Output: [3,9,20,null,null,15,7]
>
> 
>
> Example 2:
>
> Input: preorder = [-1], inorder = [-1]
> Output: [-1]

> Constraints:
>
> + 1 <= preorder.length <= 3000
> + inorder.length == preorder.length
> + -3000 <= preorder[i], inorder[i] <= 3000
>   preorder and inorder consist of unique values.
> + Each value of inorder also appears in preorder.
> + preorder is guaranteed to be the preorder traversal of the tree.
> + inorder is guaranteed to be the inorder traversal of the tree.

## 题目大意

根据前序遍历和中序遍历得到的数组，还原二叉树

## 解题思路

找到根节点，拆分数组递归

根节点就是前序遍历的第一个元素

左子树是中序遍历中根节点左边的部分，右子树是右边的部分，并且通过中序数组左右的长度结合来确定前序遍历中的划分方法



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

struct TreeNode *build(int* preoder,int start1,int end1,int* inorder,int start2,int end2)
{
    if(start1>end1||start2>end2)
        return NULL;
    struct TreeNode *root=(struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val=preoder[start1];
    int i;
    for(i=start2;inorder[i]!=root->val;i++);
    int leftsize=i-start2; int rightsize=end2-i;
    root->left=build(preoder,start1+1,start1+leftsize,inorder,start2,i-1);
    root->right=build(preoder,start1+1+leftsize,end1,inorder,i+1,end2);
    return root;
}

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize)
{
    return build(preorder,0,preorderSize-1,inorder,0,inorderSize-1);
}

int main(void)
{
    int preoder[]={3,9,20,15,7},inorder[]={9,3,15,20,7};
    struct TreeNode *p=buildTree(preoder,5,inorder,5);
    return 0;
}

```



## 总结

>  执行用时：16 ms, 在所有 C 提交中击败了83.30%的用户
>
>  内存消耗：11.3 MB, 在所有 C 提交中击败了92.79%的用户



还是思考每一个结点应该干什么，构建根节点，确定左右子树，递归

这题的关键在于用中序数组确定左右子树的大小，然后在前序数组中确定下标范围

## 参考资料



