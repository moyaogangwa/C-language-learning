//尾插法实现单链表

#include <stdio.h>
#include <stdlib.h>

typedef int Elemtype;

struct node
{
	Elemtype data;
	//指向下一个数据元素
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
	static Node *end = NULL;
	if(NULL==*list)
	{
		*list = new;
		end = *list;
	}
	else
	{
		end->next = new;
		end = new;
	}
}

void printlist(Node *first)
{
	Node *p = first;
	while(p)
	{
		printf("%d ",p->data);
		p=p->next;
	}
	printf("\n");
}

void deslist(Node *pd)
{
	if(NULL!=(pd->next))
	{
		deslist(pd->next);
	}
	pd->next=NULL;
	free(pd);
}

int main()
{
	Elemtype data = 0;
	Node *first = NULL;
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
		addnode(&first,new);
	}
	printlist(first);
	deslist(first);
	return 0;
}


