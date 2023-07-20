//改良版合并有序链表
 
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

void *printlist(Node *pp)
{
	while(pp)
	{
		printf("%d ",pp->data);
		pp=pp->next;
	}
	printf("\n");
}

void* combinelist(Node *list1,Node *list2,Node *list3)
{
	if(NULL==list1)
		return list2;
	else if(NULL==list2)
		return list1;
	
	Node *end = NULL;
	
	while(list1&&list2)
	{
		if(list1->data<list2->data)
		{
			if(NULL==list3)
			{
				list3=list1;
				end=list1;
			}
			else
			{
				end->next=list1;
				end=list1;
			}
			list1=list1->next;
			end->next=NULL;
		}
		else
		{
			if(NULL==list3)
			{
				list3=list2;
				end=list2;
			}
			else
			{
				end->next=list2;
				end=list2;
			}
			list2=list2->next;
			end->next=NULL;
		}
	}
	end->next=(list1?list1:list2);
	return list3;
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
	Node *first1 = NULL;
	Node *first2 = NULL;
	Node *first3 = NULL;
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
		addnode(&first1,new);
	}
	while(1)
	{
		scanf("%d",&data);
		if(0==data)
		{
			printf("input ok!\n");
			break;
		}
		createnode(&new,data);
		addnode(&first2,new);
	}
	
	first3=combinelist(first1,first2,first3);
	printlist(first3);
	deslist(first3);
	
	return 0;
}

