#include "BiSortTree.h"
#include "LnkQueue.h"

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
	// 先按照中序遍历的规则访问根的左子树
	midprint(bitree->lchild);
	// 访问根结点
	printf("%d ",bitree->data);
	// 按照中序遍历的规则访问根的右子树
	midprint(bitree->rchild);
}

void befprint(LnkBiTree *bitree)
{
	if(NULL==bitree)
		return;
	
	// 访问根结点
	printf("%d ",bitree->data);
	// 按照中序遍历的规则访问根的左子树
	midprint(bitree->lchild);
	// 按照中序遍历的规则访问根的右子树
	midprint(bitree->rchild);
}



void aftprint(LnkBiTree *bitree)
{
	if(NULL==bitree)
		return;
	
	// 按照中序遍历的规则访问根的左子树
	midprint(bitree->lchild);
	// 按照中序遍历的规则访问根的右子树
	midprint(bitree->rchild);
	// 访问根结点
	printf("%d ",bitree->data);
}

void levelPrint(LnkBiTree* root)
{
	// 如果不是空树
	if (root)
	{
		LnkBiTree* t = NULL;
		LnkQueue* lq = initQueue();

		// 入队前先访问
		printf("%d ", root->data);
		printf("\n");
		// 入队根节点
		enQueue(lq, root);

		int temp = 0;

		while (queueIsEmpty(lq))
		{
			// 出队队头 入队队头元素的左右子树
			t = delQueue(lq);
			
			if (temp > t->data)
				printf("\n");

			if (t->lchild)
			{
				printf("%d ", t->lchild->data);
				enQueue(lq, t->lchild);
			}

			if (t->rchild)
			{
				printf("%d ", t->rchild->data);
				enQueue(lq, t->rchild);
			}
			temp = t->data;
		}
		printf("\n");

		queueDestory(lq);
	}
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






