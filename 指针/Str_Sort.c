#include <stdio.h>
#include <string.h>

//将字符串进行排序

#define N 10

void Str_sort(char *ps ,int n)
{
	int i = 0 ,j = 0;
	char temp;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-1-i;j++)
		{
			if(ps[j]>ps[j+1])
			{
				temp = ps[j];
				ps[j]=ps[j+1];
				ps[j+1]=temp;
			}
		}
	}
}


int main()
{
	char str[N] = {0};
	int length = 0;
	printf("please input lowercase str:>>");
	scanf("%s",str);
	printf("%s\n",str);
	length = strlen(str);
	Str_sort(str,length);
	printf("%s\n",str);
	return 0;
}