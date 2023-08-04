#include "LnkQueue.h"
#include <stdlib.h>

LnkQueue *initQueue()
{
	LnkQueue *Queue = malloc(sizeof(*Queue));
	Queue->front = Queue->rear = NULL;
	Queue->num = 0;
	
	return Queue;
}

void enQueue(LnkQueue *Queue, QElemType x)
{
	// 将x 封装成结点
	LnkQnode *QNode = malloc(sizeof(*QNode));
	QNode->data = x;
	QNode->next = NULL;
	
	// 不为空 则尾插
	if( queueIsEmpty(Queue) )
	{
		Queue->rear->next = QNode;
		Queue->rear = QNode;
	}
	else // 为空
		Queue->front = Queue->rear = QNode;
	
	Queue->num++;
}

QElemType delQueue(LnkQueue *Queue)
{
	QElemType data = -1;
	LnkQnode *p = Queue->front;
	if ( queueIsEmpty(Queue) )
	{
		// 保存结点数据
		data = Queue->front->data;
		
		// 头删
		Queue->front = Queue->front->next;
		p->next = NULL;
		free(p);
		
		// 如果只有一个结点
		if ( Queue->front == NULL )
			Queue->rear = NULL;
		
		Queue->num--;
	}
	
	return data;
}

LnkQnode *getFront(LnkQueue *Queue)
{
	return Queue->front;
}

int queueIsEmpty(LnkQueue *Queue)
{
	return Queue->num;
}

void queueClear(LnkQueue *Queue)
{
	while( queueIsEmpty(Queue) )
		delQueue( Queue );
}


void queueDestory(LnkQueue *Queue)
{
	queueClear(Queue);
	free(Queue);
}