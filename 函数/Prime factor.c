#include <stdio.h>

//ÖÊÒòÊı

void Prime_Fac(int P_num)
{
	int i = 2;
	while(i<=P_num)
	{
		if(0==P_num%i && 1!=P_num/i)
		{
			printf("%d*",i);
			P_num=P_num/i;
		}
		else if(0==P_num%i && 1==P_num/i)
		{
			printf("%d\n",i);
			break;
		}
		else
			i++;
	}
}

int main()
{
	int num = 0;
	scanf("%d",&num);
	printf("%d=",num);
	Prime_Fac(num);
	return 0;
}
