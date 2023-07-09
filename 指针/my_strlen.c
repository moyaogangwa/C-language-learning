#include <stdio.h>

//my strlen

size_t my_strlen(const char *s)
{
	size_t length = 0;
	while(*(s++))
		length++;
	return length;
}

int main()
{
	char *str = "hello world";
	int length = my_strlen(str);
	printf("length=%d\n",length);
}


