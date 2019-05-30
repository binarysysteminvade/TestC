#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 

typedef struct Node
{
	int data; //数据域
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
	printf("打印链表: "); 
	traverse_list(pHead);
	if (is_empty(pHead))
	{
		printf("链表为空!!!\n"); 
	}
	else
	{
		printf("链表不为空!!!\n");
	}
	printf("链表长度是: ");
	int len = len_list(pHead);
	printf("%d\n", len);
	printf("排序后: ");
	sort_list(pHead);
	traverse_list(pHead);
	printf("插入: ");
	insert_list(pHead, 4, 66); 
	traverse_list(pHead);
	int a = 0;
	
	delete_list(pHead, 4, &a);
	printf("删除元素: %d\n", a);
	traverse_list(pHead);
	return 0;
} 

PNODE create_list(void)
{
	int len, i;
	int val; 	//临时存放用户输入节点的值 
	
	PNODE pHead = (PNODE) malloc(sizeof(NODE));//头节点 
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
		printf("请输入第%d节点的值: ", i + 1);
		scanf("%d", &val); 
		
		PNODE pNew = (PNODE) malloc(sizeof(NODE));
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
		printf("动态内存分配失败!!!\n");
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















