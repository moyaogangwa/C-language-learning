#ifndef __LNKSTACK_H__
#define __LNKSTACK_H__ 1

#include "MidAndPreToBiTree.h"

//声明变量
typedef LnkBiTree *StackElemType;

typedef struct Stacknode
{
	StackElemType data;
	struct Stacknode *next;
}StackNode;

typedef struct stack
{
	StackNode *top;
	StackNode *bottom;
	int num;
}LnkStack;

//函数声明

LnkStack *initStack();

void Push(LnkStack *stack,StackElemType data);

StackElemType Pop(LnkStack *stack);

int stackIsEmpty(LnkStack *stack);

StackNode *getTop(LnkStack *stack);

void ClearStack(LnkStack *stack);

void DesStack(LnkStack *stack);





#endif //LnkStack.h