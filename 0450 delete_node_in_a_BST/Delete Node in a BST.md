# Delete Node in a BST

## 题目

Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.

Basically, the deletion can be divided into two stages:

Search for a node to remove.
If the node is found, delete the node.
Follow up: Can you solve it with time complexity O(height of tree)?


> Example 1:
>
> ![img](https://assets.leetcode.com/uploads/2020/09/04/del_node_1.jpg)
>
> Input: root = [5,3,6,2,4,null,7], key = 3
> Output: [5,4,6,2,null,null,7]
> Explanation: Given key to delete is 3. So we find the node with value 3 and delete it.
> One valid answer is [5,4,6,2,null,null,7], shown in the above BST.
> Please notice that another valid answer is [5,2,6,null,4,null,7] and it's also accepted.
>
> ![img](https://assets.leetcode.com/uploads/2020/09/04/del_node_supp.jpg)
>
> Example 2:
>
> Input: root = [5,3,6,2,4,null,7], key = 0
> Output: [5,3,6,2,4,null,7]
> Explanation: The tree does not contain a node with value = 0.
>
> 
>
> Example 3:
>
> Input: root = [], key = 0
> Output: []

> Constraints:
>
> + The number of nodes in the tree is in the range [0, 10^4^].
> + -10^5^ <= Node.val <= 10^5^
> + Each node has a unique value.
> + root is a valid binary search tree.
> + -10^5^ <= key <= 10^5^

## 题目大意

对于一个给定的BST，给定一个key，删除该位置的节点，返回删除之后重新生成的合法的BST

## 解题思路

先找到该节点，即在每一次递归中判断当前值是不是key，若不是则递归其左右孩子节点，若是则进行删除操作。删除操作分为三种情况：

1. 若为叶子节点，则直接删除返回
2. 若只有一边有孩子节点，则孩子顶上
3. 若两边均有孩子节点，则找到左子树中最大的节点或右子树中最小的节点，然后让其变为当前节点，并删去其原来的位置（解题时用的时右子树中最小的节点）

## 代码

```c
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
```

## 总结

> 执行用时：24 ms, 在所有 C 提交中击败了94.12%的用户
>
> 内存消耗：13.2 MB, 在所有 C 提交中击败了90.50%的用户

注意第三种情况的求解。

注意要考虑key失效的情况，最先判断NULL。

## 参考资料



