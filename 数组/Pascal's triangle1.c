#include <stdio.h>

//�������

int main()
{
	int i = 0 ,j = 0;
	int n = 0;
	scanf("%d",&n);
	int arr[n][n];
	for(i=0;i<n;i++)
	{
		arr[i][0] = 1;
		arr[i][i] = 1;
	}
	for(i=1;i<n;i++)
	{
		for(j=1;j<i;j++)
		{
			arr[i][j] = arr[i-1][j]+arr[i-1][j-1];
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<=i;j++)
		{
			printf("%d ",arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}