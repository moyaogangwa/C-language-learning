#include <stdio.h>


//最大连续子数列之和(下标连续)

#define N 5
int main()
{
	int arr[N] = {0} ,n = 0;             //n存储输入数组中负数的个数
	int i = 0 ,j = 0 ,left = -1 ,right = -1;
	int sum = 0 ,max = 0 ,temp = 0; 
	
	//输入数组,并计算输入数组中负数的个数
	printf("please input:>>");
	for(i=0;i<N;i++)
	{
		scanf("%d",&arr[i]);
		if(arr[i]<0)
			n++;
	}
	
	//如果全为负数
	if(N==n)
	{
		max=arr[0];
		for(i=0;i<N;i++)
		{
			arr[i]>max?arr[i]:max;
		}
		printf("max son list:%d ",max);
	}
	
	//如果不全为负数
	else
	{
		for(i=0;i<N;i++)
		{
			if(arr[i]<0 && 0==sum)      //如果第一个值为负数则跳过
				continue;
			else if(arr[i]>0 && 0==sum)  
				left=i;
			else if(arr[i]<0 && 0!=sum)  //如果计算sum途中遇到arr[i]<0
			{
				for(j=i+1;arr[j]>=0 && j<N;j++)
				{
					temp += arr[j];       //计算所遇到的负数到下一个负数之间所有数的和
				}
				if(sum+temp+arr[i]<temp)  //将继续加到下一个负数的值与temp进行比较
				{
					max = sum = temp;
					left = i+1;
					i=j-1;
					continue;
				}
			}
			
			sum+=arr[i];
			if(max<=sum)
			{
				max = sum;
				right=i;
			}
		}
		
		printf("max son list:");
		for(i=left;i<=right;i++)
		{
			printf("%d ",arr[i]);
		}
	}
	printf("max value:%d\n",max);
	return 0;
}







