#include <stdio.h>
#include <time.h>
#include <stdlib.h>

//µãÃû

void game()
{
	int i = 0 ,j = 0;
	i = rand()%6+1;
	j = rand()%13+1;
	printf("[%d,%d]\n",i,j);
}


int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		printf("please select(1:play 0:quit):>>");
		scanf("%d",&input);
		switch(input)
		{
			case 1:
				game();
				break;
			case 0:
				printf("quit\n");
				break;
			default:
				printf("error\n");
				break;
		}
	}while(input);
	
	return 0;
}