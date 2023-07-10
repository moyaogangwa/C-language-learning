#include <stdio.h>

char *gets(char *s);


int main()
{
	char arr[10]={0};
	char * (*pgets)(char *)=gets;
	int i = 0;
	pgets(arr);
	for(i=0;i<10;i++)
		printf("%c ",arr[i]);
	printf("\n");
	return 0;
}