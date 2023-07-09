#include <stdio.h>

//判断一个数是否是质数

int main()
{
	int num = 0;
	int i = 0,flag=1;
	scanf("%d",&num);
	if(num>2 && 0==num%2 ||1==num)
	{
		printf("%d is not prime\n",num);
	}
	else
	{
		for(i = 2;i<=num/2;i++)    // num/2换成sqrt(num)会更好点,但需声明 math.h 头文件
		{
			if(0==num%i)
			{
				flag = 0;
				printf("%d is not prime\n",num);
				break;
			}
		}
		if(1==flag)
		{
			printf("%d is  prime\n",num);
		}
	}
	return 0;
}