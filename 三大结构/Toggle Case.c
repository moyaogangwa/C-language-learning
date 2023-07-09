#include <stdio.h>

//´óÐ¡Ð´×ª»»

int main()
{
	char ch = '0';
	scanf("%c",&ch);
	if('A'<=ch && ch<='Z')
	{
		ch = ch + 32;
	}
	else if('a'<=ch && ch<='z')
	{
		ch = ch -32;
	}
	printf("%c\n",ch);
	return 0;
}