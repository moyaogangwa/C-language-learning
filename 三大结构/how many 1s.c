#include <stdio.h>


//按补码
int main()
{
	unsigned int num = 0, temp = 0;
	int i = 0 ,n = 0;
	printf("please input:>>");
	scanf("%d",&num);
	temp = num;
	for(i=0;i<32;i++)
	{
		if((temp&(1<<i))!=0)
		{
			n++;
		}
	}
	printf("total : %d\n",n);
	return 0;
}