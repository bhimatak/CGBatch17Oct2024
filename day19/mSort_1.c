/*
Demo on Merge Sort
*/
#include <stdio.h>
#include<stdlib.h>
#include <unistd.h>


void display(int [], int);
void mergeDivide(int [], int, int);
// void mergeDivideRH(int [], int, int);
void mergeConquor(int [], int,int,int);

int main()
{

	int a[] = {6,5,12,10,9,1};
	int Cap = sizeof(a)/sizeof(a[0]);

	printf("\nBefore Sorting\n");
	display(a,Cap);
	
	mergeDivide(a,0,Cap -1);
	printf("\nAfter Selection Sort\n\n");
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


void mergeDivide(int a[], int is, int ie)
{
	int mid=0;
	// static int Count=0;
	// printf("\nis=%d\tie=%d\tCount=%d",is,ie,Count);
	getchar();
	if(is < ie)
	{
		// Count++;
		mid = is+(ie-is)/2;
		mergeDivide(a,is,mid);
		mergeDivide(a,mid+1,ie);
		//here we are merging the sorted array
		mergeConquor(a,is,mid,ie);
	}

}

void mergeConquor(int a[],int is, int mid, int ie)
{
	//create sub array a[p-q] and a[q+1-r] for array of a[p-r]
	int leftArr[100],rightArr[100],i,j,k;
	int n1,n2; // no of elements present in each sub array
	n1 = mid - is + 1;
	n2 = ie - mid;

	for(i=0;i<n1;i++)
		leftArr[i] = a[is+i];
	for(i=0;i<n2;i++)
		rightArr[i] = a[mid+1+i];

	printf("\nContents of a1\n");
	display(leftArr,n1);
	printf("\nContents of a2\n");
	display(rightArr,n2);
	printf("\n\n");


	i=0;
	j=0;
	k = is;

	//untill we reach to the end of a1 and a2, pick larger/greatest among arrays

	while(i<n1 && j<n2)
	{
		if(leftArr[i] <= rightArr[j]){
			a[k] = leftArr[i];
			i++;
		}
		else
		{
			a[k] = rightArr[j];
			j++;
		}
		k++;
	}

	while(i<n1)
	{
		a[k] = leftArr[i];
		i++;
		k++;
	}

	while(j<n2)
	{
		a[k]=rightArr[j];
		j++;
		k++;
	}




}