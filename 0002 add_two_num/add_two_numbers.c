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
    int a[2]={3,7};
    int b[2]={9,2};
    L1=CreateListF(a,2);
    L2=CreateListF(b,2);
    printf("L1:"); show(L1);
    printf("L2:"); show(L2);
    struct ListNode *L3=addTwoNumbers(L1,L2);
    printf("L3:"); show(L3);
    return 0;
} 