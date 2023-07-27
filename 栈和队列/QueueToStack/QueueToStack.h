#ifndef __QUEUETOSTACK_H__
#define __QUEUETOSTACK_H__ 1



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

void Push(SeqQue *seqque,int x);

QueElemType delQueue(SeqQue *seqque);

QueElemType Pop(SeqQue *seqque);

int getFront(SeqQue *seqque);

int queueIsEmpty(SeqQue *seqque);

int queueIsFull(SeqQue *seqque);

void queueClear(SeqQue *seqque);

void queueDestory(SeqQue *seqque);

int getQueueLen(SeqQue *seqque);

SeqQue *dil_queue(SeqQue *seqque,int n);

#endif