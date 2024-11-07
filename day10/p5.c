#include <stdio.h>
#include <stdlib.h>

int main()
{

	int a=10;
	int i;
	int *ptr = NULL;
	int *temp = NULL;
	/*
	ptr = &a;

	printf("\nValue stored at ptr = %d",*ptr);
	*/

	ptr = (int *)malloc(3*sizeof(int));

	if(ptr == NULL)
	{
		perror("malloc: ");
		exit(0);
	}
	temp = ptr;


	printf("\nAddress of ptr pointing to = %u",ptr);
	/*
	*(ptr+0) = 101;
	*(ptr+1) = 102;
	*(ptr+2) = 103;
	*/

	for(i=0;i<3;i++)
		printf("\n%d element addres = %u",i,&ptr[i]);

	*ptr = 101;
	printf("\n%d is stored at %u",*ptr,ptr);
	ptr++;
	
	*ptr = 102;
	printf("\n%d is stored at %u",*ptr,ptr);
	ptr++;
	*ptr = 103;
	printf("\n%d is stored at %u",*ptr,ptr);


	/*
	printf("\nValue stored at ptr = %d",*ptr);
	printf("\nValue of a = %d",a);
*/
    //ptr--;
    //ptr--;
    
	printf("\nArray Elements are\n");
	for(i=0, ptr = temp;i<3;i++,ptr++){
		printf("\n%d\n",*ptr);
		
	}
	
	printf("\n\n");

	return 0;

}