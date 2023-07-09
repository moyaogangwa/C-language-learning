#include <stdio.h>


////最大连续子数列之和(值连续)
int main()
{
	int arr[10] = {0};
	int i = 0 ,j = 0 ,flag_i = 0 ,flag_j = 0;
	int sum = 0 ,max = 0 ,n = 0;
	for(i=0;i<10;i++)
	{
		scanf("%d",&arr[i]);
	}
	
	for(i=0;i<10;i++)
	{
		sum = arr[i];
		for(j=i+1;j<10;j++)
		{
			if((arr[j]-arr[j-1]==1) || (arr[j-1]-arr[j]==1))  //判断值是否连续
			{
				sum+=arr[j];
			}
			else
			{
				break;
			}
		}
		if(j-i>1)
			{
				if(0==n)
				{
					max = sum;
					flag_i = i;
					flag_j = j;
				}
				else
				{
					if(max<sum)
					{
						max = sum;
						flag_i = i;
						flag_j = j;
					}
				}
				n++;
			}
	}
	
	for(i=flag_i;i<flag_j;i++)
	{
		printf("%d ",arr[i]);
	}
	printf(" max_sum:%d\n",max);
	return 0;
}

