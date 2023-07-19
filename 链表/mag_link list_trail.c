//头插法实现管理节点

#include <stdio.h>
#include <stdlib.h>

typedef int Elemtype;

struct node
{
	Elemtype data;
	struct node* next;
};

typedef struct node Node;

typedef struct managenode
{
	int nodenum;
	Node *first;
	Node *last;
}manage;

manage *createmag()
{
	manage *mag = (manage *)malloc(sizeof(manage));
	mag->nodenum=0;
	mag->first=NULL;
	mag->last=NULL;
	return mag;
}

void createnode(Node **new,Elemtype data)
{
	*new = (Node *)malloc(sizeof(Node));
	(*new)->data = data;
	(*new)->next = NULL;
}

void addnode(manage *mag,Node *new)
{
	if(mag->nodenum==0)
	{
		mag->first=new;
		mag->last=new;
	}
	else
	{
		new->next=mag->first;
		mag->first=new;
	}
	(mag->nodenum)++;
}

void printlist(Node *first)
{
	Node *pp=first;
	if(pp->next!=NULL)
	{
		printlist(pp->next);
	}
	printf("%d ",pp->data);
}

void deslist(Node *pd)
{
	if(pd->next!=NULL)
	{
		deslist(pd->next);
	}
	pd->next=NULL;
	free(pd);
}

void delmagnode(manage *mag,Elemtype dnode)
{
	Node *pd = mag->first;
	Node *pre = mag->first;
	while(pd)
	{
		if((pd->data)==dnode)
		{
			if(pd==(mag->first))
			{
				mag->first=mag->first->next;
				free(pd);
				pd=mag->first;
			}
			else if((pd->next)==NULL)
			{
				free(pd);
				pd=pre;
				pd->next=NULL;
			}
			else
			{
				pre->next=pd->next;
				free(pd);
				pd=pre->next;
			}
		}
		else
		{
			pre=pd;
			pd=pre->next;
		}
	}
}

int main()
{
	Elemtype data = 0;
	Node *new = NULL;
	Elemtype dnode = 0;
	manage *magnode = createmag();
	while(1)
	{
		scanf("%d",&data);
		if(0==data)
		{
			printf("input ok!\n");
			break;
		}
		createnode(&new,data);
		addnode(magnode,new);
	}
	printf("num:%d\n",(magnode->nodenum));
	printlist(magnode->first);
	printf("\n");
	scanf("%d",&dnode);
	delmagnode(magnode,dnode);
	printlist(magnode->first);
	printf("\n");
	deslist(magnode->first);
	free(magnode);
	return 0;
}

