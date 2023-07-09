#include <stdio.h>

//Ã°ÅİÅÅĞò

int main()
{
	int arr[10] = {0};
	int i = 0, j = 0;
	for(i=0;i<10;i++)
	{
		scanf("%d",&arr[i]);
	}
	for(i=0;i<10-1;i++)
	{
		for(j=0;j<10-1-i;j++)
		{
			if(arr[j]>arr[j+1])
			{
				arr[j] = arr[j]^arr[j+1];
				arr[j+1] = arr[j]^arr[j+1];
				arr[j] = arr[j]^arr[j+1];
			}
		}
	}
	for(i=0;i<10;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
	return 0;
}