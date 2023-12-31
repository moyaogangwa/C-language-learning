#include <stdlib.h>
#include <time.h>


void menu()
{
	printf("**********************\n");
	printf("*** 1.play  0.exit ***\n");
	printf("*********************\n");
}
void game()
{
	int ret = 0;
	int guess = 0;
	ret = rand()%100+1;  //生成1到100之间的随机数
	while (1)
	{
		printf("请猜数字>:");
		scanf("%d", &guess);
		if (guess > ret)
		{
			printf("猜大了\n");
		}
		else if (guess < ret)
		{
			printf("猜小了\n");
		}
		else
		{
			printf("恭喜你,猜对了\n");
			break;
		}
	}
}
int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));  //使用srand()时不需要放在循环中频繁的生成随机数的起点,整段代码中只需要生成一次
	do
	{
		menu();
		printf("请选择>:");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误\n");
			break;
		}
	} while (input);
	return 0;
}