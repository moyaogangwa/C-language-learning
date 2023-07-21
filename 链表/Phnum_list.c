//电话目录管理系统

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct phonenode
{
	char number[12];
	int status;
	struct phonenode *next;
	struct phonenode *prev;
};
typedef struct phonenode Phnode;

typedef struct phmanage
{
	int num;
	int kx;
	Phnode *first;
	Phnode *last;
}Phmanage;

void createphnode(Phnode **new,char *num)
{
	*new=malloc(sizeof(Phnode));
	strcpy((*new)->number,num);
	(*new)->status=0;
	(*new)->next=NULL;
	(*new)->prev=NULL;
}

void addphnode(Phmanage *mag,Phnode *new)
{
	if(NULL==mag->first)
		mag->first=new;
	else
	{
		mag->last->next=new;
		new->prev=mag->last;
	}
	mag->last=new;
	mag->num++;
	mag->kx++;
}

Phmanage *createphlist()
{
	char number[12]={0};
	Phnode *new = NULL;
	static Phmanage *magnode = malloc(sizeof(Phmanage));
	while(1)
	{
		scanf("%s",number);
		if('#'==number[0])
		{
			printf("input ok!\n");
			break;
		}
		createphnode(&new,number);
		addphnode(magnode,new);
	}
	return magnode;
}

int findnum(Phmanage *mag,char *nb)
{
	Phnode *pf = mag->first;
	while(pf)
	{
		if((0==strcmp(pf->number,nb))&&(0==pf->status))
		{
			pf->status=1;
			mag->kx--;
			return 1;
		}
		else
			pf=pf->next;
	}
	return 0;
}

void choosenum(Phmanage *mag)
{
	char nb[12]={0};
	Phnode *pp=mag->first;
	int ret = 0;
	while(pp)
	{
		if(0==pp->status)
			printf("Number:%s\n",pp->number);
		pp=pp->next;
	}
	printf("please choose:>");
	scanf("%s",nb);
	ret=findnum(mag,nb);
	if(0==ret)
		printf("no find!\n");
	else
		printf("ok!\n");
}


int main()
{
	char* result = NULL;
	Phmanage *phlist=createphlist();
	choosenum(phlist);
	return 0;
}

