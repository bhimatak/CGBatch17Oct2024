/*
Command line arguments

main(int argc,char *argv[])

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
	int i;

	if(argc<2)
	{
		fprintf(stderr,"\ndest/source is missing");
		fprintf(stderr,"\n./app src dest\n\n");
		return 1;
	}

	printf("\nNo of args = %d",argc);

	for(i=0;i<argc;i++)
		printf("\nargv[%d] = %s",i,argv[i]);


	printf("\n\n");
	return 0;
}