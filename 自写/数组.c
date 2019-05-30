#include <stdio.h> 
#include <stdlib.h>
#include <stdbool.h>


typedef struct Arr
{
	int * pBase;
	int len;
	int cnt;
}Arr, * PArr;

bool init_array(PArr parr, int len);

int main(void)
{
	Arr array;
	if (init_array(&array, 5))
	{
		printf("�����ڴ�ɹ�!\n");
	}
	
	return 0;
}

bool init_array(PArr parr, int len)
{
	parr->pBase = (int *)malloc(sizeof(int)*len);
	if (parr->pBase == NULL)
	{
		printf("�����ڴ�ʧ��!!!\n");
		exit(-1);
	}
	parr->len = len;
	parr->cnt = 0;
	return true;
} 
