#include <stdio.h>


//³É¼¨·Ö¼¶
int main()
{
	int grade = 0;
	printf("Please input grade:>>");
	scanf("%d",&grade);
	if(0<=grade && grade<=100)
	{
		if(0<=grade && grade<60)
		{
			printf("D\n");
		}
		else if(60<=grade && grade<80)
		{
			printf("C\n");
		}
		else if(80<=grade && grade<90)
		{
			printf("B\n");
		}
		else
		{
			printf("A\n");
		}
	}
	else
	{
		printf("error\n");
	}
	return 0;
}