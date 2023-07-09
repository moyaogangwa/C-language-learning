#include <stdio.h>

//¸ùºÅ

float my_sqrt(float x)
{
	float left = 0.0 ,right = x;
	float mid = 0.0;
	while(right-left>0.0001)
	{
		mid = (left+right)/2;
		if(mid*mid<x)
		{
			left = mid+0.0001;
		}
		else if(mid*mid>x)
		{
			right = mid-0.0001;
		}
		else
			break;
	}
	return mid;
}


int main()
{
	float num = 0 ,value = 0;
	scanf("%f",&num);
	value = my_sqrt(num);
	printf("%.3f\n",value);
	return 0;
}