//快慢指针实现寻找单链表倒数第K个节点

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
	(*new)->data=data;
	(*new)->next=NULL; 
}

void addnode(Node **list,Node *new)
{
	static Node *end = NULL;
	if(NULL==*list)
		*list = new;
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

void findlist_knode(Node *first,int k)
{
	if(NULL==first)
		return NULL;
	Node *pf=first;
	Node *pl=first;
	while(pf)
	{
		pf=pf->next;
		k--;
		if(k<0)
			pl=pl->next;
	}
	printf("node:\nvalue:%d\n",pl->data);
}

void deslist(Node *pd)
{
	if(NULL!=pd->next)
		deslist(pd->next);
	pd->next=NULL;
	free(pd);
}

int main()
{
	Elemtype data = 0;
	Node *first = NULL;
	Node *new = NULL;
	int k = 0;
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
	printf("please input(k):>");
	scanf("%d",&k);
	findlist_knode(first,k);
	deslist(first);
	
	return 0;
}

