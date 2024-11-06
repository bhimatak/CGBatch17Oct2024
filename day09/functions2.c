#include <stdio.h>
#include <stdlib.h>

int changeValue(int *, int);
void disp(int [], int);

int main()
{
	int a[] = {1,2,3,4,5};
	int CAP = sizeof(a)/sizeof(a[0]);

	printf("\nBA of arr (main): %u\n",&a[0]);
	printf("\nCAP=%d\n",CAP);
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