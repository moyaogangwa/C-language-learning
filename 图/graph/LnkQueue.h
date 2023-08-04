#ifndef __LNKQUEUE_H__
#define __LNKQUEUE_H__

// ���н��ṹ��
typedef int QElemType;
typedef struct queuenode
{
    QElemType data;
    struct queuenode *next;
}LnkQnode;

// ���� ͷ�ṹ��
typedef struct queue
{
    LnkQnode *front;		// ָ����е�ͷ��
    LnkQnode *rear;			// ָ����е�β��
    int num;				// ������еĽ����
}LnkQueue;

/*
	initQueue����ʼ��һ������
	
	����ֵ��
		���ض���ָ��
*/
LnkQueue *initQueue();

/*
	EnQueue�����
		Queue������ָ�룬ָ��һ������
		x����Ҫ��ӵ�Ԫ��
	����ֵ��
	
*/
void enQueue(LnkQueue *Queue, QElemType x);

/*
	delQueue������
		Queue������ָ�룬ָ��һ������
	����ֵ��
		���س���Ԫ�ص�������
*/
QElemType delQueue(LnkQueue *Queue);

/*
	getFront����ȡ��ͷԪ��
		Queue������ָ�룬ָ��һ������
	����ֵ��
		���ض�ͷԪ�ؽ���ַ
		����Ϊ�գ�����NULL
*/
LnkQnode *getFront(LnkQueue *Queue);

/*
	queueIsEmpty���ж϶����Ƿ�Ϊ��
		Queue������ָ�룬ָ��һ������
	����ֵ��
		���ض���Ԫ�ظ���
*/
int queueIsEmpty(LnkQueue *Queue);

/*
	queueClear:���һ����
		Queue������ָ�룬ָ��һ������
	����ֵ��	
	
*/
void queueClear(LnkQueue *Queue);

/*
	queueDestory������һ������
		Queue������ָ�룬ָ��һ������
	����ֵ��
	
*/
void queueDestory(LnkQueue *Queue);

#endif /* LnkQueue.h */