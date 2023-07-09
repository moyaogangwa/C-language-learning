#include <stdio.h>

//×ßÌ¨½×

#define N 20
int main()
{
	int n = 0 ,ways[N]={1,1,2};
	int i = 0;
	printf("Please enter the number of steps:>>");
	scanf("%d",&n);
	for(i=3;i<N;i++)
	{
		ways[i]=ways[i-1]+ways[i-2];
	}
	printf("There are %d ways\n",ways[n]);
	return 0;
}