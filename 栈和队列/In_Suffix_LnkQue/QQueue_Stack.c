#include "QQueue_Stack.h"


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



//Ë³ÐòÕ»

SeqStack *InitSeqStack(int n)
{
	SeqStack *seqstk = malloc(sizeof(SeqStack)+n*BASESTACKSIZE);
	seqstk->top=-1;
	seqstk->size=n*BASESTACKSIZE;
	seqstk->num=0;
	memset(seqstk->stack,0,n*BASESTACKSIZE);
	return seqstk;
}

void Push(SeqStack *seqstk,int x)
{
	if(seqstk->num!=seqstk->size)
	{
		seqstk->top++;
		seqstk->stack[seqstk->top]=x;
		seqstk->num++;
	}
}

StackElemtype Pop(SeqStack *seqstk)
{
	if(seqstk->num!=0)
	{
		StackElemtype x = seqstk->stack[seqstk->top];
		seqstk->stack[seqstk->top]=0;
		seqstk->top--;
		seqstk->num--;
		return x;
	}
	return -1;
}

StackElemtype getTop(SeqStack *seqstack)
{
	return (seqstack->stack)[seqstack->top];
}

void ClearStack(SeqStack *seqstack)
{
	while(seqstack->num)
		Pop(seqstack);
}

void DesStack(SeqStack *seqstack)
{
	ClearStack(seqstack);
	free(seqstack);
}

SeqStack *dil_stack(SeqStack *seqstack,int n)
{
	seqstack = realloc(seqstack,sizeof(SeqStack)+n*BASESTACKSIZE);
	seqstack->size = n*BASESTACKSIZE;
	return seqstack;
}