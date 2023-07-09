#include <stdio.h>

//求表达式 a + aa + aaa + ... + aaaaa（n个a）的值

int main()
{
	int num = 0 ,n = 0 ;
	int i = 0;
	int mup = 1 ,sum = 0 ,temp1 = 0 ,temp2 = 0;
	
	printf("please input num and n:>>");
	scanf("%d%d",&num,&n);
	
	temp1 = temp2 = num;
	while(temp1)
	{
		temp1=temp1/10;
		i++;
	}
	while(i--)
	{
		mup*=10;
	}
	while(n--)
	{
		sum =sum + temp2;
		temp2 = num + mup*temp2;
	}
	printf("sum = %d\n",sum);
	return 0;
}