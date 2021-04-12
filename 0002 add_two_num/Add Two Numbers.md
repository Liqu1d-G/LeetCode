# Add Two Numbers



## 题目

给你两个**非空**的链表，表示两个非负的整数。它们每位数字都是按照**逆序**的方式存储的，并且每个节点只能存储**一位**数字。

请你将两个数相加，并以相同形式返回一个表示和的链表。

你可以假设除了数字 0 之外，这两个数都不会以 0 开头。





![img](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2021/01/02/addtwonumber1.jpg)



>示例 1：
>
>输入：l1 = [2,4,3], l2 = [5,6,4]
>输出：[7,0,8]
>解释：342 + 465 = 807.
>
>
>
>示例 2：
>
>输入：l1 = [0], l2 = [0]
>输出：[0]
>
>
>
>示例 3：
>
>输入：l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
>输出：[8,9,9,9,0,0,0,1]



> **提示：**
>
> - 每个链表中的节点数在范围 `[1, 100]` 内
> - `0 <= Node.val <= 9`
> - 题目数据保证列表表示的数字不含前导零



## 题目大意

链表使用逆序储存，即头节点是个位数，第二个节点是十位数，往后以此类推。

两个链表代表的数相加，得到一个新的数，并用相同形式的链表输出。



## 解题思路

首先想到的方法是，将两个链表代表的数先转化出来，相加之后，再把结果转换回去。但是这个方法会遇到问题，如果链表过长，转化出来的数字int类型无法存储。

所以就想到了不用转化出来再存储，直接再两条链表间进行操作。

链表点对点进行相加操作，然后有一个carry变量储存进位，加到下一个结点中。

当一条链表跑完后，对另一条链表的多余节点作加0处理。

最后，为了避免最后一位存在进位问题，在两条链表均跑完后，需要检查carry是否为0，如果不为0还要再添加一个节点，值为carry。



## 代码

```c
#include<stdio.h>
#include<stdlib.h>

struct ListNode{
    int val;
    struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    struct ListNode *head = NULL, *tail = NULL;
    int carry = 0;

    while(l1 || l2) {
        /* 若l1、l2上还有数没加完，将剩下数字得个位上的数存入n1、n2 
         * 若l1、l2没有数了，直接赋值为0
         */
        int n1 = l1 ? l1->val : 0;
        int n2 = l2 ? l2->val : 0;

        /* 先从个位相加 */
        int sum = n1 + n2 + carry;

        if(!head) { /* 首次计算 */
            head = tail = (struct ListNode *) malloc( sizeof(struct ListNode) );
            tail->val = sum % 10;   /* 存储余数 */
            tail->next = NULL;
        } else {
            tail->next = (struct ListNode *)malloc( sizeof(struct ListNode) );
            tail->next->val = sum % 10;
            tail = tail->next;
            tail->next = NULL;
        } 

        carry = sum / 10;   /* 存储进位数 */
        
        if(l1) {    /* 若还有数，则调整指针 */
            l1 = l1->next;
        } 

        if(l2) {    /* 若还有数，则调整指针 */
            l2 = l2->next;
        }
    }

    if (carry > 0) {    /* 若最高位相加有进位数，则调整链表存储进位数 */
        tail->next = (struct ListNode *) malloc( sizeof(struct ListNode) );
        tail->next->val = carry;
        tail = tail->next;
        tail->next = NULL;
    }

    return head;
}

struct ListNode* CreateListF(int a[],int n)
//头插法建立单链表
{
	struct ListNode *s,*L;
	L=(struct ListNode *)malloc(sizeof(struct ListNode));  //创建头结点
	L->next=NULL;
    L->val=a[0];
	for (int i=1;i<n;i++)
	{	
		s=(struct ListNode *)malloc(sizeof(struct ListNode));//创建新结点s
		s->val=a[i];
		s->next=L;			
		L=s;
	}
    return L;
}

static void show(struct ListNode *ln)
{
    int sum = 0, factor = 1;
    while (ln != NULL) {
        sum += ln->val * factor;
        factor *= 10;
        ln = ln->next;
    }
    printf("%d\n", sum);
}

int main()
{
    struct ListNode *L1,*L2;
    int a[3]={1,2,3};
    int b[3]={4,5,6};
    L1=CreateListF(a,3);
    L2=CreateListF(b,3);
    printf("L1:"); show(L1);
    printf("L2:"); show(L2);
    struct ListNode *L3=addTwoNumbers(L1,L2);
    printf("L3:"); show(L3);
    return 0;
} 
```



## 总结

这题考的是**链表**，没有很卡的地方。

但是发现每次提交貌似得分都不同，今天因为分数原因希望优化二耽误了很久，以后可以只要不是特别低的，不用过于纠结。

![image-20210412005759092](C:\Users\乔翯\AppData\Roaming\Typora\typora-user-images\image-20210412005759092.png)



## 参考资料

