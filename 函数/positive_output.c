#include <stdio.h>


//正序输出数字

void input(int num)
{
	if(num>9)
		input(num/10);
	printf("%d ",num%10);
}

int main()
{
	int num = 0;
	scanf("%d",&num);
	input(num);
	printf("\n");
	return 0;
}