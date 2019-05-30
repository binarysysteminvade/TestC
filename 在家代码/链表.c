#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 

typedef struct Node
{
	int data; //������
	struct Node * pNext; 
}NODE, *PNODE;

PNODE create_list(void);
void traverse_list(PNODE pHead);
bool is_empty(PNODE pHead);
int len_list(PNODE pHead);
void sort_list(PNODE pHead);
bool insert_list(PNODE pHead, int pos, int val);
bool delete_list(PNODE pHead, int pos, int *val);

int main(void)
{
	PNODE pHead = NULL;
	pHead = create_list();
	printf("��ӡ����: "); 
	traverse_list(pHead);
	if (is_empty(pHead))
	{
		printf("����Ϊ��!!!\n"); 
	}
	else
	{
		printf("����Ϊ��!!!\n");
	}
	printf("��������: ");
	int len = len_list(pHead);
	printf("%d\n", len);
	printf("�����: ");
	sort_list(pHead);
	traverse_list(pHead);
	printf("����: ");
	insert_list(pHead, 4, 66); 
	traverse_list(pHead);
	int a = 0;
	
	delete_list(pHead, 4, &a);
	printf("ɾ��Ԫ��: %d\n", a);
	traverse_list(pHead);
	return 0;
} 

PNODE create_list(void)
{
	int len, i;
	int val; 	//��ʱ����û�����ڵ��ֵ 
	
	PNODE pHead = (PNODE) malloc(sizeof(NODE));//ͷ�ڵ� 
	if ( pHead == NULL)
	{
		printf("�ڴ����ʧ��");
		exit(-1); 
	}
	PNODE pTail = pHead;
	pTail->pNext = NULL;
	printf("��������Ҫ��������ĸ���: ");
	scanf("%d", &len);
	for (i = 0; i < len; i++)
	{
		printf("�������%d�ڵ��ֵ: ", i + 1);
		scanf("%d", &val); 
		
		PNODE pNew = (PNODE) malloc(sizeof(NODE));
		if ( pNew == NULL)
		{
			printf("����ʧ��, ������ֹ\n");
			exit(-1); 
		}
		pNew->data = val;
		pTail->pNext = pNew; 
		pNew->pNext = NULL;
		pTail = pNew;
	} 
	
	return pHead;
}

void traverse_list(PNODE pHead)
{
	PNODE p = pHead->pNext;
	
	while (p != NULL)
	{
		printf("%d ", p->data);
		p = p->pNext;
	}
	printf("\n");
}

bool is_empty(PNODE pHead)
{
	if (pHead->pNext == NULL)
		return true;
	else
		return false;
	
}

int len_list(PNODE pHead)
{
	PNODE p = pHead->pNext;
	int len = 0;
	while (p != NULL)
	{
		len++;
		p = p->pNext;
	}
	return len;
} 

void sort_list(PNODE pHead)
{
	int i, j, t;
	int len = len_list(pHead);
	PNODE p, q;
	for (i = 0,p = pHead->pNext; i < len-1; i++, p=p->pNext)
	{
		for (j = i+1,q=p->pNext; j < len; j++,q=q->pNext)
		{
			if (p->data > q->data)
			{
				t = p->data;
				p->data = q->data;
				q->data = t;
			}
		}
	}
	return;
}

bool insert_list(PNODE pHead, int pos, int val)
{
	int i = 0;
	PNODE p = pHead;
	while (p != NULL && i < pos-1)
	{
		p = p->pNext;
		i++;
	}
	if (i > pos-1 || p == NULL)
		return false;
		
	PNODE pNew = (PNODE)malloc(sizeof(NODE));
	if(NULL == pNew)
	{
		printf("��̬�ڴ����ʧ��!!!\n");
		exit(-1); 
	}
	
	pNew->data = val;
	PNODE q = p->pNext;
	p->pNext = pNew;
	pNew->pNext = q;
	
	return true;
}

bool delete_list(PNODE pHead, int pos, int *val)
{
	int i = 0;
	PNODE p = pHead;
	while (p->pNext != NULL && i < pos-1)
	{
		p = p->pNext;
		i++;
	}
	if (i > pos-1 || p == NULL)
		return false;
	PNODE q = p->pNext;
	*val = q->data;
	
	p->pNext = p->pNext->pNext;
	free(q);
	q = NULL;
	
	return true;
}















