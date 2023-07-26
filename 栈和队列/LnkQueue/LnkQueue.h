#ifndef __LNKQUEUE_H__
#define __LNKQUEUE_H__ 1

//变量声明
typedef int QElemType;
typedef struct queuenode
{
	QElemType data;
	struct queuenode *next;
}LnkQNode;

typedef struct queue
{
	LnkQNode *front;
	LnkQNode *rear;
	int num;
}LnkQue;


//函数声明

/*
	InitQue:初始化队列
		返回值：
			返回一个队列的地址
*/
LnkQue *InitQue();

/*
	EnQueue：入队
		形参：
			que:队列指针，指向一个队列
			x:入队的元素
*/
void EnQueue(LnkQue *que,QElemType x);

/*
	DelQueue：出队
		形参：
			que:队列指针，指向一个队列
		返回值：
			返回出对元素的数据域
*/
QElemType DelQueue(LnkQue *que);

/*
	GetFront：获取队头元素的地址
		形参：
			que:队列指针，指向一个队列
		返回值：
			返回队头元素的地址
*/
LnkQNode *GetFront(LnkQue *que);

/*
	GetQueNum：获取队列元素个数
		形参：
			que:队列指针，指向一个队列
		返回值：
			返回队列元素个数
*/
int GetQueNum(LnkQue *que);

/*
	QueClear：清除队列元素
		形参：
			que:队列指针，指向一个队列
*/
void QueClear(LnkQue *que);

/*
	QueDsetory：销毁队列
	形参：
		que:队列指针，指向一个队列
*/
void QueDsetory(LnkQue *que);



#endif     //LnkQueue.h