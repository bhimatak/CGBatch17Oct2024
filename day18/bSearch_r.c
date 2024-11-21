#include <stdio.h>
#include <stdlib.h>

#define FAILURE -1

int bSearch_r(int *, int,int,int);

int main(int argc, char *argv[])
{
	int *a=NULL;

	int key;
	int i,count;


	if(argc<3){
		printf("\nEnter atleast 1 element and 1 key value\n\n");
		return EXIT_FAILURE;
	}

	a = (int *)malloc(sizeof(int)*(argc-2));
	for(i=1,count=0;i<argc-1;i++,count++)
		a[count] = atoi(argv[i]);

	key = atoi(argv[argc-1]);

	i = bSearch_r(a,0,count,key);
	
	if(i!=FAILURE)
		printf("\nKey Found @ %d poisition of the list",i);
	else
		printf("\nKey Not Found");

	printf("\n\n");
	return 0;
}

int bSearch_r(int *arr, int low, int high, int key)
{
	int mid = (low+high)/2;


	if (low>high)
		return FAILURE;
	
	if(key == arr[mid])
	{
			return mid;
	}
	else if(key > arr[mid])
	{
			//rigth side of the list
			low = mid + 1;
			bSearch_r(arr,low,high,key);
	}
	else
	{
			//left side of the list
			high = mid - 1;
			bSearch_r(arr,low,high,key);

	}
	

}