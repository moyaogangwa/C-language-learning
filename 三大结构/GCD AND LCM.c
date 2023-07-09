#include <stdio.h>

//输入两个正整数,输出他们的最大公约数和最小公倍数(欧几里得算法) //最小公倍数 = 两数之积 / 最大公约数

int main()
{
	int num1 = 0 ,num2 = 0;
	int temp = 0 ,gcd = 0 ,lcm = 0;     //gcd:最大公约数  lcm:最小公倍数
	scanf("%d%d",&num1,&num2);
	lcm = num1*num2;
	while(temp=num1%num2)
	{
		num1 = num2;
		num2 = temp;
	}
	gcd = num2;
	lcm /= gcd;
	printf("GCD = %d , LCM = %d\n",gcd,lcm);
	return 0;
}