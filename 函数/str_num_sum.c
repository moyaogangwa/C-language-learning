#include <stdio.h>

//对字符串中的数字进行求和


int str_numsum(char arr[])
{
	int i = 0 ,num = 0 ,sum = 0;
	while(arr[i])
	{
		if(arr[i]>=48&&arr[i]<=57)
		{
			if(i!=0 && arr[i-1]>=48 && arr[i-1]<=57)
			{
				num = num*10+(arr[i]-48);
			}
			else
			{
				num = arr[i]-48;
			}
			if((arr[i+1]<48||arr[i+1]>57))
			{
				sum+=num;
			}
		}
		i++;
	}
	return sum;
}

int main()
{
	int i = 0 ,sum = 0;
	char str[100] = {0};
	while(i<100)
	{
		str[i]=getchar();
		if(str[i]=='\n')
		{
			str[i]=0;
			break;
		}
		i++;
		if(100==i)
		{
			str[99]=0;
			printf("full! ");
			break;
		}
	}
	sum=str_numsum(str);
	printf("sum=%d\n",sum);
	return 0;
}
