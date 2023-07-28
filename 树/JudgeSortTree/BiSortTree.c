#include "BiSortTree.h"
#include "LnkStack.h"

LnkBiTree *createbitree()
{
	LnkBiTree *root = NULL;
	LnkBiTree *new = NULL;
	int data = 0;
	while(1)
	{
		scanf("%d",&data);
		if(0==data)
		{
			printf("input ok!\n");
			break;
		}
		createtnode(&new,data);
		addtnode(&root,new);
	}
	return root;
}

void createtnode(LnkBiTree **new,TElemType data)
{
	*new = malloc(sizeof(LnkBiTree));
	(*new)->data=data;
	(*new)->lchild=NULL;
	(*new)->rchild=NULL;
}

void addtnode(LnkBiTree **bitree,LnkBiTree *newtnode)
{
	LnkBiTree *bitnode = *bitree;
	int n = 0;
	if(NULL==*bitree)
		*bitree=newtnode;
	else
	{
		while(1)
		{
			if(NULL==bitnode->lchild)
			{
				bitnode->lchild=newtnode;
				break;
			}
			
			else if(NULL==bitnode->rchild)
			{
				bitnode->rchild=newtnode;
				break;
			}
		}
	}
}

void midprint(LnkBiTree *bitree)
{
	if(NULL==bitree)
		return;
	
	LnkBiTree *t = bitree;
	LnkBiTree *tt = bitree;
	
	LnkStack *stk= initStack();
	Push(stk,t);
	while(stk->top)
	{
		if(t->lchild)
		{
			Push(stk,t->lchild);
			t=t->lchild;
		}
		else
		{
			tt=Pop(stk);
			printf("%d ",tt->data);
			if(tt->rchild)
			{
				t=tt->rchild;
				Push(stk,t);
			}
		}
	}
	printf("\n");
}

void befprint(LnkBiTree *bitree)
{
	if(NULL==bitree)
		return;
	
	LnkBiTree *t = bitree;
	LnkStack *stk= initStack();
	
	printf("%d ",t->data);
	while(t->lchild||t->rchild||stk->top)
	{
		if(t->rchild)
			Push(stk, t);
		if(t->lchild)
			t=t->lchild;
		else
			t=Pop(stk)->rchild;
		printf("%d ",t->data);
	}
	printf("\n");
}

void aftprint(LnkBiTree *bitree)
{
	if(NULL==bitree)
		return;
	
	// ������������Ĺ�����ʸ���������
	midprint(bitree->lchild);
	// ������������Ĺ�����ʸ���������
	midprint(bitree->rchild);
	// ���ʸ����
	printf("%d ",bitree->data);
}


void JudgeSort(LnkBiTree *bitree)
{
	if(NULL==bitree)
		return;
	
	LnkBiTree *t = bitree;
	LnkBiTree *tt = bitree;
	
	LnkStack *stk= initStack();
	int pre = -1;
	Push(stk,t);
	while(stk->top)
	{
		if(t->lchild)
		{
			Push(stk,t->lchild);
			t=t->lchild;
		}
		else
		{
			tt=Pop(stk);
			if(-1!=pre&&pre>=tt->data)
			{
				printf("no!\n");
				return;
			}
			if(tt->rchild)
			{
				t=tt->rchild;
				Push(stk,t);
			}
			pre=tt->data;
		}
	}
	printf("yes!\n");
}


void destroytree(LnkBiTree **bitree)
{
	if ( *bitree == NULL )
		return ;
	LnkBiTree *l = (*bitree)->lchild;
	LnkBiTree *r = (*bitree)->rchild;
	
	// �����ٸ���� -- ����֮ǰ��Ҫ�����������������������ĵ�ַ
	free(*bitree);
	*bitree=NULL;
	// �ٰ����������Ĺ���ȥ���ٸ���������
	destroytree(&l);
	//�ٰ����������Ĺ���ȥ���ٸ���������
	destroytree(&r);
	
}






