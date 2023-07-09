#include <stdio.h>

int main()
{
	int a, g, s, b;
	scanf("%d", &a);

	g = a%10;
	s = a/10%10;
	b = a/100;

	if (a == g*g*g + s*s*s + b*b*b)
	{
		printf("yes\n");
	}
	else
	{
		printf("no\n");
	}
	return 0;
}