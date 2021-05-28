# [Longest Common Prefix](https://leetcode-cn.com/problems/longest-common-prefix/)

## 题目思路

垂直扫描

## 代码

```C
char * longestCommonPrefix(char ** strs, int strsSize){
    if(strsSize==0) return "";
    for(int i=0;i<strlen(strs[0]);i++){
        for(int j=1;j<strsSize;j++)
            if(strs[0][i]!=strs[j][i]){
                strs[0][i]='\0';
                break;
            }
    }
    return strs[0];
}
```

## 总结

> 执行用时：0 ms, 在所有 C 提交中击败了100.00%的用户
>
> 内存消耗：5.6 MB, 在所有 C 提交中击败了94.59%的用户

注意二维数组各个参数的意义和表述形式