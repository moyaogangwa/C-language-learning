#include <stdio.h>

// //Ã°ÅÝÅÅÐò-º¯Êý

#define N 10

void BubbleSort(int arr[],int n)
{
	int i = 0 ,j = 0;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-1-i;j++)
		{
			if(arr[j+1]<arr[j])
			{
				arr[j]=arr[j+1]^arr[j];
				arr[j+1]=arr[j+1]^arr[j];
				arr[j]=arr[j+1]^arr[j];
			}
		}
	}
}

int main()
{
	int arr[N] = {0};
	int i = 0;
	for(i = 0;i<N;i++)
		scanf("%d",&arr[i]);
	BubbleSort(arr,N);
	for(i = 0;i<N;i++)
		printf("%d ",arr[i]);
	printf("\n");
	return 0;
}