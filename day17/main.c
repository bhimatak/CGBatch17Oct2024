#include <stdio.h>
#include <stack_v01.h>



//driver code for stack operations
int main()
{
	int v,i;
	/*
	v = pop();
	printf("\n%d element is deleted from the container/stack",v);
	*/

	push(10);
	push(11);
	push(12);
	push(13);
	push(14);
	push(15);
	
	
	dispStack();

	for(i=0;i<MAX;i++)
	{
		v = pop();
		printf("\n%d element is deleted from the container/stack",v);
		dispStack();
	}

	printf("\n\n");

	return 0;

}