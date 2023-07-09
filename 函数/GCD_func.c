#include <stdio.h>

//最大公约数

int IF_GCD(int num1,int num2)
{
	int temp = 0;
	while(temp = num1%num2)
	{
		num1 = num2;
		num2=temp;
	}
	return num2;
}


int main()
{
	int num1 = 0 ,num2 = 0 ,gcd = 0;
	scanf("%d%d",&num1,&num2);
	gcd = IF_GCD(num1,num2);
	printf("gcd=%d\n",gcd);
	return 0;
}

