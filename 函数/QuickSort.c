#include <stdio.h>

//µİ¹é¿ìËÙÅÅĞò
void QuickSort(int arr[],int start,int end)
{
	if(start>=end)
		return;
	int left = start,right = end;
	int base = arr[start];
	while(left<right)
	{
		while(left<right && arr[left]<=base)
			left++;
		while(left<right && arr[right]>base)
			right--;
		if(left!=right)
		{
			arr[right]=arr[left]^arr[right];
			arr[left]=arr[left]^arr[right];
			arr[right]=arr[left]^arr[right];
		}
	}
	if(left-1==start && arr[start]>left)
	{
		arr[start] = arr[left];
		arr[left] = base;
	}
	else
	{
		arr[start] = arr[left-1];
		arr[left-1] = base;
	}
	QuickSort(arr,start,left-2);
	QuickSort(arr,left,end);
}

int main()
{
	int arr[10] = {0} ,i = 0;
	int n = sizeof(arr)/sizeof(arr[0]);
	for(i=0;i<10;i++)
	{
		scanf("%d",&arr[i]);
	}
	QuickSort(arr,0,n-1);
	for(i=0;i<10;i++)
	{
		printf("%d ",arr[i]);
	}
	return 0;
}