#include <stdio.h>

//����������,�ж����е����ֵ
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