//删除一个单链表中所有的重复元素，只保留一个

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
	static Node *end=NULL;
	if(NULL==*list)
		*list=new;
	else
		end->next=new;
	end=new;
}

Node *createlist()
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
	return first;
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

void des_renode(Node *list)
{
	Node *pl = list;
	Node *pr = list;
	Node *pre = list;
	while(pl)
	{
		pre=pl;
		pr=pl->next;
		while(pr)
		{
			if(pl->data==pr->data)
			{
				pre->next=pr->next;
				pr->next=NULL;
				free(pr);
				pr=pre->next;
			}
			else
			{
				pre=pr;
				pr=pr->next;
			}
		}
		pl=pl->next;
	}
	
}

Node * deslist(Node *pd)
{
	Node *p = NULL;
	while(pd)
	{
		p=pd;
		pd=pd->next;
		p->next=NULL;
		free(p);
	}
	return pd;
}

int main()
{
	Node *list=createlist();
	printlist(list);
	des_renode(list);
	printlist(list);
	list=deslist(list);
	return 0;
}

