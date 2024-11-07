#include <stdio.h>
//#define CAP 5
// int CAP=5;

extern int CAP;

int main()
{
	int arr[CAP];
	int i;
	for(i=0;i<CAP;i++)
		scanf("%d",&arr[i]);

	printf("\nList is\n");
	for(i=0;i<CAP;i++)
		printf("\n%d",arr[i]);

	printf("\n\n");

	return 0;

}