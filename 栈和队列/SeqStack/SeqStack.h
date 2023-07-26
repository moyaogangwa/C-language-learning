#ifndef __SEQSTACK_H__
#define __SEQSTACK_H__ 1

//��������

#define BASESTACKSIZE 1024     // ÿ�����ݵĻ���
typedef int StackElemtype;

typedef struct sequencestack
{
	int top;
	unsigned int size;
	unsigned int num;
	StackElemtype stack[0];
}SeqStack;

//��������

SeqStack *InitSeqStack(int n);

void Push(SeqStack *seqstack,StackElemtype n);

int Pop(SeqStack *seqstack);

int getTop(SeqStack *seqstack);

void ClearStack(SeqStack *seqstack);

void DesStack(SeqStack *seqstack);

SeqStack *kuorong(SeqStack *seqstack,int n);


#endif   //SeqStack.h