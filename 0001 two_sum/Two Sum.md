# Two Sum

## 题目

给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 的那 两个 整数，并返回它们的数组下标。

你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。

你可以按任意顺序返回答案。



> 示例 1：
>
> 输入：nums = [2,7,11,15], target = 9
> 输出：[0,1]
> 解释：因为 nums[0] + nums[1] == 9 ，返回 [0, 1] 。
>
> 
>
> 示例 2：
>
> 输入：nums = [3,2,4], target = 6
> 输出：[1,2]
>
> 
>
> 示例 3：
>
> 输入：nums = [3,3], target = 6
> 输出：[0,1]



> 提示：
> 
> 2 <= nums.length <= 103
> -109 <= nums[i] <= 109
> -109 <= target <= 109
> 只会存在一个有效答案



## 题目大意

在数组中找到两个数之和等于给定值的数字，并返回他们在数组中的下标。



## 解题思路

首先想到的方法是暴力破解，即用两层for循环，外层遍历，内层寻找另外一个满足条件的数，这种方法的时间复杂度是O（n<sup> 2</sup>），很明显不是最优解。

这里用到的方法是利用哈希表，一边扫描数组，一边在哈希表中查找是否已经存入的数组元素中有满足条件的。当然，一开始扫描到的前几个（运气好的话只有一个）肯定是会被直接填入哈希表中的，因为当时哈希表内是空的，然后后续在继续扫描数组的过程中，如果发现哈希表已经有满足条件的数了，就把他们两个的下标输出，如果在哈希表中没有找到满足条件的数，就把当前这个数组元素也填入哈希表，然后继续扫描。

当然填入哈希表时，要对这个数在哈希表中的键值对进行设置，将值value设为这个元素的值，将索引key设置为**target减去这个元素的值**，这样的好处是，在检测哈希表中是否含有正在扫描的数组元素的配对值时，只需要判断有没有**key = 此时正在被扫描的数组元素的值**。  

最后的时间复杂度为O（n），主要原因是需要建立哈希表。

## 代码

```c
#include<stdio.h>
#include<stdlib.h>

typedef struct {
    int key;  //关键码为target-nums[i]
    int val;  //值
}HashTable;

int find(HashTable *k, int target, int flag ){
    for (int i = 0; i < flag; ++i) {
        if (k[i].key == target) {
            return i;
        }
    }
    return -1;
}

void insert(HashTable *k,int target, int flag, int value){
    k[flag].val = value;
    k[flag].key = target-value;
}

int* twoSum(int* nums, int numsSize, int target,int* returnSize){
    HashTable k[6];
    int *s = (int*)malloc(sizeof(int) * 2);  // 存放返回值的数组
    for (int i = 0; i < numsSize; ++i) {
        if (find(k,nums[i],i) == -1){
            insert(k,target,i,nums[i]);
        }
        else{
            s[0] = find(k,nums[i],i);
            s[1] = i;
            *returnSize = 2;
            return s;
        }
    }
    *returnSize = 0;
    return NULL;
}

int main()
{
    int nums[]={6,5,7,8,9,3};
    int numsize=6,target=10,returnsize;
    int *a=twoSum(nums,numsize,target,&returnsize);
    if(a!=NULL)
        printf("[%d,%d]",a[0],a[1]);
    else    
        printf("Not found!");
    return 0;
}
```



## 总结

本题主要考点是**数组、哈希表**。

关键在于要熟悉哈希表的用法。



还有一些操作上的问题，就是函数返回的数组不能直接赋值给已知的数组，但可以像main函数里一样，利用指针解决。



![image-20210410233546865](C:\Users\乔翯\AppData\Roaming\Typora\typora-user-images\image-20210410233546865.png)

## 参考资料

[哈希表入门讲解](https://www.bilibili.com/video/BV1cX4y1K7Tk?from=search&seid=18297558420033384859)

[LeetCode题解](https://leetcode-cn.com/problems/two-sum/solution/36xing-dai-ma-ha-xi-biao-zhi-xing-yong-s-cx1a/)