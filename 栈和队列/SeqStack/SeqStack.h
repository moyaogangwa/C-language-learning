#ifndef __SEQSTACK_H__
#define __SEQSTACK_H__ 1

//变量声明

#define BASESTACKSIZE 1024     // 每次扩容的基数
typedef int StackElemtype;

typedef struct sequencestack
{
	int top;
	unsigned int size;
	unsigned int num;
	StackElemtype stack[0];
}SeqStack;

//函数声明

SeqStack *InitSeqStack(int n);

void Push(SeqStack *seqstack,StackElemtype n);

int Pop(SeqStack *seqstack);

int getTop(SeqStack *seqstack);

void ClearStack(SeqStack *seqstack);

void DesStack(SeqStack *seqstack);

SeqStack *kuorong(SeqStack *seqstack,int n);


#endif   //SeqStack.h