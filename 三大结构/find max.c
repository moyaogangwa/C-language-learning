#include <stdio.h>

//输入两个数,判断其中的最大值
int main()
{
	int num1 = 0,num2 = 0;
	scanf("%d %d",&num1,&num2);
	if(num1>=num2)
	{
		printf("max=%d\n",num1);
	}
	else
	{
		printf("max=%d\n",num2);
	}
	return 0;
}