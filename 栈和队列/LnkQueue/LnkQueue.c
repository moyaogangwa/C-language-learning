#include "LnkQueue.h"
#include "stdlib.h"



LnkQue *InitQue()
{
	LnkQue *que = malloc(sizeof(LnkQue));
	que->front = que->rear = NULL;
	que->num = 0;
	return que;
}

void EnQueue(LnkQue *que,QElemType x)
{
	LnkQNode *qnode = malloc(sizeof(LnkQNode));
	qnode->data = x;
	qnode->next = NULL;
	if( GetQueNum(que) )
	{
		que->rear->next=qnode;
		que->rear=qnode;
	}
	else
		que->front=que->rear=qnode;
	que->num++;
}

QElemType DelQueue(LnkQue *que)
{
	LnkQNode *p = que->front;
	QElemType x = -1;
	if( GetQueNum(que) )
	{
		que->front=que->front->next;
		x=p->data;
		p->next=NULL;
		free(p);
		que->num--;
	}
	return x;
}

LnkQNode *GetFront(LnkQue *que)
{
	return que->front;
}

int GetQueNum(LnkQue *que)
{
	return que->num;
}

void QueClear(LnkQue *que)
{
	while( GetQueNum(que) )
		DelQueue(que);
}

void QueDsetory(LnkQue *que)
{
	QueClear(que);
	free(que);
}