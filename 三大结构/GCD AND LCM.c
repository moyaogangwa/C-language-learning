#include <stdio.h>

//��������������,������ǵ����Լ������С������(ŷ������㷨) //��С������ = ����֮�� / ���Լ��

int main()
{
	int num1 = 0 ,num2 = 0;
	int temp = 0 ,gcd = 0 ,lcm = 0;     //gcd:���Լ��  lcm:��С������
	scanf("%d%d",&num1,&num2);
	lcm = num1*num2;
	while(temp=num1%num2)
	{
		num1 = num2;
		num2 = temp;
	}
	gcd = num2;
	lcm /= gcd;
	printf("GCD = %d , LCM = %d\n",gcd,lcm);
	return 0;
}