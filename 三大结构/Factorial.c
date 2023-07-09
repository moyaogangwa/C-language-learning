#include <stdio.h>

//输入一个正整数,输出它的阶乘

int main()
{
	int num =0;
	int i = 0,temp = 1;
	scanf("%d",&num);
	temp = num;
	for(i=1;i<num;i++)
	{
		temp *= i;
	}
	printf("%d\n",temp);
	return 0;
}