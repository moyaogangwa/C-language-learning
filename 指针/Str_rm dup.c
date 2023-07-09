#include <stdio.h>
#include <string.h>

#define N 50

//删除字符串中的重复项
void Str_rmdup(char *ps,int n)
{
	int i = 0 ,j = 0 ,m = 0;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(ps[j]==ps[i]||0==ps[j])
			{
				m=j+1;
				while((ps[m]==ps[i]||0==ps[m])&&m<n)  //在j+1到n的范围内找到第一个一个不等于ps[i]和0的值
					m++;
				ps[j]=ps[m];		//将这个找到的值覆盖重复值(0值),并将该值原位置置0
				ps[m]=0;
			}
		}
	}
}

int main()
{
	char str[N] = {0};
	int length = 0;
	
	printf("please input str:>>");
	scanf("%s",str);
	length = strlen(str);
	Str_rmdup(str,length);
	
	printf("%s\n",str);
	return 0;
}



/* 直接置0输出
void Str_rmdup(char *ps,int n)
{
	int i = 0 ,j = 0 ,m = 0;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(ps[j]==ps[i])
			{
				ps[j]=0;
			}
		}
		printf("%c",ps[i]);
	}
}

int main()
{
	char str[N] = {0};
	int length = 0;
	
	printf("please input str:>>");
	scanf("%s",str);
	length = strlen(str);
	Str_rmdup(str,length);
	return 0;
}
*/



/* 新建一个数组输出
Str_rmdup(char *ps,int n)
{
	int i = 0 ,j = 1 ,m = 0 ,flag = 0;
	char arr[n+1] = {0};
	arr[0] = ps[0];
	for(i=0;i<n;i++)
	{
		m=j;
		while(m--)
		{
			if(ps[i]==arr[m])
			{
				flag=1;
				break;
			}
		}
		if(0==flag)
		{
			arr[j]=ps[i];
			j++;
		}
	}
	printf("%s\n",arr);
}

int main()
{
	char str[N] = {0};
	int length = 0;
	printf("please input str:>>");
	scanf("%s",str);
	length = strlen(str);
	Str_rmdup(arr,length);
	printf("%s\n",str);
	return 0;
}

*/