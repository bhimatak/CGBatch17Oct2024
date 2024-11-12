#include <common.h>
#include <emp.h>

int main()
{
	FILE *fp;
	EMP *e=NULL;
	EMP *temp = NULL;
	char line[BUFF];
	int i;

	

	fp = fopen("./data/db.txt","r");

	if(fp == NULL)
	{
		perror("fopen: ");
		return 1;
	}
	e = (EMP *)malloc(5*sizeof(EMP));
	temp = e;

	memset(line,'\0',BUFF);

	while(fgets(line,BUFF,fp)!=NULL)
	{
		line[strlen(line)-1] = '\0';
		getDetails(e,line);
		e++;
	}

	e = temp;

	for(i=0;i<5;i++,e++)
		printDetails(e);

	printf("\n\n");
	return 0;
}