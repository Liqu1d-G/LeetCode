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
