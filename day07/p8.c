#include <stdio.h>
#include <string.h>

int main()
{

	char str1[20];;
	char ch;

	char buff[1024] = {'\0',};
	fgets(str1, 4,stdin);
	puts("\nSlno | ID | Name |\n");
	strcat(buff,"001 | ");
	strcat(buff,str1);
	strcat(buff," | ");
	strcat(buff,"bhima");
	strcat(buff,"shankar");
	strcat(buff," |");
	puts(buff);

}