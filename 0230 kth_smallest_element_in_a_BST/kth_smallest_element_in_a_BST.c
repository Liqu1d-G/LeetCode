#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int numofRoot(struct TreeNode* root)
{
    if(!root) return 0;
    return 1+numofRoot(root->left)+numofRoot(root->right);
}

int kthSmallest(struct TreeNode* root, int k){
    int cnt=numofRoot(root->left);

    if(k<=cnt) return kthSmallest(root->left,k);
    else if(k>cnt+1) return kthSmallest(root->right,k-cnt-1);
    return root->val;
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

    int k = 1;
    printf("%d\n", kthSmallest(&root, k));
    return 0;
}

