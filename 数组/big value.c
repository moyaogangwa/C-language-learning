#include <stdio.h>



int main()
{
	char num[100] = {0};
	int i = 0 ,j = 0 ,flag = 0;
	while(num[i-1]!='\n')
	{
		num[i] = getchar();
		i++;
	}
	for(j=0;j<i-1;j++)
	{
		printf("%c",num[j]);
	}
	printf("\n");
	return 0;
}
