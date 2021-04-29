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
