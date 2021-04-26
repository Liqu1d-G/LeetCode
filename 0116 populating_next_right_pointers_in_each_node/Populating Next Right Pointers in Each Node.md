# Populating Next Right Pointers in Each Node

## 题目

You are given a perfect binary tree where all leaves are on the same level, and every parent has two children. The binary tree has the following definition:

```struct Node {
struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
```


Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

Follow up:

You may only use constant extra space.
Recursive approach is fine, you may assume implicit stack space does not count as extra space for this problem.




> Example 1:
>
> ![img](https://assets.leetcode.com/uploads/2019/02/14/116_sample.png)
>
> Input: root = [1,2,3,4,5,6,7]
> Output: [1,#,2,3,#,4,5,6,7,#]
> Explanation: Given the above perfect binary tree (Figure A), your function should populate each next pointer to point to its next right node, just like in Figure B. The serialized output is in level order as connected by the next pointers, with '#' signifying the end of each level.

> Constraints:
>
> The number of nodes in the given tree is less than 4096.
> -1000 <= node.val <= 1000

## 题目大意

将相邻的节点连起来，从左指向右



## 解题思路

首先想到的是，由于传入的是根节点，所以直接让传入节点的左孩子指向右孩子，但是这样有过问题，就是如果不是同一个父节点，就无法连接。

所以想到了，增加函数的参数，设置一个辅助函数，传入两个节点，先让其相连，再递归传入前者的左右孩子，后者的左右孩子，**前者的右孩子和后者的左孩子**。



## 代码

```c
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int val;
    struct Node *left;
    struct Node *right;
    struct Node *next;
};

struct Node* connect(struct Node* root) {
	if(root==NULL)
        return NULL;
    connectTwoNode(root->left,root->right);
    return root;
}

void connectTwoNode(struct Node *node1,struct Node *node2){
    if(node1==NULL||node2==NULL)
        return;
    node1->next=node2;
    connectTwoNode(node1->left,node1->right);
    connectTwoNode(node2->left,node2->right);
    connectTwoNode(node1->right,node2->left);
}

int main(void)
{
#if 1
    struct Node root, n10, n11, n20, n21, n22, n23;
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

    connect(&root);
    return 0;
}

```



## 总结

和226一样，关键在于，**如何把题目的要求细化成每个节点需要做的事情**。

思维要简单和直观。

这题的关键步骤是传入一个的右孩子和一个的左孩子，这样把他们相连。

这个此操作过程虽然可以做到无死角，但是也有许多重复步骤，或许可以优化？

最好成绩：20ms 8.5Mb



## 参考资料



