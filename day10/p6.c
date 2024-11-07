#include <stdio.h>
#include <stdlib.h>

void dispList(int *, int);


int main()
{
	int *head=NULL, *temp=NULL;
	int i;

	head = (int *)malloc(5*sizeof(int));

	if(head == NULL)
	{
		perror("malloc: ");
		exit(1);
	}

	temp = head;

	for(i=0;i<5;i++,head++)
		scanf("%d",head);
	
	head = temp;

	dispList(head,5);
	
	printf("\n\n");
	return 0;
}


void dispList(int *ptr,int s)
{
	int i;
	printf("\nElements in the list is\n");
	for(i=0;i<s;i++,ptr++)
		printf("%d ",*ptr);
	printf("\n\n");
}