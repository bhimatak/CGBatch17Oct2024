#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int val;
	struct node *ptr; //Self referencial pointer (SELF/SRP)
}NODE;


int main()
{
	//creating nodes & allocated mem
	NODE h1,h2,h3,h4;

	//ptr1 is used to navigate/travese betwn nodes
	NODE *ptr1=NULL;

	//initialze values to each node

	h1.val = 10;
	h1.ptr = NULL;

	h2.val = 20;
	h2.ptr = NULL;

	h3.val = 30;
	h3.ptr = NULL;


	printf("\nAddress of h1=%p",&h1);
	printf("\nAddress of h2=%p",&h2);
	printf("\nAddress of h3=%p",&h3);
	printf("\nAddress of ptr1=%p",&ptr1);


	printf("\nh1.value=%d and ptr=%p",h1.val,h1.ptr);
	printf("\nh2.value=%d and ptr=%p",h2.val,h2.ptr);
	printf("\nh3.value=%d and ptr=%p",h3.val,h3.ptr);

	printf("\ncontents of ptr1/ptr1 is pointing to: %p",ptr1);
	

	//Making relationship (travese)/creating LList

	h1.ptr = &h2;
	h2.ptr = &h3;

	//travese

	ptr1 = &h1; //ptr1 pointing to BA of list (first rec)

	printf("\n%d",h1.val);
	printf("\n%d",ptr1->val);

	//ptr1 = &h2;
	ptr1 = h1.ptr; //=>ptr1 is pointing to h2
	printf("\n%d",ptr1->val);

	//ptr1 = &h3;
	ptr1 = h2.ptr; // from earlier line 57
	printf("\n%d",ptr1->val);

	//create new node and init with values
	h4.val=40;
	h4.ptr = NULL;

	//inserting new node h4 betwn h1 and h2
	h1.ptr = &h4;
	h4.ptr = &h2;

	//again ptr1 is pointing to BA of list
	ptr1 = &h1;
	printf("\nNew list is\n");
	printf("\n%d->",ptr1->val);

	ptr1 = h1.ptr;
	printf("%d->",ptr1->val);
	
	ptr1 = h4.ptr;
	printf("%d->",ptr1->val);
	
	ptr1 = h2.ptr;
	printf("%d->",ptr1->val);
	
	ptr1 = h3.ptr;
	if(ptr1 == NULL)
		printf("NULL");
	else
		printf("\n%d;",ptr1->val);
	




	printf("\n\n");

	return 0;

}