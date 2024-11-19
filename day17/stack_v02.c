/*

stack using DMA

*/
#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int top;
int bottom=-1;

void push(int *, int);
void pop(int *);

void dispStack(int *);


int main()
{
	int *arr = NULL, *temp=NULL;
	arr = (int *)malloc(MAX*sizeof(int));
	temp = NULL;
	printf("\nMain = %u",arr);
	top = bottom;
	
	push(arr,10);
	push(arr,20);
	push(arr,30);
	push(arr,40);
	push(arr,50);
	push(arr,60);
	
	
	dispStack(arr);
	pop(arr);
	pop(arr);
	pop(arr);
	pop(arr);
	pop(arr);
	pop(arr);
	printf("\n\n");

	free(temp);

	return 0;
}

void dispStack(int *arr)
{
	int iter;
	if(top==bottom)
	{
		printf("\nStack is empty\n");
		return;
	}
	printf("\nStack is\n");
	for(iter=top;iter>=0;iter--)
		printf("\n%d",arr[iter]);
	printf("\n\n");

}

void push(int *arr, int val)
{
	if(top == MAX-1)
	{
		printf("\nStack is full\n");
		return;
	}
	arr[++top] = val;

}

void pop(int *arr)
{
	if(top==bottom)
	{
		printf("\nStack is empty\n");
		return;
	}
	printf("\n%d is popped out\n",arr[top]);
	top--;
}

