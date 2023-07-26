#include "Suffix.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LnkStack.h"

LnkStack *stack = NULL;

int operatorPriority(int op)
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

//判断优先级
int comparePriority(int op1,int op2)
{
	int pri1 = 0 ,pri2 = 0;
	pri1=operatorPriority(op1);
	pri2=operatorPriority(op2);
	return (pri1-pri2<=0);
}


//中缀转后缀
void InfixToSuffix(char *tp,char *InfixExpression)
{
	stack = initStack();
	char *s = InfixExpression;
	while(*s)
	{
		
		if('0'<=*s&&'9'>=*s)
		{
			if(s==InfixExpression ||('0'>*(s-1)||'9'<*(s-1)))
			{
				*tp='#';
				tp++;
			}
			*tp=*s;
			tp++;
		}
		
		else if(*s=='+'||*s=='-'||*s=='*'||*s=='/'||*s=='%')
		{
			while(stack->top&&getTop(stack)->data!='('&&comparePriority(*s,getTop(stack)->data))
			{
				*tp=Pop(stack);
				tp++;
			}
			Push(stack,*s);
		}
		
		else if(*s=='(')
			Push(stack,*s);
		
		else if(*s==')')
		{
			while(stack->top&&getTop(stack)->data!='(')
			{
				*tp=Pop(stack);
				tp++;
			}
			Pop(stack);
		}
		s++;
	}
	while(stack->top)
	{
		*tp=Pop(stack);
		tp++;
	}
	*tp=0;
}


int calculate(int num1,int num2,char sym)
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

//将得到的结果入栈
void Push_inttochar(LnkStack *stack ,int x)
{
	if(x>9)
	{
		Push_inttochar(stack ,x/10);
	}
	Push(stack,x%10+'0');
}


int getvalue(char *InfixExpression)
{
	char *temp = malloc(2*strlen(InfixExpression)+1);
	InfixToSuffix(temp,InfixExpression);
	puts(temp);
	char *tp = temp;
	int num1 = 0 ,num2 = 0 ,n = 1;
	int popdata = 0 ,result = 0;
	while(*tp)
	{
		
		if(('0'<=*tp&&'9'>=*tp)||'#'==*tp)   //#用来分割不同数
			Push(stack,*tp);
		else if(*tp=='+'||*tp=='-'||*tp=='*'||*tp=='/'||*tp=='%')
		{
			num1=num2=0;
			do
			{
				popdata=Pop(stack);
				if(popdata!='#')
					num1=num1+n*(popdata-'0');
				n*=10;
			}while(popdata!='#');
			n=1;
			do
			{
				popdata=Pop(stack);
				if(popdata!='#')
					num2=num2+n*(popdata-'0');
				n*=10;
			}while(popdata!='#');
			n=1;
			result=calculate(num1,num2,*tp);

			if(*(tp+1))
			{
				Push(stack,'#');
				Push_inttochar(stack ,result);
			}
		}
		tp++;
	}
	DesStack(stack);
	free(temp);
	return result;
}







