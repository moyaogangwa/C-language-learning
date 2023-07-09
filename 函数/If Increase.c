#include <stdio.h>


//判断一个数组是否递增

int Increase(int arr[],int n)
{
	if(1==n)
		return 1;
	else
		return arr[n-1]>arr[n-2] && Increase(arr,n-1);
}

int main()
{
	int arr[10] = {0} ,i = 0 ,flag = -1;
	for(i;i<10;i++)
	{
		scanf("%d",&arr[i]);
	}
	flag = Increase(arr,10);
	if(1==flag)
		printf("yes\n");
	else if(0==flag)
		printf("no\n");
	return 0;
}