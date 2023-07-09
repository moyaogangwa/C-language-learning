#include <stdio.h>

//输出两个数及之间偶数的和


int main()
{
	int L = 0, H = 0;
	int i =0, sum = 0;
	printf("please input min and max:>>");
	scanf("%d%d",&L,&H);
	i=L;
	while(i<=H)
	{
		sum=(0==i%2)?sum+i:sum;
		i++;
	}
	printf("sum=%d\n",sum);
	return 0;
}