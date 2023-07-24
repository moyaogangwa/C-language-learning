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
	int leisure;
	Phnode *first;
	Phnode *last;
}Phmanage;

Phmanage *magnode;

char rootword[12] = "123456789";

void createphnode(Phnode **new,char *num)
{
	*new=malloc(sizeof(Phnode));
	strcpy((*new)->number,num);
	(*new)->status=0;
	(*new)->next=NULL;
	(*new)->prev=NULL;
}

void addphnode(Phnode *new)
{
	if(NULL==magnode->first)
		magnode->first=new;
	else
	{
		magnode->last->next=new;
		new->prev=magnode->last;
	}
	magnode->last=new;
	magnode->num++;
	magnode->leisure++;
}

void createphlist()
{
	char number[12]={0};
	Phnode *new = NULL;
	while(1)
	{
		scanf("%s",number);
		if('#'==number[0])
		{
			printf("input ok!\n");
			break;
		}
		createphnode(&new,number);
		addphnode(new);
	}
}

int occupynum(char *nb)
{
	Phnode *pf = magnode->first;
	while(pf)
	{
		if((0==strcmp(pf->number,nb))&&(0==pf->status))
		{
			pf->status=1;
			magnode->leisure--;
			return 1;
		}
		else
			pf=pf->next;
	}
	return 0;
}

void choosenum()
{
	char nb[12]={0};
	Phnode *pp=magnode->first;
	int ret = 0;
	while(pp)
	{
		if(0==pp->status)
			printf("Number:%s\n",pp->number);
		pp=pp->next;
	}
	printf("please choose:>");
	scanf("%s",nb);
	if(nb[0]=='#')
		return;
	ret=occupynum(nb);
	if(0==ret)
		printf("no find!\n");
	else
		printf("ok!\n");
}

void delnum()
{
	char deldata[12] = {0};
	Phnode *pf = NULL;
	printf("please input('#'exit):>\n");
	while(1)
	{
		pf = magnode->first;
		scanf("%s",deldata);
		if(deldata[0]=='#')
			return;
		while(pf)
		{
			if((0==strcmp(pf->number,deldata)))
			{
				if((pf->next)&&(pf->prev))
				{
					pf->next->prev=pf->prev;
					pf->prev->next=pf->next;
					pf->prev=NULL;
					pf->next=NULL;
				}
				else if(pf->next)
				{
					pf->next->prev=pf->prev;
					magnode->first=pf->next;
					pf->next=NULL;
				}
				else
				{
					pf->prev->next=pf->next;
					pf->prev=NULL;
				}
				if((pf->status)==0)
					magnode->leisure--;
				free(pf);
				break;
			}
			else
				pf=pf->next;
		}
		magnode->num--;
	}
}

void release()
{
	char reldata[12] = {0};
	Phnode *pf = NULL;
	printf("please input('#'exit):>\n");
	while(1)
	{
		pf = magnode->first;
		scanf("%s",reldata);
		if(reldata[0]=='#')
			return;
		while(pf)
		{
			if((0==strcmp(pf->number,reldata))&&(1==pf->status))
			{
				pf->status=0;
				magnode->leisure++;
			}
			else
				pf=pf->next;
		}
	}
}

void look_uplei()
{
	printf("leisure number:%d\n",magnode->leisure);
}

void initlist()
{
	Phnode *pf = magnode->first;
	while(pf)
	{
		if(1==pf->status)
			magnode->leisure++;
		pf->status=0;
		pf=pf->next;
	}
}

void deslist()
{
	Phnode *pd = magnode->first;
	Phnode *p = NULL;
	while(pd)
	{
		p=pd;
		pd=pd->next;
		p->next=NULL;
		p->prev=NULL;
	}
	magnode=NULL;
	free(magnode);
}

void rootmenu()
{
	while(1)
	{
		int input = 0;
		printf("***********rootmenu***********\n");
		printf("******1.addnum  2.delnum******\n");
		printf("******3.release 4.look_uplei**\n");
		printf("******7.init    9.destroy*****\n");
		printf("************0.exit************\n");
		printf("please choose:>");
		scanf("%d",&input);
		switch(input)
		{
			case 1:
				createphlist();
				break;
			case 2:
				delnum();
				break;
			case 3:
				release();
				break;
			case 4:
				look_uplei();
				break;
			case 7:
				initlist();
				break;
			case 9:
				deslist();
				break;
			case 0:
				return;
			default:
				printf("error\n");
		}
	}
}

void log_root()
{
	char password[12]={0};
	int ret = 0;
	printf("please input password:>");
	scanf("%s",password);
	ret=strcmp(password,rootword);
	if(0==ret)
	{
		printf("log ok!\n");
		rootmenu();
	}
	else
	{
		printf("input error!\n");
		return;
	}
}

void menu()
{
	while(1)
	{
		int input = 0;
		printf("***************Phonenum***************\n");
		printf("*******1.choosenum  2.log root********\n");
		printf("**************************************\n");
		printf("please choose:>");
		scanf("%d",&input);
		switch(input)
		{
			case 1:
				choosenum();
				break;
			case 2:
				log_root();
				break;
			default:
				printf("error\n");
			
		}
	}
}

int main()
{
	char* result = NULL;
	magnode = malloc(sizeof(Phmanage));
	menu();
	choosenum();
	return 0;
}

