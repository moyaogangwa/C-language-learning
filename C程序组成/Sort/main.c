#include <stdio.h>
#include "BubbleSort.h"
#include "SelectionSort.h"
#include "QuickSort.h"

#define N 10
int main()
{
	int arr[N]={0,2,5,3,3,1,4,7,8,9};
	int i = 0;
	//BubbleSort(arr,N);
	//SelectionSort(arr,N);
	QuickSort(arr,0,N-1);
	for(i=0;i<N;i++)
		printf("%d ",arr[i]);
	printf("\n");
}


