#include "QuickSort.h"


void QuickSort(int *p,int start,int end)
{
	if(start>=end)
		return;
	int left = start ,right = end;
	int base = p[start];
	while(left<right)
	{
		while(p[left]<=base && left<right)
			left++;
		while(p[right]>base && left<right)
			right--;
		if(p[left]!=p[right])
		{
			p[left]=p[left]^p[right];
			p[right]=p[left]^p[right];
			p[left]=p[left]^p[right];
		}
	}
	if(start==left-1 && p[left]<base)
	{
		p[start]=p[left];
		p[left]=base;
	}
	else
	{
		p[start]=p[left-1];
		p[left-1]=base;
	}
	QuickSort(p,start,left-2);
	QuickSort(p,left,end);
}
