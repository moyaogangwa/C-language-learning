#include <stdio.h>

//½×³Ë


int Factorial(int num)
{
	int x = 1;
	if(num>1)
	{
		x=Factorial(num-1);
	}
	x*=num;
	return x;
}


int main()
{
	int n = 0 ,jc = 0;
	scanf("%d",&n);
	jc=Factorial(n);
	printf("%d\n",jc);
	return 0;
}