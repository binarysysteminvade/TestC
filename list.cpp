#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int data; //������
	struct Node * pNext; 
}NODE, *PNODE;

PNODE create_list(void);
void traverse_list(PNODE pHead);
int main(void)
{
	PNODE pHead = NULL;
	pHead = create_list();
	traverse_list(pHead);
	
	return 0;
} 

PNODE create_list(void)
{
	int len, i;
	int val; 	//��ʱ����û�����ڵ��ֵ 
	
	PNODE pHead = (PNODE) malloc(sizof(NODE));//ͷ�ڵ� 
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
		printf("�������%d�ڵ��ֵ", i + 1);
		scanf("%d", &val); 
		
		PNODE pNew = (PNODE) malloc(sizof(NODE));
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

