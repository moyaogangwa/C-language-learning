#include <stdio.h>

//���,�������Сֵ

#define MAX(X,Y) (X)>(Y)?(X):(Y)
#define MIN(X,Y) (X)<(Y)?(X):(Y)
int main()
{
	int arr[5] = {0};
	int i = 0,sum = 0,max = 0,min = 0;
	for(i=0;i<5;i++)
	{
		scanf("%d",&arr[i]);
		sum += arr[i];
	}
	min = max = arr[0];
	for(i=0;i<5;i++)
	{
		max=MAX(max,arr[i]);
		min=MIN(min,arr[i]);
	}
	printf("sum = %d , max = %d , min = %d\n",sum,max,min);
	return 0;
}