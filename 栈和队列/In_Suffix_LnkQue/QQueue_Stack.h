#ifndef __QQUEUE_STACK_H__
#define __QQUEUE_STACK_H__ 1

//ͷ�ļ�
#include <stdlib.h>
#include <string.h>


//˳�����

//��������

#define BASEQUEUESIZE 1024

typedef char QueElemType;
typedef struct seqqueue
{
	int front;
	int rear;
	int max;
	QueElemType queue[0];
}SeqQue;

//��������

SeqQue *InitSeqQue(int n);

void enQueue(SeqQue *seqque,int x);

QueElemType delQueue(SeqQue *seqque);

int getFront(SeqQue *seqque);

int queueIsEmpty(SeqQue *seqque);

int queueIsFull(SeqQue *seqque);

void queueClear(SeqQue *seqque);

void queueDestory(SeqQue *seqque);

int getQueueLen(SeqQue *seqque);

SeqQue *dil_queue(SeqQue *seqque,int n);


//˳��ջ

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

void Push(SeqStack *seqstk,int x);

StackElemtype Pop(SeqStack *seqstk);

int getTop(SeqStack *seqstack);

void ClearStack(SeqStack *seqstack);

void DesStack(SeqStack *seqstack);

SeqStack *dil_stack(SeqStack *seqstack,int n);


#endif   //QQueue_Stack.h