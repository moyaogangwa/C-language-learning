#include "Sort.h"


//√∞≈›≈≈–Ú

void * Bubble_Sort(int *p,int n)
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
	return p;
}

//—°‘Ò≈≈–Ú

void * Selection_Sort(int *p,int n)
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
				index=j;
			}
		}
		p[index]=p[index]^p[n-1-i];
		p[n-1-i]=p[index]^p[n-1-i];
		p[index]=p[index]^p[n-1-i];
	}
	return p;
}










