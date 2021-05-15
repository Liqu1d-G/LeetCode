#include<stdlib.h>
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
struct TreeNode* deleteNode(struct TreeNode* root, int key){
    if(root==NULL) return NULL;
    if(root->val==key){
        if(root->left==NULL&&root->right==NULL)
            return NULL;
        else if(root->left==NULL||root->right==NULL){
            if(root->left==NULL)
                return root->right;
            else
                return root->left;
        }
        else{
            struct TreeNode *p=root->right;
            while(p->left!=NULL)    p=p->left;
            root->val=p->val;
            root->right=deleteNode(root->right,root->val);
        }
    }
    else if(root->val>key)
        root->left=deleteNode(root->left,key);
    else if(root->val<key)
        root->right=deleteNode(root->right,key);
    return root;
}