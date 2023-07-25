#include "LnkStack.h"
#include <stdio.h>
#include <stdlib.h>

LnkStack *initStack()
{
	LnkStack * stack = malloc(sizeof(LnkStack));
	stack->top=NULL;
	stack->bottom=NULL;
	stack->num=0;
	return stack;
}

void Push(LnkStack *stack,StackElemType data)
{
	
	//将data封装成节点
	StackNode *Snode = malloc(sizeof(StackNode));
	Snode->data=data;
	Snode->next=NULL;
	if( stackIsEmpty(stack) )   //不为空
	{
		Snode->next=stack->top;
		stack->top=Snode;
	}
	else
	{
		stack->top=stack->bottom=Snode;
	}
	stack->num++;
}

StackElemType Pop(LnkStack *stack)
{
	StackNode *p = stack->top;
	StackElemType data = 0;
	if( stackIsEmpty(stack) )  //不为空
	{
		stack->top=p->next;
		p->next=NULL;
		data=p->data;
		free(p);
		stack->num--;
		return data;
	}
	return -1;
	
}

int stackIsEmpty(LnkStack *stack)
{
	return stack->num;
}


StackNode *getTop(LnkStack *stack)
{
	return stack->top;
}

void ClearStack(LnkStack *stack)
{
	while(stackIsEmpty(stack))
		Pop(stack);
}

void DesStack(LnkStack *stack)
{
	ClearStack(stack);
	free(stack);
}











