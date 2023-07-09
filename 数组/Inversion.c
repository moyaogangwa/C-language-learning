#include <stdio.h>

//逆置数组中的元素

#define N 10
int main()
{
	int arr[N] = {0} ;
	int i = 0;
	for(i=0;i<N;i++)
	{
		scanf("%d",&arr[i]);
	}
	
	for(i=0;i<N/2;i++)
	{
		arr[i]=arr[i]^arr[N-i-1];
		arr[N-i-1]=arr[i]^arr[N-i-1];
		arr[i]=arr[i]^arr[N-i-1];
	}
	
	for(i=0;i<N;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
	return 0;
}




