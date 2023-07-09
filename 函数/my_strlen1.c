#include <stdio.h>


//获取字符长度

int my_strlen(char arr[])
{
	int i = 0;
	while(arr[i++]);
	return i--;
}


int main()
{
	int lg = 0 ,i = 0;
	char str[100] = {0};
	while(i<100)
	{
		str[i]=getchar();
		if(str[i]=='\n')
		{
			str[i]=0;
			break;
		}
		i++;
		if(100==i)
		{
			str[99]=0;
			printf("full ");
			break;
		}
	}
	lg = my_strlen(str);
	printf("long=%d\n",lg);
	return 0;
}
