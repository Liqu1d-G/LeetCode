#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* build(int *nums,int start,int end)
{
    if(start>end)
        return NULL;
    int root=start,max=nums[start];
    for(int i=start;i<=end;i++){
        if(max<nums[i]){
            root=i;
            max=nums[i];
        }
    }
    struct TreeNode *r=(struct TreeNode*)malloc(sizeof(struct TreeNode));
    r->val=max;
    r->left=build(nums,start,root-1);
    r->right=build(nums,root+1,end);
    return r;
}
  
struct TreeNode* constructMaximumBinaryTree(int* nums, int numsSize)
{
    return build(nums,0,numsSize-1);
}

int main(void)
{
    int nums[]={3,2,1,6,0,5};
    struct TreeNode *p=constructMaximumBinaryTree(nums,6);
    return 0;
}
