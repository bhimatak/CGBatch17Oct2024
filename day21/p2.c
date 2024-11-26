#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define BUFF 1024

int main()
{
	int nTC=0;
	char line[BUFF];
	int isCount=0;
	int aCount=0,i;
	int lenLine=0;
	int count =0;
	int sum=0;
	fgets(line,BUFF,stdin);
	line[strlen(line)-1]='\0';
	nTC = atoi(line);

	while(nTC)
	{
		// printf("\nntc=%d",nTC);
		count=0;
		isCount=0;
		aCount=0;
		// scanf(" ");
		fgets(line,BUFF,stdin);
		lenLine = strlen(line);
		// printf("\n%c=%d",line[lenLine-1],line[lenLine-1]);
		line[lenLine-1]='\0';
		lenLine = strlen(line);
		
		//to find is present
		// BA = &line[0];
		for(i=0;i<lenLine;i++)
		{
			if((line[i]=='i')&&(line[i+1]=='s'))
			{
				isCount = isCount+i;
			}
		}

		for(i=0;i<lenLine;i++)
		{
			if((line[i]=='a'))
			{
				aCount=aCount+i;
			}
		}

		if(aCount==0)
			count--;
		if(isCount==0)
			count--;

		sum = aCount+isCount+count;
		// printf("\nisCount=%d\taCount=%d",isCount,aCount);
		printf("\nsum=%d\n",sum);
		nTC--;
	}

}