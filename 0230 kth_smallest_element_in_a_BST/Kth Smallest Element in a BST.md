# Kth Smallest Element in a BST

## 题目

Given the `root` of a binary search tree, and an integer `k`, return the k^th^ (**1-indexed**) smallest element in the tree.

>Example 1:
>
>![img](https://assets.leetcode.com/uploads/2021/01/28/kthtree1.jpg)
>
>Input: root = [3,1,4,null,2], k = 1
>Output: 1
>
>
>
>Example 2:
>
>![img](https://assets.leetcode.com/uploads/2021/01/28/kthtree2.jpg)
>
>Input: root = [5,3,6,2,4,null,null,1], k = 3
>Output: 3

> **Constraints:**
>
> + The number of nodes in the tree is n.
> + 1 <= k <= n <= 104
> + 0 <= Node.val <= 104
>
> **Follow up:** 
>
> If the BST is modified often (i.e., we can do insert and delete operations) and you need to find the kth smallest frequently, how would you optimize?

## 题目大意

寻找搜索二叉树中第k小的元素

## 解题思路

首先想到的暴力解法是，因为搜索二叉树的中序遍历是升序，所以只需要中序遍历得出数组，再取第k个元素就行了，但是这样的复杂度有一些高。

稍微优化一点，在中序遍历的位置设置计数变量，当遍历到第k小的元素时，通过全局变量记录结果然后不断返回null跳出遍历，但是这样的复杂度也有一些高达到了`O(N)`。

可以利用搜索树的性质将其降到`O(logN)`，根据根节点所代表的二叉树中左子树和右子树元素的个数，可以判定第k个元素是在左子树还是右子树中，因为确定了左子树和右子树的元素个数，就可以确定根节点是第几小的，进而确定k的位置。



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

int numofRoot(struct TreeNode* root)
{
    if(!root) return 0;
    return 1+numofRoot(root->left)+numofRoot(root->right);
}

int kthSmallest(struct TreeNode* root, int k){
    int cnt=numofRoot(root->left);

    if(k<=cnt) 
        return kthSmallest(root->left,k);
    else if(k>cnt+1) 
        return kthSmallest(root->right,k-cnt-1);
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

```



## 总结

在搜索二叉树中把复杂度降低到对数的关键，在于想方设法去利用搜索二叉树的性质。

> 执行用时：12 ms, 在所有 C 提交中击败了86.72%的用户
>
> 内存消耗：10.1 MB, 在所有 C 提交中击败了52.66%的用户

## 参考资料

