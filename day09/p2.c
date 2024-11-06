/*
Array Examples

*/

#include <stdio.h>

int main()
{
	int intArr[5];
	int i;


	printf("\nBA of array = %u",&intArr[0]);
	printf("\nAddress of intArr[0]=%u and Value=%d",&intArr[0],intArr[0]);
	printf("\nAddress of intArr[1]=%u and Value=%d",&intArr[1],intArr[1]);
	printf("\nAddress of intArr[2]=%u and Value=%d",&intArr[2],intArr[2]);
	printf("\nAddress of intArr[3]=%u and Value=%d",&intArr[3],intArr[3]);
	printf("\nAddress of intArr[4]=%u and Value=%d",&intArr[4],intArr[4]);
	
	/*
	intArr[0]=10;
	intArr[1]=11;
	intArr[2]=12;
	intArr[3]=13;
	intArr[4]=14;
	*/
	for(i=0;i<5;i++)
		scanf("%d",&intArr[i]);
	/*
	printf("\nBA of array = %u",&intArr[0]);
	printf("\nAddress of intArr[0]=%u and Value=%d",&intArr[0],intArr[0]);
	printf("\nAddress of intArr[1]=%u and Value=%d",&intArr[1],intArr[1]);
	printf("\nAddress of intArr[2]=%u and Value=%d",&intArr[2],intArr[2]);
	printf("\nAddress of intArr[3]=%u and Value=%d",&intArr[3],intArr[3]);
	printf("\nAddress of intArr[4]=%u and Value=%d",&intArr[4],intArr[4]);
	*/	

	for(i=0;i<5;i++)
		printf("\nAddress of intArr[%d]=%u and Value=%d",i,&intArr[i],intArr[i]);
	
	printf("\n\n");		


	return 0;


}