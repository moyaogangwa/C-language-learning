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
	if(NULL==*bitree)
		*bitree=newtnode;
	else
	{
		while(1)
		{
			if(bitnode->data>newtnode->data)
			{
				if(NULL==bitnode->lchild)
				{
					bitnode->lchild=newtnode;
					break;
				}
				bitnode=bitnode->lchild;
			}
			else if(bitnode->data<newtnode->data)
			{
				if(NULL==bitnode->rchild)
				{
					bitnode->rchild=newtnode;
					break;
				}
				bitnode=bitnode->rchild;
			}
			else
			{
				free(newtnode);
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

void preprint(LnkBiTree *bitree)
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

void posprint(LnkBiTree *bitree)
{
	if(NULL==bitree)
		return;
	
	LnkBiTree *t = bitree;
	LnkStack *stk1= initStack();
	LnkStack *stk2= initStack();
	Push(stk1,t);
	while(stk1->top)
	{
		t=Pop(stk1);
		if(t->lchild)
			Push(stk1,t->lchild);
		if(t->rchild)
			Push(stk1,t->rchild);
		Push(stk2,t);
	}
	while(stk2->top)
		printf("%d ",Pop(stk2)->data);
	printf("\n");
}



void destroytree(LnkBiTree **bitree)
{
	if ( *bitree == NULL )
		return ;
	LnkBiTree *l = (*bitree)->lchild;
	LnkBiTree *r = (*bitree)->rchild;
	
	// 先销毁根结点 -- 销毁之前需要保留根的左子树和右子树的地址
	free(*bitree);
	*bitree=NULL;
	// 再按照销毁树的规则去销毁根的左子树
	destroytree(&l);
	//再按照销毁树的规则去销毁根的右子树
	destroytree(&r);
	
}






