#include <stdio.h>


//my_strcmp

int my_strcmp(const char *s1, const char *s2)
{
	int i = 0;
	while(s1[i]==s2[i])
	{
		if(0==s1[i])
			break;
		i++;
	}
	return s1[i]-s2[i];
}


int main()
{
	char *str1 = "hello world";
	char *str2 = "hello";
	int ret = my_strcmp(str1,str2);
	printf("%d\n",ret);
	return 0;
}

