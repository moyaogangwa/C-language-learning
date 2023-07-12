#include "BubbleSort.h"


void BubbleSort(int *p,int n)
{
	int i = 0 ,j = 0;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-1-i;j++)
		{
			if(p[j]>p[j+1])
			{
				p[j]=p[j]^p[j+1];
				p[j+1]=p[j]^p[j+1];
				p[j]=p[j]^p[j+1];
			}
		}
	}
}