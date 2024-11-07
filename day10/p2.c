/*
Pointer Demo
*/

#include <stdio.h>

int main()
{
	int a=10;
	float b=20.2;
	

	void *ptr = NULL;

	int *ptr1 = NULL;

	printf("\nAddress of a=%u and its value=%d",&a,a);
	printf("\nAddress of b=%u and its value=%f",&b,b);
	printf("\nAddress of ptr=%u and its value=%u",&ptr,ptr);

	printf("\nSize of a=%d",sizeof(a));
	printf("\nSize of b=%d",sizeof(b));
	printf("\nSize of ptr=%d",sizeof(ptr));
	
	ptr = &a;
	ptr1 = &a;

	printf("\nptr value = %u",ptr);

	printf("\nValue pointed by ptr = %d",*(int *)ptr);

	printf("\nValue pointed by ptr1 = %d",*ptr1);

	printf("\n\n");

	return 0;
	

}