#include <stdio.h>


//����������,�ж����������ܷ����һ��������

int main()
{
	int num1 = 0,num2 = 0,num3 = 0;
	int max = 0;
	scanf("%d %d %d",&num1,&num2,&num3);
	if(num1>=num2)
	{
		if(num1>=num3)
		{
			max = num1;
		}
		else
		{
			max = num3;
		}
	}
	else
	{
		if(num2>=num3)
		{
			max = num2;
		}
		else
		{
			max = num3;
		}
	}
	(max-num1<num2 && num1+num2>max) ? printf("�������������\n") : printf("���������������\n");
	
}