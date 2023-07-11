#include <stdio.h>
#include "Sort.h"
#define N 10



void Sort(int *a,int n,void *(*func)(int*,int))
{
	func(a,n);
}


int main()
{
	int arr[N] = {0};
	int i = 0;
	for(i=0;i<N;i++)
	{
		scanf("%d",&arr[i]);
	}
	Sort(arr,N,Bubble_Sort);
	for(i=0;i<N;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
	return 0;
}






