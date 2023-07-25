#include <stdio.h>
#include "LnkStack.h"


int main()
{
	LnkStack *stack = initStack();
	StackElemType data = 0;
	while(1)
	{
		scanf("%d",&data);
		if(0==data)
		{
			printf("push ok!\n");
			break;
		}
		Push(stack,data);
	}
	printf("get top:%d num:%d\n",getTop(stack)->data,stack->num);
	while(stackIsEmpty(stack))
	{
		data=Pop(stack);
		printf("data:%d num:%d\n",data,stack->num);
	}
	printf("\n");
	DesStack(stack);
	return 0;
}