#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
	int nbooks=3;
	int row = 3;
	int col = 1024; // bytes
	char books[nbooks][row][col];

	strcpy(books[0][0],"C odesey"); //first book
	strcpy(books[0][1],"Vijaya Mukhi");
	strcpy(books[0][2],"Computer");



	printf("\nTitle: %s",books[0][0]);
	printf("\nAuthor: %s",books[0][1]);
	printf("\nGener: %s",books[0][2]);


	strcpy(books[1][0],"C odesey1");
	strcpy(books[1][1],"Vijaya Mukhi1");
	strcpy(books[1][2],"Computer");

	

	printf("\nTitle: %s",books[1][0]); //2nd book
	printf("\nAuthor: %s",books[1][1]);
	printf("\nGener: %s",books[1][2]);


	strcpy(books[2][0],"C odesey2");
	strcpy(books[2][1],"Vijaya Mukhi2");
	strcpy(books[2][2],"Comedy");

	

	printf("\nTitle: %s",books[2][0]); //third book
	printf("\nAuthor: %s",books[2][1]);
	printf("\nGener: %s",books[2][2]);



	printf("\n\n");
	return 0;
	
	
	

}