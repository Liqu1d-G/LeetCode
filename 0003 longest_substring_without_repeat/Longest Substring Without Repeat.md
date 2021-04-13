# **Longest Substring Without Repeat**



## 题目

给定一个字符串，请你找出其中不含有重复字符的 **最长子串** 的长度。



>示例 1:
>
>输入: s = "abcabcbb"
>输出: 3 
>解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
>
>
>
>示例 2:
>
>输入: s = "bbbbb"
>输出: 1
>解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
>
>
>
>示例 3:
>
>输入: s = "pwwkew"
>输出: 3
>解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
>     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串.
>
>
>
>示例 4:
>
>输入: s = ""
>输出: 0

> **提示：**
>
> - `0 <= s.length <= 5 * 104`
> - `s` 由英文字母、数字、符号和空格组成

## 题目大意

在一个字符串中寻找没有重复字母的最长字串。

## 解题思路

设置一个滑动窗口，窗口的右边界不断地向前滑动一位直到数组结束，窗口的左边界在右窗口的的下一位与窗口内字符没有重复时不动，在有重复时，滑动到重复字符的下一位。

在每次左窗口滑动时，需要记录当前窗口的长度，当下一次左窗口滑动时，若窗口长度大于已知最大长度，则将其设为最大长度，最后返回最大长度。

需要注意的是，当右窗口的下一位是数组尾部即 ‘\0’ 时，会表现为无重复，因此无法进入max的判断，所以需要在最后返回max时进行max与当前窗口长度的判断。

## 代码

```c
#include<stdio.h>

int WhereRepeat(int front,int rear,char * s)
{
    for(front;front<=rear;front++)
        if(s[front]==s[rear+1])
            return front;
    return -1;
}

int lengthOfLongestSubstring(char * s){
    int front,rear,max;
    front=rear=0;max=1;
    if(s[0]=='\0')
        return 0;
    for(rear;s[rear]!='\0';rear++){
        int flag=WhereRepeat(front,rear,s);
        if(flag+1){
            if(max<rear-front+1)
                max=rear-front+1;
            front=flag+1;
        }
    }
    return max>(rear-front)?max:(rear-front);                          
}



int main()
{
    char a[]="";
    printf("%d",lengthOfLongestSubstring(a));
    return 0;
}
```



## 总结

本题运用了**滑动窗口**算法。

滑动窗口算法可以用以解决数组/字符串的子元素问题，它可以将嵌套的循环问题，转换为单循环问题，降低时间复杂度。

如果题目中求的结果有以下情况时可使用滑动窗口算法：

- 最小值 Minimum value
- 最大值 Maximum value
- 最长值 Longest value
- 最短值 Shortest value
- K值 K-sized value



要注意测试用例的设计，以及最好不要为了某种特殊情况而大面积修改代码，那样可能造成之前可以通过的测试用例无法通过了，这样的小单位修改影响越小越好。



如果报错 error: conflicting types for xxx ，可能的原因是调用的函数位置过于靠后，以至于还没有声明。



![image-20210413010716897](C:\Users\乔翯\AppData\Roaming\Typora\typora-user-images\image-20210413010716897.png)

## 参考资料

[滑动窗口](https://www.cnblogs.com/liang24/p/13595458.html)

[error: conflicting types for xxx ](https://blog.csdn.net/biubiuibiu/article/details/78326358)

[三目运算符   表达式1 ?  表达式2 ：表达式3](https://blog.csdn.net/yuanzhuohang/article/details/5176303)