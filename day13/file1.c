/*

FILE => DS 
fd => file pointer to FILE DS

fopen("NameofFIle","Mode") => opening a file
Mode=> r,w,a,r+,w+,a+

fclose(fd) => close the opened file

read/write

fprintf,fscanf => formated writing and reading resp.


fputs,fgets => unformated i/o operation

fwrite/fread => reading/writing binary objects



*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>



int main()
{
	FILE *fd=NULL;
	char ch='a';
	char Name[] = "Bhimashankar";
	char rName[100];
	int i;
	
	fd = fopen("Test2.txt","r");

	if(fd == NULL)
	{
		perror("fopen: ");
		printf("\n%p\n\n",fd);
		exit(1);
	}
	printf("\nOpened the file successfully %p\n\n",fd);
/*
	while((ch=fgetc(fd))!=EOF)
	{
		putchar(ch);
	}

*/
	
	/*
	fputc(ch,fd);
	fputc(ch,fd);
	fputc(ch,fd);
	fputc(ch,fd);
	fputc(ch,fd);
	*/

	/*for(i=0;i<strlen(Name);i++)
		fputc(Name[i],fd);
	*/
	i=0;
	while((ch=fgetc(fd))!=EOF)
	{
		rName[i] = ch;
		i++;
	}
	rName[i] = '\0';

	printf("\nrName = %s\n",rName);

	printf("\n\n");



	fclose(fd);
	return 0;
}