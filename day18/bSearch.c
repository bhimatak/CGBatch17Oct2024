#include <stdio.h>
#include <stdlib.h>

#define CAP 10

int bSearch(int [], int);

int main(int argc, char *argv[])
{
	int a[CAP];

	int key;
	int i,count;

	if(argc<12){
		printf("\nEnter 10 elements of the list and 1 key value\n\n");
		return EXIT_FAILURE;
	}
	for(i=1,count=0;i<argc-1;i++,count++)
		a[count] = atoi(argv[i]);

	key = atoi(argv[argc-1]);
	i = bSearch(a,key);
	
	if(i!=EXIT_FAILURE)
		printf("\nKey Found @ %d poisition of the list",i);
	else
		printf("\nKey Not Found");

	printf("\n\n");
	return 0;
}

int bSearch(int arr[], int key)
{
	int low,mid,high;

	low = 0;
	high = CAP;
	
	while(low<=high)
	{
		mid = (low+high)/2;
		if(key == arr[mid])
		{
			return mid;
		}
		else if(key > arr[mid])
		{
			//rigth side of the list
			low = mid + 1;
		}
		else
		{
			//left side of the list
			high = mid - 1;

		}
	}

	return EXIT_FAILURE;

}