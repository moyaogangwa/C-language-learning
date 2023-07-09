#include <stdio.h>


//机器人走方格

#define N 3
#define M 4

int main()
{
	int arr[N][M] = {0};
	int i = 0 ,j = 0;
	for(i=0;i<N;i++)
	{
		for(j=0;j<M;j++)
		{
			if(0==i||0==j)
				arr[i][j]=1;
			else
			{
				arr[i][j]=arr[i-1][j]+arr[i][j-1];
			}
		}
	}
	printf("%d\n",arr[N-1][M-1]);
	return 0;
}