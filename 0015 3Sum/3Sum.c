#include<stdlib.h>
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