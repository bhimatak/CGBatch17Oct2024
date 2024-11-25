#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char *reverseStr(char *s)
{
	int i,l=strlen(s);
	char t;
	for(i=0;i<l/2;i++)
	{
		t = s[i];
		s[i] = s[l-i-1];
		s[l-i-1] = t;
	}

	return s;
}


char *revStrPos(char *s, int a, int b)
{
	int i;

	char t;
	a--;
	b--;
	
    while (a < b) {
        char temp = s[a];
        s[a] = s[b];
        s[b] = temp;
        a++;
        b--;
    }

	return s;

}

char *changeStr(char *s, int a, int b, int val)
{
	char c = (char)val;
	int i;
	printf("\nEntered in changeStr\n");
	a--;
	b--;

	for(i=a;i<=b;i++)
	{
		s[i] = c;

	}

	printf("\nchangeStr=%s\n",s);
	return s;
}

char *swapChars(char *s, int a, int b)
{
	char t;
	a--;
	b--;
	t = s[a];
	s[a] = s[b];
	s[b] = t;

	return s;
}


char *qSolve(char *s, int r, int c, int **quires)
{
	int si,ei,val,i;
	int qt;
	char *result = (char *)malloc(strlen(s)+1);

	strcpy(result,s);

	for(i=0;i<r;i++)
	{
		qt = quires[i][0];
		si = quires[i][1];
		ei = quires[i][2];
		val = quires[i][3];


		switch(qt)
		{
			case 1:
					reverseStr(result);
					break;
			case 2:
					revStrPos(result,si,ei);
					break;
			case 3:
					swapChars(result,si,ei);
					break;
			case 4:

					changeStr(result,si,ei,val);
					break;
			default:
					break;
		}

	}

	return result;
}


int main()
{
	char s[] = "abcde";
	reverseStr(s);
	printf("\n%s\n",s);
	changeStr(s,1,2,98);
	printf("\n%s\n",s);
}