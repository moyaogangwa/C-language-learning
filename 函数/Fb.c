#include <stdio.h>

//斐波那契数列第n项

int Fb(int a)
{
	int num1 = 1 ,num2 = 1 ,num3 = 0;
	int i = 0;
	if(1==a || 2==a)
		return 1;
	else
	{
		for(i=2;i<a;i++)
		{
			num3 = num1+num2;
			num1 = num2;
			num2 = num3;
		}
	}
	return num3;
}


int main()
{
	int n = 0 ,num = 0;
	scanf("%d",&n);
	num = Fb(n);
	printf("Fb[%d]=%d\n",n,num);
	return 0;
}