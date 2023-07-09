#include <stdio.h>

//my_strcat

char *my_strcat(char *dest, const char *src)
{
	int i = 0 ,j = 0;
	while(dest[i])
		i++;
	while(dest[i]=src[j])
	{
		i++;j++;
	}
	return dest;
}

int main()
{
	char *str = "hello world";
	char str1[50]={'m','y','_','s','t','r','c','a','t',' '};
	my_strcat(str1,str);
	printf("%s\n",str1);
	return 0;
}


