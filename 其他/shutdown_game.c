#include <stdio.h>


int main()
{
	char input[10] = { 0 };
	system("shutdown -s -t 60");
again:
	prinrf("���Խ���1�����ڹػ�,�������:������,��ȡ���ػ�!\n������:>");
	scanf("%s", input);
	if (0 == strcmp(input, "������"))
	{
		system("shutdown -a");
	}
	else
	{
		goto again;
	}
	return 0;
}


