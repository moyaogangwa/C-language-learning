#include <stdio.h>
#include "Suffix.h"


int main()
{
	int result = 0;
	char expression[100] = {0};
	gets(expression);
	result=getvalue(expression);
	printf("result:%d",result);
	return 0;
}


//a+b\*c+(e*d+f) *g

//����ʽ�ӵĺ�׺���ʽ��abc * + ed * f + g * +