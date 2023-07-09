#include <stdio.h>


//Ñ°ÕÒË®ÏÉ»¨Êý

int main()
{
	int sum = 0 ,temp = 0 ,i = 0 ,refer = 0;
	int L = 0 ,H = 0; 
	printf("please input min and max:>>");
	scanf("%d%d",&L,&H);
	for(i = L;i<=H;i++)
	{
		sum = 0;
		refer = i;
		while(refer)
		{
			temp = refer%10;
			refer = refer/10;
			sum=sum+temp*temp*temp;
		}
		if(i == sum)
		{
			printf(" %d ",i);
		}
	}
	printf("\n");
	return 0;
}