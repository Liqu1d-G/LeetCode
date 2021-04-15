# ZigZag Conversation

## 题目

将一个给定字符串 s 根据给定的行数 numRows ，以从上往下、从左到右进行 Z 字形排列。

比如输入字符串为 "PAYPALISHIRING" 行数为 3 时，排列如下：

> P   A   H   N
> A P L S I I G
> Y   I   R

之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："PAHNAPLSIIGYIR"。

请你实现这个将字符串进行指定行数变换的函数：

```
string convert(string s, int numRows);
```



> 示例 1：
>
> 输入：s = "PAYPALISHIRING", numRows = 3
> 输出："PAHNAPLSIIGYIR"
>
> 示例 2：
> 输入：s = "PAYPALISHIRING", numRows = 4
> 输出："PINALSIGYAHRPI"
> 解释：
> P     I    N
> A   L S  I G
> Y A   H R
> P     I
>
> 示例 3：
>
> 输入：s = "A", numRows = 1
> 输出："A"



> **提示：**
>
> - `1 <= s.length <= 1000`
> - `s` 由英文字母（小写和大写）、`','` 和 `'.'` 组成
> - `1 <= numRows <= 1000`

## 题目大意

这个 Z 字型其实是这样的：

![image.png](https://pic.leetcode-cn.com/810b316c74a8eb0d2c97cbfc1bcf7559811f73b1bbed92848ba1bb7b9f1691b1-image.png)

对于前面的 3 行的 示例1 , 它的字符数分布是这样的：

![image.png](https://pic.leetcode-cn.com/01f701396440902b127931f5a1a8a9ecbf70a9dc43ba2b7752a8756b8393e521-image.png)

对于前面的 4 行的 示例2 , 它的字符数分布是这样的：

![image.png](https://pic.leetcode-cn.com/89ba53b0da11c91a66dbb05a75e4b9d83e853bbe3a82c7860cde1a6c1e0c9c8e-image.png)

那么对于 n 行的字符数分布是这样的：

![img](https://pic.leetcode-cn.com/d610b140dd0789204efe699672dc72a83e7b826da0165bbf083d24fc97ecdea7-image.png)



最后就是把形成的z字形按从左到右从上到下的顺序读成新数组。

## 解题思路

想到了两种方法，一个是利用二维数组，一个是直接通过数学方法找到其对应的位置。

二维数组没什么好说的。

直接用数学方法找规律。

1. 当numrow=4时，每一排的数组下标间的差距

   第一排：6-6-6-6-6...

   第二排：4-2-4-2-4...

   第三排：2-4-2-4-2...

   第四排：6-6-6-6-6...

2. 当numrow=5时，每一排的数组下标间的差距

   第一排：8-8-8-8-8...

   第二排：6-2-6-2-6...

   第三排：4-4-4-4-4...

   第四排：2-6-2-6-2...

   第五排：8-8-8-8-8...

3. 当numrow=n时，每一排数组下标间的差距

   第一排：(n-1)×2—(n-1)×2—(n-1)×2—(n-1)×2—(n-1)×2...

   第二排：(n-1)×2-row×2—row×2—(n-1)×2-row×2—row×2...

   ...

   第n排：(n-1)×2—(n-1)×2—(n-1)×2—(n-1)×2—(n-1)×2...



## 代码

用数学方法直接找。

```c
static char* convert(char* s, int numRows)
{
    if (numRows <= 1) return s;

    int len = strlen(s);
    char *new_str = malloc(len + 1);    
    char *p = new_str;
    int row = 0;
    for (row = 0; row < numRows; row++) {
        int interval1 = numRows + (numRows - 2) - row * 2;
        int interval2 = 2 * row;
        int flag = 0;
        int i = row;
        while (i < len) {
            *p++ = s[i];
            int delta = 0;
            do {
                delta = flag == 0 ? interval1 : interval2;
                flag = !flag;
            } while (delta == 0);
            i += delta;
        }
    }

    new_str[len] = '\0';
    return new_str;
}
```

用二维数组存储

```c
char * convert(char * s, int numRows){
    int len = strlen(s);
    if(len<=2||numRows<=1) return s;    //特殊情况

    int numLines;   //算列数
    if((len-numRows)%(numRows-1)==0){
        numLines = (len-numRows)/(numRows-1)+1;
    }else{
        numLines = (len-numRows)/(numRows-1)+2;
    }

    int chMap[numRows][numLines];
    memset(chMap,0,sizeof(chMap));
    int i = 1;  //第一个字符直接赋值从第二个开始
    int row = 0,line = 0;
    while(line<numLines){
        if(line%2==0){  //偶数列从上到下
            row = 1;
            while(s[i] && row<numRows){ 
                chMap[row][line] =(int)s[i];
                i++;
                row++;
            }
        }else{      //奇数列从下到上
            row = numRows-2;
            while(row>=0 && s[i]){
                chMap[row][line] =(int)s[i];
                i++;
                row--;
            }
        }
        line++;
    }

    char *a = (char *)malloc(len+1);
    a[0] = s[0];
    i = 1;
    for(row = 0;row<numRows;row++){     //二维数组写入一维数组
        for(line = 0;line<numLines;line++){
            if(chMap[row][line]){
                a[i] = (char)chMap[row][line];
                i++;
            }  
        }
    }
    a[len] = '\0';
    return a;
}
```



## 总结

数学方法的分数：

![image-20210416015413302](C:\Users\乔翯\AppData\Roaming\Typora\typora-user-images\image-20210416015413302.png)

二维数组的分数：

![image-20210416015557235](C:\Users\乔翯\AppData\Roaming\Typora\typora-user-images\image-20210416015557235.png)

这题不知道在考啥，可能是数学找规律能力吧。

## 参考资料

[二维数组源码](https://leetcode-cn.com/problems/zigzag-conversion/solution/hen-ben-hen-jian-dan-de-si-lu-er-wei-shu-zu-by-you/)

[题目大意图片](https://leetcode-cn.com/problems/zigzag-conversion/solution/6-z-zi-xing-bian-huan-c-c-by-bian-bian-xiong/)