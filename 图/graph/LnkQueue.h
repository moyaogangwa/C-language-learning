#ifndef __LNKQUEUE_H__
#define __LNKQUEUE_H__

// 队列结点结构体
typedef int QElemType;
typedef struct queuenode
{
    QElemType data;
    struct queuenode *next;
}LnkQnode;

// 队列 头结构体
typedef struct queue
{
    LnkQnode *front;		// 指向队列的头部
    LnkQnode *rear;			// 指向队列的尾部
    int num;				// 保存队列的结点数
}LnkQueue;

/*
	initQueue：初始化一个队列
	
	返回值：
		返回队列指针
*/
LnkQueue *initQueue();

/*
	EnQueue：入队
		Queue：队列指针，指向一个队列
		x：将要入队的元素
	返回值：
	
*/
void enQueue(LnkQueue *Queue, QElemType x);

/*
	delQueue：出队
		Queue：队列指针，指向一个队列
	返回值：
		返回出队元素的数据域
*/
QElemType delQueue(LnkQueue *Queue);

/*
	getFront：获取队头元素
		Queue：队列指针，指向一个队列
	返回值：
		返回队头元素结点地址
		队列为空，返回NULL
*/
LnkQnode *getFront(LnkQueue *Queue);

/*
	queueIsEmpty：判断队列是否为空
		Queue：队列指针，指向一个队列
	返回值：
		返回队中元素个数
*/
int queueIsEmpty(LnkQueue *Queue);

/*
	queueClear:清空一个队
		Queue：队列指针，指向一个队列
	返回值：	
	
*/
void queueClear(LnkQueue *Queue);

/*
	queueDestory：销毁一个队列
		Queue：队列指针，指向一个队列
	返回值：
	
*/
void queueDestory(LnkQueue *Queue);

#endif /* LnkQueue.h */