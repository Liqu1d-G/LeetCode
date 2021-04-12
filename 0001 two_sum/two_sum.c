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

//[6,5,7,8,9,3]
//10

