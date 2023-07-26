#include <stdio.h>
#include "LnkQueue.h"


int main()
{
	LnkQue *que = InitQue();
	QElemType x = 0;
	EnQueue(que,1);
	EnQueue(que,2);
	printf("%d\n",GetFront(que)->data);
	EnQueue(que,3);
	EnQueue(que,4);
	printf("%d\n",GetFront(que)->data);
	while( GetQueNum(que) )
	{
		x=DelQueue(que);
		printf("%d\n",x);
	}
	QueDsetory(que);
	return 0;
}