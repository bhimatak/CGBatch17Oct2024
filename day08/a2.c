#include <stdio.h>

int powOf(int x,int y)
{
	int i,res=x;
	if (y==0)
		return 1;
	for(i=0;i<y-1;i++)
		res = res*x;
	return res;
}

int main()
{
	int x=2,y=0;
	int res=0, n;
	scanf("%d",&n);
	while(1){
		if(res >= n)
			break;
		res = powOf(x,y);
		printf("%d ",res);
		y++;
	}
}