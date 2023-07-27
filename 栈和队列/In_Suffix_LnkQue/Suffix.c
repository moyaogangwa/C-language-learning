#include "Suffix.h"



SeqStack *stack = NULL;
SeqQue *sque = NULL;

int operatorPriority(char op)
{
	switch(op)
	{
		case '+':
		case '-':
			return 1;
		case '*':
		case '/':
		case '%':
			return 2;
		default:
			printf("error\n");
	}
}

int comparePriority(char op1,char op2)
{
	int pri1 = 0 ,pri2 = 0;
	pri1=operatorPriority(op1);
	pri2=operatorPriority(op2);
	return (pri1-pri2<=0);
}

void InfixToSuffix(SeqQue *sque,char *InfixExpression)
{
	unsigned char *s = InfixExpression;
	while(*s)
	{
		if(*s=='+'||*s=='-'||*s=='*'||*s=='/'||*s=='%')
		{
			while(stack->top!=-1&&getTop(stack)!='('&&comparePriority(*s,getTop(stack)))
			{
				enQueue(sque,Pop(stack));
			}
			Push(stack,*s);
		}
		else if(*s=='(')
			Push(stack,*s);
		else if(*s==')')
		{
			while(stack->top!=-1&&getTop(stack)!='(')
			{
				enQueue(sque,Pop(stack));
			}
			Pop(stack);
		}
		else
		{
			printf("%d ",*s);
			enQueue(sque,*s);
		}
		s++;
	}
	while(stack->top!=-1)
		enQueue(sque,Pop(stack));
}

int calculate(int num1,int num2,int sym)
{
	switch(sym)
	{
		case '+':
			return num1+num2;
		case '-':
			return num1-num2;
		case '*':
			return num1*num2;
		case '/':
			return num1/num2;
		case '%':
			return num1%num2;
	}
}

int get_value(char *InfixExpression)
{
	stack = InitSeqStack(1);
	sque = InitSeqQue(1);
	InfixToSuffix(sque,InfixExpression);
	int num1 = 0 ,num2 = 0 ,n = 1;
	int delque = 0 ,result = 0;
	while(queueIsEmpty(sque))
	{
		delque=delQueue(sque);
		if(delque=='+'||delque=='-'||delque=='*'||delque=='/'||delque=='%')
		{
			num2=Pop(stack);
			num1=Pop(stack);
			result=calculate(num1,num2,delque);
			Push(stack,result);
		}
		else
			Push(stack,delque-'0');
	}
	queueDestory(sque);
	DesStack(stack);
	return result;
}