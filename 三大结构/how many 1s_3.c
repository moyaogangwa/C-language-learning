#include <stdio.h>

//多少个1（方法2）

int main()
{
	int num = 0 ,count = 0;
	scanf("%d",&num);
	if(num<0)
	{
		num=0-num;
		count++;
	}
	while(num)
	{
		num=num&(num-1);
		count++;
	}
	printf("%d\n",count);
	return 0;
}