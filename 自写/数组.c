#include <stdio.h> 
#include <stdlib.h>


typedef struct Arr
{
	int * pBase;
	int len;
	int cnt;
}Arr, * PArr;

void init_array(PArr parr, int len);

int main(void)
{
	Arr array;
	 
	
	return 0;
}

void init_array(PArr parr, int len)
{
	parr->pBase = (int *)malloc(sizeof(int)*len);
	parr->len = len;
} 
