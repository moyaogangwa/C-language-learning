#ifndef __LNKSTACK_H__
#define __LNKSTACK_H__ 1

//声明变量
typedef char StackElemType;

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

/*
	initStack():栈的初始化
		返回值：
			返回一个栈指针
*/
LnkStack *initStack();

/*
	Push(LnkStack *stack,StackElemType data)：入栈 / 压栈
		形参：
			stack:栈指针，指向一个栈
			data:要入栈的元素
*/
void Push(LnkStack *stack,StackElemType data);

/*
	Pop(LnkStack *stack)：出栈
		形参：
			stack:栈指针，指向一个栈
		返回值：
			返回栈顶元素的数据
*/
StackElemType Pop(LnkStack *stack);

/*
	stackIsEmpty(LnkStack *stack)：计算栈中元素个数
		形参：
			stack:栈指针，指向一个栈
		返回值：
			返回中元素个数
*/
int stackIsEmpty(LnkStack *stack);

/*
	getTop(LnkStack *stack)：获取栈顶元素的地址
		形参：
			stack:栈指针，指向一个栈
		返回值：
			返回栈顶元素的地址
*/
StackNode *getTop(LnkStack *stack);

/*
	ClearStack(LnkStack *stack)：清除栈中元素
		形参：
			stack:栈指针，指向一个栈
*/
void ClearStack(LnkStack *stack);

/*
	DesStack(LnkStack *stack)：销毁栈
		形参：
			stack:栈指针，指向一个栈
*/
void DesStack(LnkStack *stack);





#endif  //LnkStach.h