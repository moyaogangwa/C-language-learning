#include <stdio.h>

int main()
{
	int num1 =0,num2 =0;
	char ch = '0';
	printf("please input:>>");
	scanf("%d %c %d",&num1,&ch,&num2);
	switch(ch)
	{
		case '+':
			printf("%d %c %d = %d\n",num1,ch,num2,num1+num2);
			break;
		case '-':
			printf("%d %c %d = %d\n",num1,ch,num2,num1-num2);
			break;
		case '*':
			printf("%d %c %d = %d\n",num1,ch,num2,num1*num2);
			break;
		case '/':
			printf("%d %c %d = %d\n",num1,ch,num2,num1/num2);
			break;
		case '%':
			printf("%d %c %d = %d\n",num1,ch,num2,num1%num2);
			break;
		default:
			printf("error\n");
		
	}
	return 0;
}