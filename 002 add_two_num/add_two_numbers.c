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
        /* ��l1��l2�ϻ�����û���꣬��ʣ�����ֵø�λ�ϵ�������n1��n2 
         * ��l1��l2û�����ˣ�ֱ�Ӹ�ֵΪ0
         */
        int n1 = l1 ? l1->val : 0;
        int n2 = l2 ? l2->val : 0;

        /* �ȴӸ�λ��� */
        int sum = n1 + n2 + carry;

        if(!head) { /* �״μ��� */
            head = tail = (struct ListNode *) malloc( sizeof(struct ListNode) );
            tail->val = sum % 10;   /* �洢���� */
            tail->next = NULL;
        } else {
            tail->next = (struct ListNode *)malloc( sizeof(struct ListNode) );
            tail->next->val = sum % 10;
            tail = tail->next;
            tail->next = NULL;
        } 

        carry = sum / 10;   /* �洢��λ�� */
        
        if(l1) {    /* ���������������ָ�� */
            l1 = l1->next;
        } 

        if(l2) {    /* ���������������ָ�� */
            l2 = l2->next;
        }
    }

    if (carry > 0) {    /* �����λ����н�λ�������������洢��λ�� */
        tail->next = (struct ListNode *) malloc( sizeof(struct ListNode) );
        tail->next->val = carry;
        tail = tail->next;
        tail->next = NULL;
    }

    return head;
}

struct ListNode* CreateListF(int a[],int n)
//ͷ�巨����������
{
	struct ListNode *s,*L;
	L=(struct ListNode *)malloc(sizeof(struct ListNode));  //����ͷ���
	L->next=NULL;
    L->val=a[0];
	for (int i=1;i<n;i++)
	{	
		s=(struct ListNode *)malloc(sizeof(struct ListNode));//�����½��s
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