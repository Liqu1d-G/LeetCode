# Maximum Binary Tree

## 题目

You are given an integer array nums with no duplicates. A **maximum binary tree** can be built recursively from nums using the following algorithm:

1. Create a root node whose value is the maximum value in nums.
2. Recursively build the left subtree on the **subarray prefix** to the **left** of the maximum value.
3. Recursively build the right subtree on the **subarray suffix** to the right of the maximum value.
   Return the **maximum binary tree** built from nums.



>Example 1:
>
>![img](https://assets.leetcode.com/uploads/2020/12/24/tree1.jpg)
>
>Input: nums = [3,2,1,6,0,5]
>Output: [6,3,5,null,2,0,null,null,1]
>Explanation: The recursive calls are as follow:
>
>- The largest value in [3,2,1,6,0,5] is 6. Left prefix is [3,2,1] and right suffix is [0,5].
>    - The largest value in [3,2,1] is 3. Left prefix is [] and right suffix is [2,1].
>        - Empty array, so no child.
>        - The largest value in [2,1] is 2. Left prefix is [] and right suffix is [1].
>            - Empty array, so no child.
>            - Only one element, so child is a node with value 1.
>    - The largest value in [0,5] is 5. Left prefix is [0] and right suffix is [].
>        - Only one element, so child is a node with value 0.
>        
>        - Empty array, so no child.
>        
>          
>
>Example 2:
>
>![img](https://assets.leetcode.com/uploads/2020/12/24/tree2.jpg)
>
>Input: nums = [3,2,1]
>Output: [3,null,2,null,1]

> **Constraints:**
>
> + 1 <= nums.length <= 1000
> + 0 <= nums[i] <= 1000
> + All integers in nums are **unique.**
>
> 

## 题目大意

选取数组中最大的值作为根节点，然后在左子树中放该数左边的部分，右子树放右边的部分。

## 解题思路

  先找到最大的节点，然后通过改变下标范围递归左子树和右子树。

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

```



## 总结

把题目的要求细化，搞清楚根节点应该做什么，然后剩下的事情抛给前/中/后序的遍历框架就行了

千万不要跳到递归的框架里！！！

最好成绩：52ms  26.4MB

## 参考资料

