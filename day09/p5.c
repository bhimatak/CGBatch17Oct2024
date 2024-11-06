#include <stdio.h>

#define CAP 10

int main()
{
	int i=0,t, mid;
	int a[CAP]={1,2,3,4,5,6,7,8,9,10};

	for(i=0;i<CAP;i++)
		printf(" %d ",a[i]);


	printf("\n%d\n",a[a[2]]);
	printf("\n%d\n",2[a]);
	

	//logic rev array
	printf("\nAfter reverse of array\n\n");
	for(i=0, mid=CAP/2;i<mid;i++)
	{
		t = a[i];
		a[i] = a[(CAP-1)-i];
		a[(CAP-1)-i] = t;
	}	

	for(i=0;i<CAP;i++)
		printf(" %d ",a[i]);



}