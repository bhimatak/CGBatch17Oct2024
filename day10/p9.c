#include <stdio.h>

int func();

int main()
{
	int ret=0;
	ret = func();
	printf("\nRet = %d",ret);

	ret = func();
	printf("\nRet = %d",ret);

	printf("\n\n");

	return 0;
}

int func()
{
	static int a=10;

	a = a+2;

	return a;
}