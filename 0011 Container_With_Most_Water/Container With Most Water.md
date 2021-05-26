# [Container With Most Water](https://leetcode-cn.com/problems/container-with-most-water/)

## 题目思路

首先想到暴力解法，时间复杂度为O(n^2^)，显然是不行的。

接着想到了**双指针法**，即从数组的头和尾同时开始，比对之后移动小的那一个。这样做的原因是，如果移动长的那一个，不仅宽度减少了，而且下一个高，有几种情况，但是面积均会减少：

1. 移动到的下一个柱子高度大于等于前一个，仍然使用没有移动的矮柱作为高
2. 移动到的下一个柱子小于前一个，但大于矮柱，仍然使用没有移动的矮柱作为高
3. 移动到的下一个柱子高度小于矮柱，用当前这个更小的高度作高

要么高不变，宽减小，要么高宽均减小，从逻辑上就可以排除。但是如果比对之后是移动矮的那一个，就不会出现这样的情况，可以遍历到所有可能的情况，时间复杂度为O（n）

## 代码

```C
int maxArea(int* height, int heightSize){
    int front=0,rear=heightSize-1,s=0;
    while(front<rear){
        int tmp=(rear-front)*(height[front]>=height[rear] ? height[rear]:height[front]);
        if(tmp>s)
            s=tmp;
        if(height[front]>=height[rear])
            rear--;
        else
            front++;
    }
    return s;
}
```

## 总结

> 执行用时：88 ms, 在所有 C 提交中击败了84.92%的用户
>
> 内存消耗：11.4 MB, 在所有 C 提交中击败了69.18%的用户

