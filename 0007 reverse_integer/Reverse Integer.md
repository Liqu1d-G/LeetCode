# Reverse Inyeger

## 题目

给你一个 32 位的有符号整数 x ，返回将 x 中的数字部分反转后的结果。

如果反转后整数超过 32 位的有符号整数的范围 [−2^31,  2^31 − 1] ，就返回 0。

**假设环境不允许存储 64 位整数（有符号或无符号）。**



> 示例 1：
>
> 输入：x = 123
> 输出：321
>
> 示例 2：
>
> 输入：x = -123
> 输出：-321
>
> 示例 3：
>
> 输入：x = 120
> 输出：21
>
> 示例 4：
>
> 输入：x = 0
> 输出：0

> **提示：**
>
> - `-231 <= x <= 231 - 1`



## 题目大意

把一个整数倒序输出



## 解题思路

倒序思路很简单，就是取尾部数然后再砍掉。

关键在于保证倒序之后的数没有溢出。

首先想到的是用long int储存生成的数，但是题目中说了不允许储存64位的数。

然后想到，可以再每一次生成数的时候检查是否溢出，这里会用到INT_MAX和INT_MIN，表示−2^31和 2^31 − 1。因为不能等真正生成了最后的数再检查，这样已经溢出了就检查不出来了，所以都是在n进行运算前检查，检查条件也是 `if((num>INT_MAX/10)||((num==INT_MAX/10)&&(x>7)))`  

其实还是可以优化的，就是不必在每次生成的时候都检查，而是在最后输出的时候检查。但是这就会有一个问题，就是可能那个数已经溢出了，检查不出来，所以这里用的判断终止条件是 `while(x/10)`，因为少一位，所以可以保证循环结束后，n绝对没有溢出。



## 代码

```c
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


int reverse(int x){
    int num=0;
    while(x/10){
        num=num*10+x%10;
        x/=10;
    }
    if((num>INT_MAX/10)||((num==INT_MAX/10)&&(x>7)))   return 0;
    else if((num<INT_MIN/10)||((num==INT_MIN/10)&&(x<-8)))  return 0;
    else    return num*10+x;
}

#define TEST(n, e)  printf("%12d  =>  %-12d  %s!\n",  n, reverse(n),  e == reverse(n)?"passed":"failed")

int main(int argc, char**argv)
{
    //basic cases
    TEST(  123,  321);
    TEST( -123, -321);
    TEST( -100,   -1);
    TEST( 1002, 2001);
    //big integer
    TEST( 1463847412,  2147483641);
    TEST(-2147447412, -2147447412);
    TEST( 2147447412,  2147447412);
    //overflow
    TEST( 1000000003, 0);
    TEST( 2147483647, 0);
    TEST(-2147483648, 0);
    //customized cases
    if (argc != 2) {
        fprintf(stderr, "Usage: ./test i\n");
        return 0;
    }
    printf("\n");
    int n = atoi(argv[1]); 
    printf("%12d  =>  %-12d  %s!\n",  n, reverse(n), reverse(reverse(n))==n ? "passed":"failed");
    return 0;
}

```



## 总结

![image-20210421125543916](C:\Users\乔翯\AppData\Roaming\Typora\typora-user-images\image-20210421125543916.png)

main函数里的调用宏定义也有点意思

## 参考资料

[INT_MAX和INT_MIN](https://blog.csdn.net/u012604810/article/details/80290706)

