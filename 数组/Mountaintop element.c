#include <stdio.h>

//É½¶¥ÔªËØ 

#define N 5
#define M 5
int main()
{
	int arr[N][M] = {0};
	int i = 0 ,j = 0 ,n = 0;
	for(i=0;i<N;i++)
	{
		for(j=0;j<M;j++)
		{
			scanf("%d",&arr[i][j]);
		}
	}
	for(i=0;i<N;i++)
	{
		for(j=0;j<M;j++)
		{
			if((0==i||arr[i][j]>arr[i-1][j])&&(0==j||arr[i][j]>arr[i][j-1])&&
				(N==i||arr[i][j]>arr[i+1][j])&&(M==j||arr[i][j]>arr[i][j+1]))
			{
				printf("arr[%d][%d]=%d ",i,j,arr[i][j]);
				n++;
			}
			
		}
	}
	printf("total:%d\n",n);
	return 0;
}