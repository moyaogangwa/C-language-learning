#include <stdio.h>


//my_strcpy

char *my_strcpy(char *dest, const char *src)
{
	int i = 0;
	while(dest[i]=src[i])
		i++;
	return dest;
}


int main()
{
	char *str="hello world";
	char str1[12]={0};
	my_strcpy(str1,str);
	printf("%s\n",str1);
	return 0;
}


