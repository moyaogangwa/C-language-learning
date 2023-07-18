//链表实现插入排序

#include <stdio.h>
#include <stdlib.h>

typedef int Elemtype;
struct node
{
	Elemtype data;
	struct node* next;
};

typedef struct node Node;


void createnode(Node **new,Elemtype data)
{
	*new = malloc(sizeof(Node));
	(*new)->data = data;
	(*new)->next = NULL;
}

void insertadd(Node **list,Node *new)
{
	Node *insert = *list;
	int flag = 0;
	if(NULL == *list)
	{
		*list = new;
	}
	else
	{
		while((insert->data)<=(new->data))
		{
			flag=1;
			if(NULL==(insert->next) || ((insert->next)->data)>(new->data))
			{
				new->next=insert->next;
				insert->next=new;
				break;
			}
			else
				insert=insert->next;
		}
		if(0==flag)
		{
			new->next=*list;
			*list=new;
		}
	}
}

void printlist(Node *first)
{
	Node *pp = first;
	while(pp)
	{
		printf("%d ",pp->data);
		pp=pp->next;
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
		insertadd(&first,new);
	}
	printlist(first);
	deslist(first);
	return 0;
}



