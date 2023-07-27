#ifndef __SUFFIX_H__
#define __SUFFIX_H__ 1

//头文件
#include "QQueue_Stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//函数声明
int operatorPriority(char op);

int comparePriority(char op1,char op2);

void InfixToSuffix(SeqQue *sque,char *InfixExpression);

int calculate(int num1,int num2,int sym);

int get_value(char *InfixExpression);

#endif//Suffix.h


