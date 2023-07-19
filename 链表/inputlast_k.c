/*
返回一个链表中倒数第K个结点
*/

#include <stdio.h>
#include <stdlib.h>

typedef int Elemtype;

struct node
{
	Elemtype data;
	struct node *next;
};
typedef struct node Node;

typedef struct
{
	int nodenum;
	Node *first;
	Node *last;
}manage;

manage *createmag()
{
	manage *mag = malloc(sizeof(manage));
	mag->nodenum=0;
	mag->first=NULL;
	mag->last=NULL;
	return mag;
}

void createnode(Node **new,Elemtype data)
{
	if(data)
	{
		*new=malloc(sizeof(Node));
		(*new)->data=data;
		(*new)->next=NULL;
	}
}

void addnode(manage *mag,Node *new)
{
	
	if(NULL==mag->first)
		mag->first = new;
	else
		mag->last->next = new;
	mag->last = new;
	(mag->nodenum)++;
}


void printlist(manage *mag)
{
	Node *pp = mag->first;
	while(pp)
	{
		printf("%d ",pp->data);
		pp=pp->next;
	}
	printf("\n");
}

void deslist(Node *pd)
{
	if(NULL!=pd->next)
	{
		deslist(pd->next);
	}
	pd->next=NULL;
	free(pd);
}

void outputnode(manage *mag,int k)
{
	Node *p = mag->first;
	void *pt = NULL;
	int n = (mag->nodenum)-k;
	while(n--)
	{	
		pt=p;
		p=p->next;
	}
	printf("node:\nvalue:%d\nsite:%p\n",p->data,p);
}

int main()
{
	Elemtype data = 0;
	Node *new = NULL;
	int K = 0;
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
	
	printlist(magnode);
	scanf("%d",&K);
	outputnode(magnode,K);
	deslist(magnode->first);
	free(magnode);
	return 0;
}
 
 
 