/*
Command line arguments

main(int argc,char *argv[])

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFF 1024
#define OR ||


int main(int argc, char *argv[])
{
	FILE *fp;
	// int i;
	char fileName[BUFF];
	char lines[BUFF];
	// char *tokens=NULL;

	if((argc<2)OR(argc>2))
	{
		fprintf(stderr,"\nconfigFile is missing");
		fprintf(stderr,"\n./app configFile.csv\n\n");
		return 1;
	}

	strcpy(fileName,argv[1]);

	fp = fopen(fileName,"r");
	if(fp == NULL)
	{
		perror("fopen: ");
		return 1;
	}

	memset(lines,'\0',BUFF);
	while(fgets(lines,BUFF,fp)!=NULL)
	{
		lines[strlen(lines)-1] = '\0';
		puts(lines);
		memset(lines,'\0',BUFF);
	}

	fclose(fp);

	printf("\n\n");
	return 0;
}