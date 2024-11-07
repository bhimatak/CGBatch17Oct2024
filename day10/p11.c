/*

=========================================
=================Welcome=================
=========================================


*/

#include <stdio.h>
#include <string.h>

int printChar(int, int);

int main()
{
	char msg[]="Welcome";
	int i;
	printChar('\n',1);
	printChar('=',50);
	printChar('\n',1);
	printChar('=',21);
	for(i=0;i<strlen(msg);i++)
		printChar(msg[i],1);
	
	printChar('=',22);
	printChar('\n',1);
	printChar('=',50);
	printChar('\n',1);
	
	printf("\n\n");

	return 0;
}

int printChar(int ch, int n)
{
	int i;
	for(i=0;i<n;i++)
		putchar(ch);
}