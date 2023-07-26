#ifndef __LNKSTACK_H__
#define __LNKSTACK_H__ 1

//��������
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

//��������

/*
	initStack():ջ�ĳ�ʼ��
		����ֵ��
			����һ��ջָ��
*/
LnkStack *initStack();

/*
	Push(LnkStack *stack,StackElemType data)����ջ / ѹջ
		�βΣ�
			stack:ջָ�룬ָ��һ��ջ
			data:Ҫ��ջ��Ԫ��
*/
void Push(LnkStack *stack,StackElemType data);

/*
	Pop(LnkStack *stack)����ջ
		�βΣ�
			stack:ջָ�룬ָ��һ��ջ
		����ֵ��
			����ջ��Ԫ�ص�����
*/
StackElemType Pop(LnkStack *stack);

/*
	stackIsEmpty(LnkStack *stack)������ջ��Ԫ�ظ���
		�βΣ�
			stack:ջָ�룬ָ��һ��ջ
		����ֵ��
			������Ԫ�ظ���
*/
int stackIsEmpty(LnkStack *stack);

/*
	getTop(LnkStack *stack)����ȡջ��Ԫ�صĵ�ַ
		�βΣ�
			stack:ջָ�룬ָ��һ��ջ
		����ֵ��
			����ջ��Ԫ�صĵ�ַ
*/
StackNode *getTop(LnkStack *stack);

/*
	ClearStack(LnkStack *stack)�����ջ��Ԫ��
		�βΣ�
			stack:ջָ�룬ָ��һ��ջ
*/
void ClearStack(LnkStack *stack);

/*
	DesStack(LnkStack *stack)������ջ
		�βΣ�
			stack:ջָ�룬ָ��һ��ջ
*/
void DesStack(LnkStack *stack);





#endif  //LnkStach.h