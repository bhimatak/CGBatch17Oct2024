#include <common.h>
#include <emp.h>

int getDetails(EMP *e, char line[])
{
	char *token = NULL;
	token = strtok(line,"|");
	if(token != NULL)
	{
		e->id = atoi(token);
		token = strtok(NULL,"|");
		strcpy(e->Name,token);
		token = strtok(NULL,"|");
		e->g = *token;
		token = strtok(NULL,"|");
		e->phno = atoi(token);
		token = strtok(NULL,"|");
		e->sal = atoi(token);
		return 0;
	}
	return 1;
}

int printDetails(EMP *e)
{
	printf("\nEmployee Details are\n");
	printf("\n===============================\n");
	printf("\nID: %d",e->id);
	printf("\nName: %s",e->Name);
	printf("\nGender: %c",e->g);
	printf("\nPhNo: %d",e->phno);
	printf("\nSalary: %d",e->sal);
	printf("\n===============================\n");
}


EMP *appendNode(EMP *head,EMP *nn)
{
	// printf("\nIn appendNode\n");
	EMP *temp = head;

	if(head == NULL)
	{
		//the list is empty
		printf("\nList is Empty\n");
		head = nn;
		temp = nn;
	}
	else
	{
		// printf("\nList is not empty\n");
		while(head->next!= NULL)
		{
			// printf("%d->",head->val);
			head = head->next;	
		}
		
		head->next = nn; //adding node to the end of the list

	}
	head = temp; //head is again pointed to the BA

	return head;
}


void printList(EMP *head)
{

	if(head == NULL)
	{
		//the list is empty
		printf("\nList is Empty\n");
		return;
	}
	printf("\nList is\n===================================\n");
	while(head!= NULL)
	{
		// printf("%d->",head->val);
		printDetails(head);
		head = head->next;	
	}
	printf("\nEND OF Records\n");
	printf("\n\n===================================\n");
}
