#include <stdio.h>


#define N 3
#define M 10

int main()
{
	int i = 0 ,j = 0 ,max = 0;
	int arr[N][M]={0};
	
	for(i=0;i<N;i++)
	{
		for(j=0;j<M;j++)
		{
			scanf("%d",&arr[i][j]);
			if(0==i&&0==j)
				  max = arr[0][0];
			max = max>arr[i][j]?max:arr[i][j];
		}
	}
	printf("max = %d\n",max);
	return 0;
}