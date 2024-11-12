#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
	FILE *fp=NULL;

	int noLine;
	system("wc -l ../data/db.txt > recs.txt");

	fp = fopen("../data/recs.txt", "r");

	fscanf(fp,"%d",&noLine);

	printf("\nLines = %d\n\n",noLine);

	fclose(fp);

	return 0;


}