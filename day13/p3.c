#include <stdio.h>

enum RegClrCodes
{
	Black=101,
	Brown,
	Red,
	Orange,
	Yellow=303,
	Green,
	Blue,
	Voilate,
	Gray,
	White
}RCC;

int dispMenu()
{
	int cc;
	printf("\nPress,");
	printf("\n%d. Black",Black);
	printf("\n%d. Brown", Brown);
	printf("\n%d. Red",Red);
	printf("\n%d. Orange",Orange);
	printf("\n%d. Yellow",Yellow);
	printf("\n%d. Green",Green);
	printf("\n%d. Blue",Blue);
	printf("\n%d. Voilate",Voilate);
	printf("\n%d. Gray",Gray);
	printf("\n%d. White",White);
	printf("\nChoice: ");
	scanf("%d",&cc);
	return cc;
}

int main()
{
	RCC = dispMenu();
	switch(RCC)
	{
		case Black:
				printf("\nBlack");
				break;
		case Brown:
				printf("\nBrown");
				break;
		case Red:
				printf("\nRed");
				break;
		case Orange:
				printf("\nOrange");
				break;
		case Yellow:
				printf("\nYellow");
				break;
		default:
				printf("\nEnter correct choice");
	}

	printf("\nPrgram Ended\n\n");

	return 0;

}