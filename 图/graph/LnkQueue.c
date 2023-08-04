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
	// ��x ��װ�ɽ��
	LnkQnode *QNode = malloc(sizeof(*QNode));
	QNode->data = x;
	QNode->next = NULL;
	
	// ��Ϊ�� ��β��
	if( queueIsEmpty(Queue) )
	{
		Queue->rear->next = QNode;
		Queue->rear = QNode;
	}
	else // Ϊ��
		Queue->front = Queue->rear = QNode;
	
	Queue->num++;
}

QElemType delQueue(LnkQueue *Queue)
{
	QElemType data = -1;
	LnkQnode *p = Queue->front;
	if ( queueIsEmpty(Queue) )
	{
		// ����������
		data = Queue->front->data;
		
		// ͷɾ
		Queue->front = Queue->front->next;
		p->next = NULL;
		free(p);
		
		// ���ֻ��һ�����
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