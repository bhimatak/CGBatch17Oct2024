#include <stdio.h>


int main()
{
	int a=10;

	printf("\n%d",sizeof(char));
	printf("\n%d",sizeof(int));
	printf("\n%d",sizeof(float));
	printf("\n%d",sizeof(double));
	printf("\n%d",sizeof(a++));
	printf("\nnew value of a=%d\n",a);

	return 0;
}

