//递归实现寻找单链表倒数第K个节点

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

void *findlist_knode(Node *list,int k)
{
	static int n = 0;
	if(list)
	{
		
		Node *pf=findlist_knode(list->next,k);
		n++;
		if(n==k)
			return list;
		else
			return pf;
	}
	else
		return NULL;
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
	Node *pf = NULL;
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
	scanf("%d",&k);
	pf=findlist_knode(first,k);
	printf("%d\n",pf->data);
	deslist(first);
	return 0;
}

