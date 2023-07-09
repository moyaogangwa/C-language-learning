#include <stdio.h>

//一个数的连续整数和

int main()
{
	int num = 0 ,sum = 0;
	int i = 0 ,j = 0 , k = 0 ,flag = 0;
	printf("please input:>>");
	scanf("%d",&num);
	for(i=1;i<num;i++)
	{
		sum = 0;
		flag = 0;
		for(j=i;j<num;j++)
		{
			if(sum<num)
			{
				sum += j;
				continue;
			}
			else if(sum==num)
			{
				flag = 1;
				k = j;
				break;
			}
			else
			{
				break;
			}
		}
		if(1 == flag)
		{
			printf("%d=%d",num,i);
			for(j=i+1;j<k;j++)
			{
				printf("+%d",j);
			}
			printf("\n");
		}
	}
	return 0;
}