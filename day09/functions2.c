#include <stdio.h>
#include <stdlib.h>

int changeValue(int [], int,int);
void disp(int [], int);

int main()
{
	int a[] = {1,2,3,4,5};
	int CAP = sizeof(a)/sizeof(a[0]);
	int ret=0;

	printf("\nBA of arr (main): %u\n",&a[0]);
	printf("\nCAP=%d\n",CAP);
	disp(a,CAP);
	ret = changeValue(a,CAP,9);
	if(ret == 0)
		printf("\nKey Found\n");
	else
		printf("\nKey Not Found\n");
	disp(a,CAP);
	

	return 0;

}

void disp(int arr[], int n)
{
	int i;
	printf("\nBA of arr (disp): %u\n",&arr[0]);
	for(i=0;i<n;i++)
		printf("%d ",arr[i]);
	printf("\n\n");
}


int changeValue(int arr[],int n, int key)
{
	int i;
	int flag = 0;
	int CAP = 0;
	printf("\nCAP=%d",sizeof(arr)/sizeof(arr[0]));
	for(i=0;i<n;i++)
	{
		if(arr[i] == key)
		{
			arr[i] = 40;
			flag = 1;
		}
	}

	if(flag == 0)
		return 1;
	else
		return 0;
}