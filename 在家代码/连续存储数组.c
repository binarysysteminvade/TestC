#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Arr
{
	int * pBase;	//存储的是数组第一个元素的地址 
	int len;		//数组索能容纳的最大元素的个数 
	int cnt;		//当前数组有效元素的个数 
};

void init_arr(struct Arr * pArr, int length); 
bool append_arr(struct Arr * pArr, int val);
bool insert_arr(struct Arr * pArr, int pos, int val); //插入在pos之前 
bool delete_arr(struct Arr * pArr, int pos, int *pval);
bool inversion_arr(struct Arr * pArr);
bool sort_arr(struct Arr * pArr);
void show_arr(struct Arr * pArr);
bool is_empty(struct Arr * pArr); 
bool is_full(struct Arr * pArr);

int main(void)
{
	struct Arr array;
	init_arr(&array, 6);
	if (append_arr(&array, 1)) 
	{
		printf("追加成功\n"); 
	} 
	append_arr(&array, 2);
	append_arr(&array, 3);
	append_arr(&array, 4);
	append_arr(&array, 5);
	append_arr(&array, 6);
	
	show_arr(&array);
	if (insert_arr(&array, 1, 99)==0) //0为false 
		printf("插入失败\n"); 
	show_arr(&array);
	int a = 0;
	delete_arr(&array, 2, &a);
	show_arr(&array);
	printf("删除的元素是 %d\n", a);
	inversion_arr(&array);
	printf("互换元素: ");
	show_arr(&array);
	sort_arr(&array);
	printf("排序元素: ");
	show_arr(&array);
	//printf("\n%d",*(array.pBase+4));
	return 0;
}

void init_arr(struct Arr * pArr, int length)
{
	pArr->pBase = (int *) malloc(sizeof(int) * length);
	if (pArr->pBase == NULL)
	{
		printf("动态内存分配失败");
		exit(1);		//终止整个程序 
	}
	pArr->len = length;
	pArr->cnt = 0;
	return; 
}

bool is_empty(struct Arr * pArr)
{
	if (pArr->cnt == 0)
		return true;
	else
		return false;
}

void show_arr(struct Arr * pArr)
{	
	if (is_empty(pArr))
	{
		printf("数组为空!\n");
	}
	else
	{
		int i;
		for (i = 0; i<pArr->cnt; i++)
		{
			printf("%d ", pArr->pBase[i]);
		}
		printf("\n");
	}
}

bool is_full(struct Arr * pArr)
{
	
	if (pArr->cnt == pArr->len)
		return true;
	else
		return false;
	
}

bool append_arr(struct Arr * pArr, int val)
{
	if (is_full(pArr))
	{
		return false;
	}
	pArr->pBase[pArr->cnt] = val;//第一次添加是    arr[0]    pArr->cnt = 0
	(pArr->cnt)++;// pArr->cnt = 1
	return true;//成功返回true 
}

bool insert_arr(struct Arr * pArr, int pos, int val)
{
	if (is_full(pArr))
		return false;
	if(pos<1 || pos>pArr->cnt+1)
		return false;
	int i;
	for (i = pArr->cnt-1; i >= pos-1; i--)//i此时为 有效元素-1   arr有一个元素的时候就是1   所以-1 相当于数组的下标 
	{
		pArr->pBase[i+1] = pArr->pBase[i];
	}
	pArr->pBase[pos-1] = val;
	(pArr->cnt)++;
	return true;
} 

bool delete_arr(struct Arr * pArr, int pos, int *pval)
{
	if ( is_empty(pArr))
		return false;
	if (pos<1 || pos>pArr->cnt)
		return false;
	int i;
	*pval = pArr->pBase[pos-1];
	for (i = pos; i <= pArr->cnt-1; i++)
	{
		pArr->pBase[i-1] = pArr->pBase[i];
	}
	pArr->cnt--;
	return true;
}

bool inversion_arr(struct Arr * pArr)
{
	int i = 0;
	int j = pArr->cnt-1;
	int t;
	while(i < j)
	{
		t = pArr->pBase[i];
		pArr->pBase[i] = pArr->pBase[j];
		pArr->pBase[j] = t;
		i++;
		j--;
	}
	return true;
}

bool sort_arr(struct Arr * pArr)
{
	int i, j, t;
	for (i = 0; i < pArr->cnt; i++)	
	{
		for (j = i+1; j < pArr->cnt; j++)
		{
			if (pArr->pBase[i] > pArr->pBase[j])
			{
				t = pArr->pBase[i];
				pArr->pBase[i] = pArr->pBase[j];
				pArr->pBase[j] = t;
			} 
		}
	}
		
}




