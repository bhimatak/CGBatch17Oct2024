#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int val;
	struct node *next; //Self referencial pointer (SELF/SRP)
	struct node *prev;
}NODE;


NODE *createNode(NODE *);
int dispMainMenu();
void printListFD(NODE *);
void printListBD(NODE *);

NODE* appendNode(NODE *,NODE *);
NODE *addNodeBeg(NODE *, NODE *);
int delNode(NODE *, int);


int main()
{
	NODE *nn=NULL;
	NODE *head=NULL,*temp=NULL;
	int flag=0;
	int key=0;

	while(1)
	{
		switch(dispMainMenu())
		{
			case 1:
					nn = createNode(nn);
					head = addNodeBeg(head,nn);
					break;
			case 2:
					nn = createNode(nn);
					head = appendNode(head,nn);
					break;
			case 3:
					printf("\nEnter the key of the node: ");
					scanf("%d",&key);
					delNode(head,key);
					break;
			case 4:
					printListFD(head);
					break;
			case 5:
					printListBD(head);
					break;
			case 6:
					flag = 1;
					break;
			default:
					printf("\nEnter the correct Choice");
					break;
		}
		if(flag == 1)
			break;
	}
	
	printf("\n\n");

	return 0;

}

NODE *createNode(NODE *nn)
{
	nn = (NODE *)malloc(sizeof(NODE));
	printf("\nEnter the value of New Node: ");
	scanf("%d",&nn->val);
	nn->next = NULL;
	nn->prev = NULL;
	return nn;
}


int dispMainMenu()
{
	int ch;
	printf("\nLinked List Menu\n");
	printf("\nPress,");
	printf("\n1. Add Node in Begning");
	printf("\n2. Add Node to the End");
	printf("\n3. Delete a Node");
	printf("\n4. Print List FD");
	printf("\n5. Print List BD");
	printf("\n6. Exit");
	printf("\nChoice: ");
	scanf("%d",&ch);

	return ch;
}


void printListFD(NODE *head)
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
		printf("%d->",head->val);
		head = head->next;	
	}
	printf("NULL");
	printf("\n\n===================================\n");
}


void printListBD(NODE *head)
{

	if(head == NULL)
	{
		//the list is empty
		printf("\nList is Empty\n");
		return;
	}
	printf("\nList is\n===================================\n");
	//travese until last node
	while(head->next!= NULL)
	{
		head = head->next;	
	}
	//print from the last to first node
	do
	{
		printf("%d->",head->val);
		head = head->prev;
		
	}while(head!=NULL);

	printf("NULL");
	printf("\n\n===================================\n");
}



NODE *appendNode(NODE *head,NODE *nn)
{
	// printf("\nIn appendNode\n");
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
		// printf("\nList is not empty\n");
		while(head->next!= NULL)
		{
			// printf("%d->",head->val);
			head = head->next;	
		}
		
		head->next = nn; //adding node to the end of the list
		nn->prev = head;
	}
	head = temp; //head is again pointed to the BA

	return head;
}


NODE *addNodeBeg(NODE *head, NODE *nn)
{
	NODE *temp = head;
	// printf("\nIn addNodeBeg\n");
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
		head->prev = nn;
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