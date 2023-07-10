#include <stdio.h>


//打印1000年到2000年之间的闰年
int main()
{
	int year = 0;
	int count = 0;
	for (year = 1000; year <= 2000; year++)       
	{                                               
		if (year % 4 == 0 && year % 100 != 0)     
		{
			printf("%d ", year);
			count++;
		}

		else if (year % 400 == 0)
		{
			printf("%d ", year);
			count++;
		}
	}
	printf("\ncount=%d", count);
	return 0;
}


