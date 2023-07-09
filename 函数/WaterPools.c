#include <stdio.h>

//Ë®ÍÝÊý

#define N 5
#define M 5

void clear_wa(int arr[][M],int i,int j)
{
	if(i<N&&i>=0&&j<M&&j>=0)
	{
		if(0==arr[i][j])
			return;
		arr[i][j]=0;
		clear_wa(arr,i+1,j);
		clear_wa(arr,i-1,j);
		clear_wa(arr,i,j+1);
		clear_wa(arr,i,j-1);
	}
}
int find_wa(int arr[][M],int n,int m)
{
	int i = 0 ,j = 0 ,num = 0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(1==arr[i][j])
			{
				clear_wa(arr,i,j);
				num++;
			}
		}
	}
	return num;
}

int main()
{
	int arr[N][M] = {0};
	int i = 0 ,j = 0 ,num = 0;
	printf("please input arr(0 or 1):>>\n");
	for(i=0;i<N;i++)
	{
		for(j=0;j<M;j++)
		{
			scanf("%d",&arr[i][j]);
		}
	}
	printf("Your farm:\n");
	for(i=0;i<N;i++)
	{
		for(j=0;j<M;j++)
		{
			printf("%d ",arr[i][j]);
		}
		printf("\n");
	}
	num = find_wa(arr,N,M);
	printf("%d\n",num);
	return 0;
}