#include "SelectionSort.h"

void SelectionSort(int *p ,int n)
{
	int i = 0 ,j = 0;
	int max = 0 ,index = 0;
	for(i=0;i<n-1;i++)
	{
		max = p[0];
		for(j=0;j<=n-1-i;j++)
		{
			if(p[j]>max)
			{
				max=p[j];
				index=j;
			}
		}
		p[index]=p[n-1-i];
		p[n-1-i]=max;
	}
}

