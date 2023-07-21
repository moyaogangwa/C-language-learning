//实现旋转一个双向链表

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
	static Binode *end = NULL;
	if(NULL==*list)
		*list=new;
	else
	{
		end->next=new;
		new->prev=end;
	}
	end=new;
}

Binode *createbilist()
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
	return first;
}

void roundlist(Binode **list,int k)
{
	if(NULL==*list)
		return;
	Binode *end = *list;
	
	while(end->next)
	{
		end=end->next;
	}
	while(k--)
	{
		end->next=*list;
		(*list)->prev=end;
		(*list)=end;
		end->prev->next=NULL;
		end=end->prev;
		(*list)->prev=NULL;
	}
}

void printbilist(Binode *pp)
{
	Binode *p = NULL;
	while(pp)
	{
		printf("%d ",pp->data);
		p=pp;
		pp=pp->next;
	}
	printf("\n");
	while(p)
	{
		printf("%d ",p->data);
		p=p->prev;
	}
	printf("\n");
}

void deslist(Binode *pd)
{
	Binode *p = NULL;
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
	Binode *list=createbilist();
	int k = 0;
	printbilist(list);
	scanf("%d",&k);
	roundlist(&list,k);
	printbilist(list);
	deslist(list);
	return 0;
}

