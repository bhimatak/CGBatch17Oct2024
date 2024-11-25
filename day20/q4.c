#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
	char **names=NULL;
	int i,j;
	int row=5,col=50;

	//creating pointer of arrays which points
	// to different names 
	names = (char **)malloc(sizeof(char *)*row);

	//allocate mem for each string and 
	// assign address of each string to each 
	// pointer(names) returned by malloc
	//names[0],names[1]... are representing pointers
	// to each string/name
	for(i=0;i<row;i++)
		names[i] = (char *)malloc(sizeof(char)*col);

	for(i=0;i<row;i++)
		scanf("%s",names[i]);
	printf("\nNames are\n");
	for(i=0;i<row;i++)
		printf("%s\n",names[i]);
	printf("\n\n");

	return 0;
}
