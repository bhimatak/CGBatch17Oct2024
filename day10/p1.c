/*
Demo on recurrsive function
*/

#include<stdio.h>

int f(int);

int main()
{

	int res = f(5);

	printf("\nRes=%d\n\n",res);

	return 0;
}

int f(int v)
{
	int ret;
	printf("\nV Value : %d\n",v);
	if (v == 1)
		return 1;
	
	ret = v * f(--v);
	printf("\nV Value in Func: %d\n",v);
	return ret;
}
