#include <stdio.h>

int main()
{

	int a=10;
	int b[3]= {11,12,13};

	int *ptr=NULL;

	printf("\nAddress of ptr=%u and stored address in ptr=%u",&ptr,ptr);

	ptr = &a;

	printf("\nAddress of ptr=%u and stored address in ptr=%u",&ptr,ptr);
	printf("\nValue stored at %u = %d",ptr,*ptr);
	
	printf("\nBase Address of b=%u\n",&b[0]);
	ptr = &b[0];
	printf("\nValue stored at %u = %d",ptr,*ptr);

	//array notation
	printf("\nb[0]=%d",ptr[0]);
	printf("\nb[1]=%d",ptr[1]);
	printf("\nb[2]=%d",ptr[2]);

	printf("\nIn pointer notation\n");
	//pointer notation
	printf("\nb[0]=%d",*(ptr+0));
	printf("\nb[1]=%d",*(ptr+1));
	printf("\nb[2]=%d",*(ptr+2));

	printf("\n\n");

	

}	
