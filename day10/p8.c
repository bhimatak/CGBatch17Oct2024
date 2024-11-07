#include <stdio.h>

int add(int,int);
int sub(int, int);

int Calc((*)(),int,int);

int main()
{
	int ret=Calc(add,10,20);
	int ret1=Calc(sub,20,10);

	printf("\nRet=%d\tRet1=%d\n\n",ret,ret1);

	return 0;
}

int add(int v1,int v2)
{
	return v1+v2;
}

int sub(int v1,int v2)
{
	return v1-v2;
}

int Calc((*f)(),int v1,int v2)
{
	return f(v1,v2);
}


