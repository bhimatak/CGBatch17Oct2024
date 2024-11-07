/*
thumb rules:

1. 

&* = Nullify each other

2.
op[]  => *op
*op => op[] 


*/


#include <stdio.h>

int main()
{

	int a=10;
	int b[3]= {11,12,13};
	int i;
	int *ptr=NULL;


	//ptr = &b[0]; //=>ptr is pointing to the BA of b=BAof 1st element

	//ptr = &*(b+0)
	//ptr =(b+0)
	ptr = b;

	for(i=0;i<3;i++)
		printf("\n%d",*(ptr+i));
	
	//b[1] = 100;
	*(ptr+1) = 100;

	for(i=0;i<3;i++)
		printf("\n%d",*(ptr+i));
	
	printf("\n\n");

	
	return 0;
}	
