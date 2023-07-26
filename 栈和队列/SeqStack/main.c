#include <stdio.h>
#include "SeqStack.h"


int main()
{
	SeqStack *seqstack = InitSeqStack(1);
	StackElemtype data = 0;
	Push(seqstack,1);
	Push(seqstack,2);
	Push(seqstack,3);
	printf("%d\n",(seqstack->stack)[getTop(seqstack)]);
	while(seqstack->num)
	{
		data=Pop(seqstack);
		printf("%d\n",data);
	}
	printf("size:%d\n",seqstack->size);
	seqstack = kuorong(seqstack,2);
	printf("size:%d\n",seqstack->size);
	DesStack(seqstack);
	return 0;
}