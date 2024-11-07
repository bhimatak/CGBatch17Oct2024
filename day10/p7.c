#include <stdio.h>

int *allocMem();

int main()
{
	int a=10;
	int *ptr=NULL;

	// ptr = &a;
	ptr = allocMem();
	printf("\n%d\n",*ptr);

	return 0;
}

int *allocMem()
{
	static int a=10;
	return &a;
}