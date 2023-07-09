#include <stdio.h>

#define N 10

int main()
{
	int arr[N] = {0};
	int i = 0 ,j = 0;
	int max = 0 ,index = 0 ,temp=0;
	for(i=0;i<N;i++)
	{
		scanf("%d",&arr[i]);
	}
	for(i=0;i<N-1;i++)
	{
		max=arr[0];
		index = 0;
		for(j=0;j<=N-1-i;j++)
		{
			if(max<arr[j])
			{
				max=arr[j];
				index=j; 
			}
		}
		temp=arr[index];
		arr[index]=arr[N-1-i];
		arr[N-1-i]=temp;
	}
	for(i=0;i<N;i++)
		printf("%d ",arr[i]);
	printf("\n");
	return 0;
}


