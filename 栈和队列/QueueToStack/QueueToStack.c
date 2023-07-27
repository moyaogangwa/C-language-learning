#include "QQueue.h"


//Ë³Ðò¶ÓÁÐ
SeqQue *InitSeqQue(int n)
{
	SeqQue *seqque = malloc(sizeof(SeqQue)+n*BASEQUEUESIZE);
	seqque->front=seqque->rear=0;
	seqque->max=n*BASEQUEUESIZE;
	memset(seqque->queue,0,n*BASEQUEUESIZE);
	return seqque;
}

void enQueue(SeqQue *seqque,int x)
{
	if(!queueIsFull(seqque))
	{
		seqque->queue[seqque->rear]=x;
		seqque->rear++;
		seqque->rear=(seqque->rear)%(seqque->max);
	}
}

void Push(SeqQue *seqque,int x)
{
	SeqQue *sque = InitSeqQue(1);
	while(queueIsEmpty(seqque))
		enQueue(sque,delQueue(seqque));
	enQueue(seqque,x);
	while(queueIsEmpty(sque))
		enQueue(seqque,delQueue(sque));
	queueDestory(sque);
}


QueElemType Pop(SeqQue *seqque)
{
	QueElemType t = -1;
	if(queueIsEmpty(seqque))
	{
		t = seqque->queue[seqque->front];
		seqque->front++;
		seqque->front=(seqque->front)%(seqque->max);
	}
	return t;
}	

QueElemType delQueue(SeqQue *seqque)
{
	QueElemType t = -1;
	if(queueIsEmpty(seqque))
	{
		t = seqque->queue[seqque->front];
		seqque->front++;
		seqque->front=(seqque->front)%(seqque->max);
	}
	return t;
	
}

int getFront(SeqQue *seqque)
{
	if ( queueIsEmpty(seqque) )
		return seqque->queue[seqque->front];
	
	return -1;
}

int queueIsEmpty(SeqQue *seqque)
{
	if ( seqque->front == seqque->rear )
		return 0;
	
	return 1;
}

int queueIsFull(SeqQue *seqque)
{
	return ((seqque->rear+1) % (seqque->max) == seqque->front);
}

void queueClear(SeqQue *seqque)
{
	seqque->front = seqque->rear = 0;
}

void queueDestory(SeqQue *seqque)
{
	queueClear(seqque);
	free(seqque);
}

int getQueueLen(SeqQue *seqque)
{
	return (seqque->rear - seqque->front+(seqque->max))%(seqque->max); 
}

SeqQue *dil_queue(SeqQue *seqque,int n)
{
	seqque = realloc(seqque,sizeof(seqque)+(seqque->max));
	seqque->max = n*BASEQUEUESIZE;
	return seqque;
}
