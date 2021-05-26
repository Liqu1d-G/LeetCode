# [12. Integer to Roman](https://leetcode-cn.com/problems/integer-to-roman/)

## 题目思路

逐为比对，将几种特殊情况单独考虑

## 代码

```C
char * intToRoman(int num){
    int sym[13] = {0};
    int div[13]        = {1000,  900, 500,  400, 100,   90,  50,   40,  10,    9,   5,    4,   1};
    char symCat[13][3] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    int i;
    char *s = (char *)malloc(20 * sizeof(char));
    memset(s, 0, 20 * sizeof(char));

    for(i=0;i<13;i++){
        sym[i]=num/div[i];
        num=num%div[i];
    }
    for(i=0;i<13;i++){
        while(sym[i]-->0)
            strcat(s,symCat[i]);
    }

    return s;
}
```

## 总结

> 执行用时：4 ms, 在所有 C 提交中击败了92.41%的用户
>
> 内存消耗：5.7 MB, 在所有 C 提交中击败了72.86%的用户

注意数表的使用
