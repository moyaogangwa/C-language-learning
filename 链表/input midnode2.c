//快慢指针实现输出中间节点

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
	*new=malloc(sizeof(Node));
	(*new)->data=data;
	(*new)->next=NULL;
}

void addnode(Node **list,Node *new)
{
	static Node *end = NULL;
	if(NULL==*list)
		*list=new;
	else
		end->next=new;
	end=new;
}

void printlist(Node *pp)
{
	while(pp)
	{
		printf("%d ",pp->data);
		pp=pp->next;
	}
	printf("\n");
}

void findmidnode(Node *list)
{
	Node *pf = list;
	Node *pl = list;
	int n = 0;
	while(pf)
	{
		pf=pf->next;
		n++;
		if(0==n%2)
			pl=pl->next;
	}
	printf("%d\n",pl->data);
}

void deslist(Node *pd)
{
	Node *p = NULL;
	while(pd)
	{
		p=pd;
		pd=pd->next;
		p->next=NULL;
		free(p);
	}
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
	findmidnode(first);
	deslist(first);
}

