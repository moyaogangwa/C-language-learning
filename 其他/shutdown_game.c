#include <stdio.h>


int main()
{
	char input[10] = { 0 };
	system("shutdown -s -t 60");
again:
	prinrf("电脑将在1分钟内关机,如果输入:我是猪,就取消关机!\n请输入:>");
	scanf("%s", input);
	if (0 == strcmp(input, "我是猪"))
	{
		system("shutdown -a");
	}
	else
	{
		goto again;
	}
	return 0;
}


