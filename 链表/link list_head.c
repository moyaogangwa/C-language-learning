//头插法实现单链表
 
#include <stdio.h>
#include <stdlib.h>
 
typedef int Elemtype;
 
struct node
{
	Elemtype data;
	struct node *next;
};
typedef struct node Node;
 
void createnode(Node **new,Elemtype data)
{
	*new = malloc(sizeof(Node));
	(*new)->data = data;
	(*new)->next = NULL;
}

void addnode(Node **list,Node *new)
{
	if(NULL == *list)
	{
		*list = new;
	}
	else
	{
		new->next = *list;
		*list = new;
	}
}

void printanddes(Node *pd)
{
	if(NULL!=pd->next)
	{
		printanddes(pd->next);
	}
	printf("%d ",pd->data);
	pd->next = NULL;
	free(pd);
	
}


int main()
{
	Elemtype data = 0;
	Node *end = NULL;
	Node *new = NULL;
	while(1)
	{
		scanf("%d",&data);
		if(0==data)
		{
			printf("input ok!\n");
			break;
		}
		createnode(&new,data);
		addnode(&end,new);
	}
	printanddes(end);
	printf("\n");
	return 0;
}


