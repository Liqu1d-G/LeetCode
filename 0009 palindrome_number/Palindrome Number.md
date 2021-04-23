# Palindrome Number

## 题目

给你一个整数 x ，如果 x 是一个回文整数，返回 true ；否则，返回 false 。

回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。例如，121 是回文，而 123 不是。

> 示例 1：
>
> 输入：x = 121
> 输出：true
>
> 
>
> 示例 2：
>
> 输入：x = -121
> 输出：false
> 解释：从左向右读, 为 -121 。 从右向左读, 为 121- 。因此它不是一个回文数。
>
> 
>
> 示例 3：
>
> 输入：x = 10
> 输出：false
> 解释：从右向左读, 为 01 。因此它不是一个回文数。
>
> 
>
> 示例 4：
>
> 输入：x = -101
> 输出：false



> **提示：**
>
> - `-231 <= x <= 231 - 1`

## 题目大意

带符号倒序输出后与原数一样。

## 解题思路

首先想到的时暴力解法直接倒序。当然在开始倒序之前会有一些条件的筛选，比如负数一定不成立，正个位数一定成立。但是这样的复杂度有一点高。

再想到的是。可以同时砍x和倒序生成y，进行x与y比较，这样只用进行到一半就可以出结果。

然后考虑到原数可能时奇数位也有可能是偶数位，如果是偶数位就是比较`x==y`,奇数位就是比较`x/10==y`.

## 代码

逆序暴力解

```c
bool isPalindrome(int x){
    if(x<0)
        return false;
    else if(x<10)
        return true;
    else{
        long int y=0;
        int n=x;
        while(n!=0){
            y=y*10+n%10;
            n/=10;
        }
        if(x==y)
            return true;
        else
            return false;
    }
}
```
优化后只用比较一半

```c
bool isPalindrome(int x){
    if(x<0)
        return false;
    else if(x<10)
        return true;
    else if(!(x%10))
        return false;
    else{
        int y=0;
        do{
            y=y*10+x%10;
            x/=10;
            if((x==y)||((x/10)==y))
                return true;
        }while(x>y);
        return false;
    }
}

```



## 总结

暴力解

![image-20210423185856515](C:\Users\乔翯\AppData\Roaming\Typora\typora-user-images\image-20210423185856515.png)

优化解

![image-20210423191016309](C:\Users\乔翯\AppData\Roaming\Typora\typora-user-images\image-20210423191016309.png)

没啥好说的，主要是暴力逆序时注意可能会出现溢出问题，所以这里用的是`long int`

（Leetcode打分挺迷的

## 参考资料

