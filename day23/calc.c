#include <stdio.h>
#include <stdlib.h>


int main(int argc, char const *argv[])
{
	char op=argv[1][0];
	int op1 = atoi(argv[2]);
	int op2 = atoi(argv[3]);

	switch(op)
	{
		case '+':
			printf("\nAdd=%d",(op1+op2));
			break;
		case '-':
			printf("\nSub=%d",(op1-op2));
			break;
	}
	printf("\nEnd of Program\n\n");

	/* code */
	return 0;
}