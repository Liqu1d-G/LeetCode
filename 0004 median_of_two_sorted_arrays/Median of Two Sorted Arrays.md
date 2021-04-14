# Median of Two Sorted Arrays

## 题目

给定两个大小分别为 `m` 和 `n` 的正序（从小到大）数组 `nums1` 和 `nums2`。请你找出并返回这两个正序数组的 **中位数** 。

**进阶：**你能设计一个时间复杂度为 `O(log (m+n))` 的算法解决此问题吗？



>示例 1：
>
>输入：nums1 = [1,3], nums2 = [2]
>输出：2.00000
>解释：合并数组 = [1,2,3] ，中位数 2
>
>示例 2：
>
>输入：nums1 = [1,2], nums2 = [3,4]
>输出：2.50000
>解释：合并数组 = [1,2,3,4] ，中位数 (2 + 3) / 2 = 2.5
>
>示例 3：
>
>输入：nums1 = [0,0], nums2 = [0,0]
>输出：0.00000
>
>示例 4：
>
>输入：nums1 = [], nums2 = [1]
>输出：1.00000
>
>示例 5：
>
>输入：nums1 = [2], nums2 = []
>输出：2.00000



> 提示：
>
> nums1.length == m
> nums2.length == n
> 0 <= m <= 1000
> 0 <= n <= 1000
> 1 <= m + n <= 2000
> -106 <= nums1[i], nums2[i] <= 106



## 题目大意

按顺序合并两个数组后，求其中位数。

## 解题思路

首先想到的是将两个数组合并成一个有序数组，再求其中位数，这样的时间复杂度是`O(max(m,n))`。

但是如果要变成`O(log (m+n))`，就要用到另一种方法，看到 log 可以很自然地想到二分法二分搜索。

关键的问题是如何切分数组 1 和数组 2 。其实就是如何切分数组 1 。先随便⼆分产⽣⼀个midA ，切分的线何时算满⾜了中位数的条件呢？即，线左边的数都⼩于右边的数，即，nums1[midA-1] ≤ nums2[midB] && nums2[midB-1] ≤ nums1[midA] 。如果这些条件都不满⾜，切分线就需要调整。如果 nums1[midA] < nums2[midB-1] ，说明 midA 这条线划分出来左边的数⼩了，切分线应该右移；如果 nums1[midA-1] > nums2[midB] ，说明 midA 这条线划分出来左边的数⼤了，切分线应该左移。经过多次调整以后，切分线总能找到满⾜条件的解。
假设现在找到了切分的两条线了， 数组 1 在切分线两边的下标分别是 midA - 1 和 midA 。 数组 2 在切分线两边的下标分别是 midB - 1 和 midB 。最终合并成最终数组，如果数组⻓度是奇数，那么中位数就是 max(nums1[midA-1], nums2[midB-1]) 。如果数组⻓度是偶数，那么中间位置的两个数依次是： max(nums1[midA-1], nums2[midB-1]) 和 min(nums1[midA],nums2[midB]) ，那么中位数就是 (max(nums1[midA-1], nums2[midB-1]) +min(nums1[midA], nums2[midB])) / 2 。

![IMG_0238(20210414-000612)](D:\1643076551\FileRecv\MobileFile\IMG_0238(20210414-000612).JPG)

## 代码

```c
#include <stdio.h>
#include <stdlib.h>

static double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size)
{
    int sum = nums1Size + nums2Size;
    int *nums = malloc(sizeof(int) * sum);
    int i = 0, j = 0, k = 0;
    int half = sum / 2 + 1;
    while (k < half) {
        int n;
        if (i < nums1Size && j < nums2Size) {
            n = (nums1[i] < nums2[j]) ? nums1[i++] : nums2[j++];
        } else if (i < nums1Size) {
            n = nums1[i++];
        } else if (j < nums2Size) {
            n = nums2[j++];
        }
        nums[k++] = n;
    }
    if (sum % 2) {
        return nums[k-1];
    } else {
        return (nums[k-1] + nums[k-2]) / 2.0;
    }
}

int main(int argc, char **argv)
{
    int r1[] = {1};
    int r2[] = {2};
 
    int n1 = sizeof(r1)/sizeof(r1[0]);
    int n2 = sizeof(r2)/sizeof(r2[0]);

    printf("Median is 1.5 = %f\n", findMedianSortedArrays(r1, n1, r2, n2));

    int ar1[] = {1, 12, 15, 26, 38};
    int ar2[] = {2, 13, 17, 30, 45, 50};
 
    n1 = sizeof(ar1)/sizeof(ar1[0]);
    n2 = sizeof(ar2)/sizeof(ar2[0]);

    printf("Median is 17 = %f\n", findMedianSortedArrays(ar1, n1, ar2, n2));

    int ar11[] = {1, 12, 15, 26, 38};
    int ar21[] = {2, 13, 17, 30, 45 };
 
    n1 = sizeof(ar11)/sizeof(ar11[0]);
    n2 = sizeof(ar21)/sizeof(ar21[0]);

    printf("Median is 16 = %f\n", findMedianSortedArrays(ar11, n1, ar21, n2));

    int a1[] = {1, 2, 5, 6, 8 };
    int a2[] = {13, 17, 30, 45, 50};
 
    n1 = sizeof(a1)/sizeof(a1[0]);
    n2 = sizeof(a2)/sizeof(a2[0]);

    printf("Median is 10.5 = %f\n", findMedianSortedArrays(a1, n1, a2, n2));

    int a10[] = {1, 2, 5, 6, 8, 9, 10 };
    int a20[] = {13, 17, 30, 45, 50};
 
    n1 = sizeof(a10)/sizeof(a10[0]);
    n2 = sizeof(a20)/sizeof(a20[0]);

    printf("Median is 9.5 = %f\n", findMedianSortedArrays(a10, n1, a20, n2));

    int a11[] = {1, 2, 5, 6, 8, 9 };
    int a21[] = {13, 17, 30, 45, 50};
 
    n1 = sizeof(a11)/sizeof(a11[0]);
    n2 = sizeof(a21)/sizeof(a21[0]);

    printf("Median is 9 = %f\n", findMedianSortedArrays(a11, n1, a21, n2));

    int a12[] = {1, 2, 5, 6, 8 };
    int a22[] = {11, 13, 17, 30, 45, 50};
    return 0;
}

```



**二分搜索法**

``` double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    if(nums1Size>nums2Size)
        return findMedianSortedArrays(nums2,nums2Size,nums1,nums1Size);
    else{
        int lmax1,lmax2,rmin1,rmin2;
        int lo,hi,c1,c2;
        lo=0;
        hi=nums1Size;
        while(lo<=hi){
            c1=(lo+hi+1)/2;
            c2=(nums1Size+nums2Size)/2-c1;
            lmax1=(c1==0)?INT_MIN:nums1[c1-1];
            rmin1=(c1==nums1Size)?INT_MAX:nums1[c1];
            lmax2=(c2==0)?INT_MIN:nums2[c2-1];
            rmin2=(c2==nums2Size)?INT_MAX:nums2[c2];
            if(lmax1>rmin2)
                hi=c1-1;
            else if(lmax2>rmin1)
                lo=c1+1;
            else
                break;
        }
        if((nums1Size+nums2Size)%2)
            return rmin1>rmin2?rmin2:rmin1;
        else
            return ((rmin1>rmin2?rmin2:rmin1)+(lmax1>lmax2?lmax1:lmax2))/2.0;
    }
}
```

## 总结

这个是时间复杂度是`O(max(m,n))`的分。

![image-20210414001123310](C:\Users\乔翯\AppData\Roaming\Typora\typora-user-images\image-20210414001123310.png)



## 参考资料

[二分搜索思路](https://github.com/halfrost/LeetCode-Go)

[二分查找有几种写法？它们的区别是什么？](https://www.zhihu.com/question/36132386)

[二分搜索题解](https://leetcode-cn.com/problems/median-of-two-sorted-arrays/solution/cyu-yan-er-fen-fa-by-pang-san-jin-3/)

