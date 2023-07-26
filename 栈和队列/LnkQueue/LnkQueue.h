#ifndef __LNKQUEUE_H__
#define __LNKQUEUE_H__ 1

//��������
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


//��������

/*
	InitQue:��ʼ������
		����ֵ��
			����һ�����еĵ�ַ
*/
LnkQue *InitQue();

/*
	EnQueue�����
		�βΣ�
			que:����ָ�룬ָ��һ������
			x:��ӵ�Ԫ��
*/
void EnQueue(LnkQue *que,QElemType x);

/*
	DelQueue������
		�βΣ�
			que:����ָ�룬ָ��һ������
		����ֵ��
			���س���Ԫ�ص�������
*/
QElemType DelQueue(LnkQue *que);

/*
	GetFront����ȡ��ͷԪ�صĵ�ַ
		�βΣ�
			que:����ָ�룬ָ��һ������
		����ֵ��
			���ض�ͷԪ�صĵ�ַ
*/
LnkQNode *GetFront(LnkQue *que);

/*
	GetQueNum����ȡ����Ԫ�ظ���
		�βΣ�
			que:����ָ�룬ָ��һ������
		����ֵ��
			���ض���Ԫ�ظ���
*/
int GetQueNum(LnkQue *que);

/*
	QueClear���������Ԫ��
		�βΣ�
			que:����ָ�룬ָ��һ������
*/
void QueClear(LnkQue *que);

/*
	QueDsetory�����ٶ���
	�βΣ�
		que:����ָ�룬ָ��һ������
*/
void QueDsetory(LnkQue *que);



#endif     //LnkQueue.h