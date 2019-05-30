#include <stdio.h>

int main(void)
{
	
	int a = 10;
	int * pa = &a;
	int *pb = pa;
	printf("%d %d\n", pa, pb);
	
	return 0;
}
