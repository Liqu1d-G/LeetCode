#### [13. Roman to Integer](https://leetcode-cn.com/problems/roman-to-integer/)

## 题目思路

逐位比对，按照要求操作

## 代码

```C
int romanToInt(char * s){
    int sum=0,i=0,lenth=strlen(s);
    for(i;i<lenth;i++){
        switch(s[i]){
            case 'M':sum+=1000;break;
            case 'D':sum+=500;break;
            case 'L':sum+=50;break;
            case 'V':sum+=5;break;
            case 'C':
                switch(s[i+1]){
                    case 'D':sum-=100;break;
                    case 'M':sum-=100;break;
                    default:sum+=100;
                }break;
            case 'X':
                switch(s[i+1]){
                    case 'L':sum-=10;break;
                    case 'C':sum-=10;break;
                    default:sum+=10;
                }break;
            case 'I':
                switch(s[i+1]){
                    case 'V':sum-=1;break;
                    case 'X':sum-=1;break;
                    default:sum+=1;
                }
        }
    }
    return sum;
}
```

## 总结

> 执行用时：4 ms, 在所有 C 提交中击败了95.37%的用户
>
> 内存消耗：5.7 MB, 在所有 C 提交中击败了48.16%的用户

