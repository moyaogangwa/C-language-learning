#include "SeqStack.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

SeqStack *InitSeqStack(int n)
{
	SeqStack *seqstack=malloc(sizeof(SeqStack)+n*BASESTACKSIZE);
	seqstack->top=-1;
	seqstack->size=n*BASESTACKSIZE;
	memset(seqstack->stack,0,n*BASESTACKSIZE);
	return seqstack;
}

void Push(SeqStack *seqstack,StackElemtype n)
{
	seqstack->top++;
	seqstack->stack[seqstack->top]=n;
	seqstack->num++;
}

int Pop(SeqStack *seqstack)
{
	int n = seqstack->stack[seqstack->top];
	seqstack->stack[seqstack->top]=0;
	seqstack->top--;
	seqstack->num--;
	return n;
}

int getTop(SeqStack *seqstack)
{
	return seqstack->top;
}

void ClearStack(SeqStack *seqstack)
{
	while(seqstack->num)
		Pop(seqstack);
}

void DesStack(SeqStack *seqstack)
{
	ClearStack(seqstack);
	free(seqstack);
}

SeqStack *kuorong(SeqStack *seqstack,int n)
{
	seqstack = realloc(seqstack,sizeof(SeqStack)+n*BASESTACKSIZE);
	seqstack->size = n*BASESTACKSIZE;
	return seqstack;
}