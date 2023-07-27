#include <stdio.h>
#include "QQueue.h"



int main()
{
	SeqQue *seqque = InitSeqQue(1);
	int x = 0;
	while(1)
	{
		scanf("%d",&x);
		if(0==x)
			break;
		Push(seqque,x);
	}
	while(queueIsEmpty(seqque))
			printf("%d ",Pop(seqque));
	return 0;
}