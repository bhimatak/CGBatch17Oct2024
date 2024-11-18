#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int val;
	struct node *next; //Self referencial pointer (SELF/SRP)
}NODE;

void printList(NODE *);
void printListAdd(NODE *);
NODE* appendNode(NODE *,NODE *);
NODE *addNodeBeg(NODE *, NODE *);
int delNode(NODE *, int);


int main()
{
	NODE *nn=NULL;
	NODE *head=NULL,*temp=NULL;
	int ch;
	do
	{
		nn = (NODE *)malloc(sizeof(NODE));
		printf("\nNew Node Add=%p",nn);
		printf("\nEnter the value of New Node: ");
		scanf("%d",&nn->val);
		nn->next = NULL;

		head = appendNode(head,nn);
		if (head == NULL)
		{
			printf("\nUnable to create Node\n");
			printf("\nMem allocation failed\n");
			return 1;
		}

		printf("\nDo you want to add new node(1/0): ");
		scanf("%d",&ch);
	}while(ch !=0);
	
	printListAdd(head);

	printf("\n\n");

	return 0;

}

void printList(NODE *head)
{

	if(head == NULL)
	{
		//the list is empty
		printf("\nList is Empty\n");
		return;
	}
	printf("\nlist using loops and function\n");
	while(head!= NULL)
	{
		printf("%d->",head->val);
		head = head->next;	
	}
	printf("NULL");
}


void printListAdd(NODE *head)
{

	if(head == NULL)
	{
		//the list is empty
		printf("\nList is Empty\n");
		return;
	}
	printf("\nlist using loops and function\n");
	while(head!= NULL)
	{
		printf("\n%d->%p",head->val,head->next);
		head = head->next;	
	}
	printf("NULL");
}




NODE *appendNode(NODE *head,NODE *nn)
{
	printf("\nIn appendNode\n");
	NODE *temp = head;

	if(head == NULL)
	{
		//the list is empty
		printf("\nList is Empty\n");
		head = nn;
		temp = nn;
	}
	else
	{
		printf("\nList is not empty\n");
		while(head->next!= NULL)
		{
			printf("%d->",head->val);
			head = head->next;	
		}
		
		head->next = nn; //adding node to the end of the list
	}
	head = temp; //head is again pointed to the BA

	return head;
}


NODE *addNodeBeg(NODE *head, NODE *nn)
{
	NODE *temp = head;
	printf("\nIn addNodeBeg\n");
	if(head == NULL)
	{
		//the list is empty
		printf("\nList is Empty\n");
		head = nn;
		temp = nn;
	}
	else
	{
		nn->next = head;
		head = nn;     // making the head point to the nn(BA of new list)
	}
	return head; //return the BA of the list
}


int delNode(NODE *head, int key)
{
	int flag = 1;

	NODE *temp = head;


	while(head!=NULL)
	{
		if(head->val == key)
		{
			//found
			flag = 0;
			break;
		}
		temp = head;
		head = head->next;
	}	

	if(flag == 0)
	{
		
		temp->next = head->next;
	}

	return flag;


}