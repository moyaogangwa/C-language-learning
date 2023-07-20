//头插法实现双向链表

#include <stdio.h>
#include <stdlib.h>

typedef int Elemtype;

struct binode
{
	Elemtype data;
	struct binode *next;
	struct binode *prev;
};
typedef struct binode Binode;

void createbinode(Binode **new,Elemtype data)
{
	*new=malloc(sizeof(Binode));
	(*new)->data=data;
	(*new)->next=NULL;
	(*new)->prev=NULL;
}

void addbinode(Binode **list,Binode *new)
{
	if(NULL==*list)
	{
		*list=new;
	}
	else
	{
		new->next=*list;
		(*list)->prev=new;
		*list=new;
	}
}

void printbilist(Binode *first)
{
	Binode *pn = first;
	Binode *pr = NULL;
	while(pn)
	{
		printf("%d ",pn->data);
		pr=pn;
		pn=pn->next;
	}
	printf("\n");
	while(pr)
	{
		printf("%d ",pr->data);
		pr=pr->prev;
	}
	printf("\n");
}

void deslist(Binode *pd)
{
	Binode *p=NULL;
	while(pd)
	{
		p=pd;
		pd=pd->next;
		p->next=NULL;
		p->prev=NULL;
		free(p);
		
	}
}

int main()
{
	Elemtype data = 0;
	Binode *first = NULL;
	Binode *new = NULL;
	while(1)
	{
		scanf("%d",&data);
		if(0==data)
		{
			printf("input ok!\n");
			break;
		}
		createbinode(&new,data);
		addbinode(&first,new);
	}
	printbilist(first);
	deslist(first);
	return 0;
}


