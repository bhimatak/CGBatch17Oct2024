/*
Demo on Quick Sort
*/
#include <stdio.h>
#include <stdlib.h>


void display(int [], int);
void qSort(int [], int, int);
int partition(int [], int , int );

int main()
{
	int a[] = {6,5,12,10,9,1};
	int Cap = sizeof(a)/sizeof(a[0]);

	printf("\nBefore Sorting\n");
	display(a,Cap);
	printf("\nAfter Quick Sort\n\n");
	qSort(a,0,Cap-1);
	display(a,Cap);

	printf("\n\n");
	return 0;
}

void display(int a[], int Cap)
{
	int i;
	for(i=0;i<Cap;i++)
		printf(" %d ",a[i]);
	printf("\n");
}

void qSort(int arr[], int is, int ie)
{
	int pi=0;
	if(is< ie)
	{
		pi = partition(arr, is,ie);

		qSort(arr,is,pi-1);
		qSort(arr,pi+1,ie);

	}
}

int partition(int arr[], int is, int ie)
{
	int pivot=0, ptrg=0, i;
	int t;
	//right most element is choosen for pivot
	pivot = arr[ie];

	ptrg = (is -1);

	for(i=is;i<ie;i++)
	{
		if(arr[i]<= pivot)
		{
			ptrg++;

			t = arr[ptrg];
			arr[ptrg] = arr[i];
			arr[i] = t;
		}
	}

	t = arr[ptrg+1];
	arr[ptrg+1] = arr[ie];
	arr[ie] = t;


	return (ptrg+1);

}