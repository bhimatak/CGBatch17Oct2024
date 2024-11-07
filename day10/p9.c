#include <stdio.h>

int func();

int main()
{
	register int ret=0;
	ret = func();
	printf("\nRet = %d",ret);

	ret = func();
	printf("\nRet = %d",ret);

	printf("\n\n");

	int i;

	for(i=0;i<100000;i++)
		printf("%d",i);

	return 0;
}

int func()
{
	static int a=10;

	a = a+2;

	return a;
}