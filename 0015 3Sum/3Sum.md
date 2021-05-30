# [3Sum](https://leetcode-cn.com/problems/3sum/)

## 题目思路

将数组利用快排升序排序，之后遍历，遍历的时候，固定遍历的值，然后对于其后面的部分使用双指针

在最开始要检查数组是否为空，或元素个数是否小于三个

在遍历时，如果遍历到的数大于零，则后面就都不存在了，结束遍历。如果遍历的数和前一个重复，则跳过

在用完双指针之后，为了避免重复，还要将两个指针移动到不再重复的位置

## 代码

```C
 int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    *returnSize=0;
    if(nums==NULL||numsSize<3)
        return NULL;
    qsort(nums,numsSize,sizeof(int),cmp);
    int **ret = (int**)malloc(numsSize*numsSize*sizeof(int*));
    *returnColumnSizes=(int*)malloc(numsSize*numsSize*sizeof(int));
    for(int i=0;i<numsSize;i++){
        if(nums[i]>0)
            break;
        if(i>0&&nums[i]==nums[i-1])
            continue;
        int left=i+1,right=numsSize-1;
        while(left<right){
            int sum=nums[i]+nums[left]+nums[right];
            if(sum==0){
                ret[*returnSize]=(int*)malloc(sizeof(int)*3);
                ret[*returnSize][0]=nums[i];
                ret[*returnSize][1]=nums[left];
                ret[*returnSize][2]=nums[right];
                (*returnColumnSizes)[*returnSize]=3;
                (*returnSize)++;
                while(left<right&&nums[left]==nums[++left]);
                while(left<right&&nums[right]==nums[--right]);
            }
            else if(sum<0)
                left++;
            else 
                right--;
        }
    }
    return ret;
}
```

## 总结

> 执行用时：152 ms, 在所有 C 提交中击败了96.19%的用户
>
> 内存消耗：31.4 MB, 在所有 C 提交中击败了56.73%的用户

快排是C的库函数，可以直接调用，不过要先声明比较函数是什么。[C 库函数 - qsort()](https://www.runoob.com/cprogramming/c-function-qsort.html)

注意对于二维数组的指针形式的相关操作

` int** returnColumnSizes`表示返回数组中每一行的列数

