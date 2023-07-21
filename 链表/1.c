
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

int Judge(Binode *list)
{
	if(NULL==list)
		return 0;
	else
		return 1;
}

int howlong(Binode *list)
{
	int n = 0;
	while(list)
	{
		n++;
		list=list->next;
	}
	return n;
}

void findnode_value(Binode *list,int x)
{
	Binode *pf = NULL;
	int flag = 0;
	while(list)
	{
		if(list->data==x)
		{
			pf=list;
			printf("node:%d\nsite:%p\n",x,pf);
			flag=1;
		}
		list=list->next;
	}
	if(0==flag)
		printf("no find\n");
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
	Binode *list = createbilist();
	int flag = 0 ,length = 0 ,x = 0;
	flag = Judge(list);
	length = howlong(list);
	scanf("%d",&x);
	printf("%d length:%d\n",flag,length);
	findnode_value(list,x);
	deslist(list);
	return 0;
}