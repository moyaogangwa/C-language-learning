/*
归并两个有序链表，要求归并后仍然有序
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
//有序添加节点
void addnode(manage *mag,Node *new)
{
	Node *pin = mag->first;
	int flag = 0;
	if(mag->first==NULL)
	{
		mag->first=new;
	}
	else
	{
		while(pin->data<=new->data)
		{
			flag=1;
			if(NULL==(pin->next) || (pin->next->data)>(new->data))
			{
				new->next=pin->next;
				pin->next=new;
				break;
			}
			else
				pin=pin->next;
		}
		if(flag==0)
		{
			new->next=mag->first;
			mag->first=new;
		}
	}
	(mag->nodenum)++;
}
//合并
manage *combinelist(manage *mag1,manage *mag2)
{
	if(mag1->first&&mag2->first)
	{
		Node *list1=mag1->first;
		Node *list2=mag2->first;
		Node *p = NULL;
		while(list2)
		{
			p=list2;
			list2=list2->next;
			mag2->first=list2;
			p->next=NULL;
			addnode(mag1,p);
		}
		return mag1;
		
	}
	else if(mag1->first)
			return mag1;
	return mag2;
}
//输出
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
//销毁
void deslist(Node *pd)
{
	if(NULL!=pd->next)
	{
		deslist(pd->next);
	}
	pd->next=NULL;
	free(pd);
}

int main()
{
	Elemtype data = 0;
	Node *new1 = NULL;
	Node *new2 = NULL;
	manage *magnode1 = createmag();
	manage *magnode2 = createmag();
	
	while(1)
	{
		scanf("%d",&data);
		if(0==data)
		{
			printf("input ok!\n");
			break;
		}
		createnode(&new1,data);
		addnode(magnode1,new1);
	}
	while(1)
	{
		scanf("%d",&data);
		if(0==data)
		{
			printf("input ok!\n");
			break;
		}
		createnode(&new2,data);
		addnode(magnode2,new2);
	}
	
	manage *maginput = combinelist(magnode1,magnode2); //接收合并后的链表地址
	printlist(maginput);
	deslist(maginput->first);
	free(magnode1);
	free(magnode2);
	return 0;
}
