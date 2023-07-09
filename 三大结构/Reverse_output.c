#include <stdio.h>

//输入一个正整数,逆序输入这个正整数的每一位

int main()
{
	int num = 0,temp=0;
	scanf("%d",&num);
	while(num)
	{
		temp=num%10;
		num=num/10;
		printf("%d",temp);
	}
	printf("\n");
	return 0;
}