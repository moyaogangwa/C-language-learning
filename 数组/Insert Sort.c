#include <stdio.h>

//插入排序

#define N 5
int main()
{
	int arr[N] = {0}, arr2[N] = {0}, flag = 1;
	int i = 0, j = 0, k = 0;
	for(i=0;i<N;i++)
	{
		scanf("%d",&arr[i]);
	}
	
	arr2[0]=arr[0];     //从arr中取出第一个数
	for(i=1;i<N;i++)
	{
		for(j=0;j<i;j++)
		{
			if(arr[i]<arr[j])
			{
				for(k=i;k>=j;k--)       //将插入位置及之后的元素后移
				{
					arr2[k+1]=arr[k];
				}
				arr2[j]=arr[i];
				flag = 0;         
				break;
			}
		}
		if(1==flag)                    //如果没有比新取出的数大的数，则将该数放在已有值的最右边
		{
			arr2[i]=arr[i];
		}
	}
	for(i=0;i<N;i++)
	{
		printf("%d ",arr2[i]);
	}
	printf("\n");
	return 0;
}