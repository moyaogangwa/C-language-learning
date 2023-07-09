#include <stdio.h>

//99乘法表

int main()
{
	int i = 0 ,j = 0;
	for(i=1;i<=9;i++)
	{
		for(j=1;j<=i;j++)
		{
			printf(" %d*%d =%2d ",j,i,i*j);
		}
		j=1;
		printf("\n");
	}
	return 0;
}