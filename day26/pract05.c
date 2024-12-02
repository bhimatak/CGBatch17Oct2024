#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Employee
{
	int eid;
	char ename[20];
	struct Employee *next;
	struct Employee *prev;
}EMP;

void *createNode();
void dispList(EMP *);
void dispListF(EMP *);
void dispListB(EMP *);
void sortEmp(EMP *);
void freeList(EMP *);


int main()
{
	EMP *head=NULL, *temp=NULL, *nn = NULL;
	int noEmps = 0;
	register int i=0;
	printf("\nEnter the no Employee needed: ");
	scanf("%d",&noEmps);
	for(i=0;i<noEmps;i++)
	{
		nn = (EMP *)createNode();
		printf("\nEnter Employee Details: \n");
		printf("\nName: ");
		scanf("%s",nn->ename);
		printf("\nID: ");
		scanf("%d",&nn->eid);
		nn->next = NULL; // any node with null termination for the tail end
		nn->prev = NULL;
		if(head == NULL)
		{
			// if the list is empty
			head = nn;
			temp = nn;
		}
		else
		{
			// if the list is not empty
			nn->prev = temp; // for doubly linked list
			temp->next = nn;
			temp = temp->next;

		}
	}

	temp = head;

	dispList(temp);
	temp = head;
	//dispListB(temp);
	sortEmp(temp);
	temp = head;
	printf("\nAfter Sorting\n");
	dispList(temp);

	// free(head);
	freeList(head);
	printf("\n\n");
	return 0;

}

void *createNode()
{
	return (malloc(sizeof(EMP)));
}

void dispList(EMP *head)
{
	printf("\nEmployee Lists\n");
	while(head != NULL)
	{
		printf("\nName: %s",head->ename);
		printf("\nID: %d",head->eid);
		head = head->next;
	}
}

void freeList(EMP *head)
{
	EMP *temp = head;
	printf("\nFree Employee Lists\n");
	while(head != NULL)
	{
		temp = head->next;
		free(head);
		head = temp;
		
		
	}
}

void dispListF(EMP *head)
{
	printf("\nEmployee Lists in forward order\n");
	while(head != NULL)
	{
		printf("\nName: %s",head->ename);
		printf("\nID: %d",head->eid);
		head = head->next;
	}
}

void dispListB(EMP *head)
{
	while(head != NULL){ //Move until the last/tail end
		if(head->next == NULL)
			break;
		head = head->next;
	} 

	printf("\nEmployee Lists in reverse order\n");
	while(head != NULL)
	{
		printf("\nName: %s",head->ename);
		printf("\nID: %d",head->eid);
		head = head->prev;
	}
}

void sortEmp(EMP *head)
{
	EMP *temp=NULL, *tempNext = NULL;
	temp = (EMP *)malloc(sizeof(EMP));
	
	if(head->next != NULL)
		tempNext = head->next;
	while(head != NULL)
	{
		if(head->next != NULL)
			tempNext = head->next;
		if(strcmp(head->ename, tempNext->ename)>0)
		{
			strcpy(temp->ename, head->ename);
			temp->eid = head->eid;

			strcpy(head->ename, tempNext->ename);
			head->eid = tempNext->eid;
			
			strcpy(tempNext->ename, temp->ename);
			tempNext->eid = temp->eid;
			
		}
		head = head->next;
	}

	free(temp);

}