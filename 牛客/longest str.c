/*
输入一个整数n,输入n个字符串，输出最长的那个字符串
*/


#include<stdio.h>
#include<string.h>

int main()
{	
	int n;
	char ch;
	scanf("%d",&n);
	while(getchar()!='\n');
	char str[n][100]={0};

	for(int i=0;i<n;i++)
	{
		scanf("%s",str[i]);
		printf("%d %s\n",i,str[i]);
	}
	
	int index,max;
	
	max = strlen(str[0]);
	
	for(int i=0;i<n;i++)
	{
		if(max < strlen(str[i]))
		{
			max = strlen(str[i]);
			index = i;
			printf("%d %ld\n",index,strlen(str[i]));
			printf("%ld\n",strlen(str[2]));
		}
		
	}
	
	printf("%s\n",str[index]);
	
}