#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int data; //数据域
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
	int val; 	//临时存放用户输入节点的值 
	
	PNODE pHead = (PNODE) malloc(sizof(NODE));//头节点 
	if ( pHead == NULL)
	{
		printf("内存分配失败");
		exit(-1); 
	}
	PNODE pTail = pHead;
	pTail->pNext = NULL;
	printf("请输入您要生成链表的个数: ");
	scanf("%d", &len);
	for (i = 0; i < len; i++)
	{
		printf("请输入第%d节点的值", i + 1);
		scanf("%d", &val); 
		
		PNODE pNew = (PNODE) malloc(sizof(NODE));
		if ( pNew == NULL)
		{
			printf("分配失败, 程序终止\n");
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

