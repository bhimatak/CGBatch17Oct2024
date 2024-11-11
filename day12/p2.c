#include <stdio.h>
#include <string.h>

char covChar(int i)
{
	return (i+'0');
}


void reverseNum(char temp[],int n)
{
	int i;
	char t;
	for(i=0;i<n/2;i++)
	{
		t = temp[i];
		temp[i] = temp[(n-1)-i];
		temp[(n-1)-i] = t;
	}
}


int digits(char temp[],int num)
{
	int count=0;
	int tNum = num;
	while(num)
	{
		tNum = num % 10;
		temp[count] = covChar(tNum);
		count++;
		num = num/10;

	}
	temp[count] = '\0';
	reverseNum(temp, strlen(temp));
	return 0;
}

int main()
{
	int c1,c2,c3;
	char res[40]={'\0',};
	char temp[10]={'\0',};
	char temp1[5];
	c1=2;
	c2=1;
	c3=0;

	
	while(c2<11){
    	c3=c1*c2;
    	
    	digits(temp,c1);
    	strcat(strcpy(res,temp)," x ");
    	// strcat(res," x ");
    	digits(temp,c2);
    	strcat(strcat(res,temp)," = ");
    	//strcat(res," = ");
    	digits(temp,c3);
    	strcat(res,temp);
    	
    	puts(res);
    	c2++;
    }

    return 0;

}