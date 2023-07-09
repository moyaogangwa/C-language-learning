#include <stdio.h>

int main()
{
	int grade = 0;
	printf("please input:>>");
	scanf("%d",&grade);
	grade /= 10;
	switch(grade)
	{
		case 0:
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
			printf("D\n");
			break;
		case 6:
		case 7:
			printf("C\n");
			break;
		case 8:
			printf("B\n");
			break;
		case 9:
		case 10:
			printf("A\n");
			break;
		default:
			printf("error\n");
			break;
	}
	return 0;
}