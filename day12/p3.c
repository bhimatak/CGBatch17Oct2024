#include <stdio.h>

int main()
{
	char Lines[] = "101|Amit|M|8888|10000";
	char Names[10][20];
	int row=0,col=0;
	char *ptr=NULL;
	int flag = 0;

	ptr = Lines;

	while(*ptr!='\0')
	{
		putchar(*ptr);
		ptr++;
	}

	ptr = Lines;
	row=0;
	col=0;
	while(*ptr != '\0')
	{
		if(*ptr == '|')
			break;
		Names[row][col]=*ptr;
		ptr++;
		col++;
	}
	Names[row][col] = '\0';

	printf("\n\n");
	putchar(*ptr);
	printf("\n\n");
	puts(Names[row]);

	while(1){
		ptr++;
		row++;
		col=0;
		if(*ptr == '\0')
		{
			flag = 1;
			break;
		}
		while(*ptr != '\0')
		{
			if(*ptr == '|')
				break;
			Names[row][col]=*ptr;
			ptr++;
			col++;
		}
		Names[row][col] = '\0';

		// printf("\n\n");
		// putchar(*ptr);
		printf("\n\n");
		puts(Names[row]);
	}
	/*
	ptr++;
	row++;
	col=0;
	while(*ptr != '\0')
	{
		if(*ptr == '|')
			break;
		Names[row][col]=*ptr;
		ptr++;
		col++;
	}
	Names[row][col] = '\0';

	printf("\n\n");
	putchar(*ptr);
	printf("\n\n");
	puts(Names[row]);
	*/

	printf("\n\n");
	return 0;
}