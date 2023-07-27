#include <stdio.h>
#include "QQueue_Stack.h"
#include "Suffix.h"


int main()
{
	int result = 0;
	/*SeqStack *stack = InitSeqStack(1);
	SeqQue *seqque = InitSeqQue(1);*/
	char expression[100] = {0};
	gets(expression);
	result=get_value(expression);
	printf("result:%d\n",result);
	/*Push(stack,1);
	Push(stack,2);
	printf("%d\n",Pop(stack));
	DesStack(stack);
	enQueue(seqque,1);
	enQueue(seqque,2);
	printf("%d\n",delQueue(seqque));
	queueDestory(seqque);*/
	return 0;
}

