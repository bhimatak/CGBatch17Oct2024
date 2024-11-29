#include "myheader.h"
/*
int main()
{
	key_t key= ftok("/home/bhima/BhimaFldr/day24",10010);
	printf("\n%X",key);

	printf("\n\n");
	return 0;
}

*/

int main()
{
	int msgid;
	msgid = msgget((key_t)12,IPC_CREAT|0644);
	printf("\nMSG queue created with %d id\n",msgid);

	printf("\n\n");
	return 0;
}