#include <stdio.h>

int add(int,int);
int sub(int, int);

int Calc(int (*)(),int,int);



int main()
{
	int ret;//=Calc(add,10,20);
	int ret1=0;//=Calc(sub,20,10);

	int (*func)();

	/*
	func = add;
	ret = (*func)(10,20);

	printf("\nRet=%d\tRet1=%d\n\n",ret,ret1);
	func = sub;
	ret1 = (*func)(100,20);
	printf("\nRet=%d\tRet1=%d\n\n",ret,ret1);
	*/

	ret = Calc(sub,30,5);
	ret1 = Calc(add,110,20);
	
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


int Calc(int (*f)(),int v1,int v2)
{
	return (*f)(v1,v2);
}


