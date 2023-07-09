#include <stdio.h>

//求一个整数的n次方

int main()
{
	int num = 0,n = 0;
	int value = 1;
	int i = 0;
	printf("please input num and n:>>");
	scanf("%d%d",&num,&n);
	for(i=1;i<=n;i++)
	{
		value*=num;
	}
	printf("num^n = %d\n",value);
	return 0;
}