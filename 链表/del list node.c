//删除列表中的节点
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

void addnode(Node **list,Node *new)
{
	static Node *end = NULL;
	if(NULL==*list)
	{
		*list=new;
		end=*list;
	}
	else
	{
		end->next=new;
		end=new;
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

void delnode(Node **list,Elemtype node)
{
	Node *pre = *list;
	Node *p = *list;
	while(p)
	{
		if(node==(p->data))
		{
			if(p==*list)
			{
				*list=(*list)->next;
				free(p);
				p=*list;
			}
			else if(p->next==NULL)
			{
				free(p);
				p=pre;
				p->next=NULL;
			}
			else
			{
				pre->next=p->next;
				free(p);
				p=pre->next;
			}
		}
		else
		{
			pre=p;
			p=pre->next;
		}
	}
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
	Elemtype dnode = 0;
	
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
	scanf("%d",&dnode);
	delnode(&first,dnode);
	printlist(first);
	deslist(first);
	return 0;
}


