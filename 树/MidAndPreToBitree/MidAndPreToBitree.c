#include "MidAndPreToBiTree.h"
#include "LnkStack.h"
#include "LnkQueue.h"

LnkBiTree *CreateBitree()
{
	LnkBiTree *root = NULL;
	LnkBiTree *new = NULL;
	TElemType data = 0;
	while (1)
	{
		scanf("%d", &data);
		if (0 == data)
		{
			printf("input ok!\n");
			break;
		}
		new = InitTreeNode(data);
		root = AddTreeNode(root, new);
	}
	return root;
}

LnkBiTree *InitTreeNode(TElemType data)
{
	LnkBiTree *new = malloc(sizeof(LnkBiTree));
	new->data = data;
	new->lchild = NULL;
	new->rchild = NULL;
	return new;
}

LnkBiTree *AddTreeNode(LnkBiTree *root, LnkBiTree *new)
{
	LnkBiTree *treenode = root;
	if (root)
	{
		while (1)
		{
			if (treenode->data>new->data)
			{
				if (treenode->lchild == NULL)
				{
					treenode->lchild = new;
					break;
				}
				treenode = treenode->lchild;
			}
			else if (treenode->data<new->data)
			{
				if (treenode->rchild == NULL)
				{
					treenode->rchild = new;
					break;
				}
				treenode = treenode->rchild;
			}
			else
			{
				free(new);
				break;
			}
		}
	}
	else
		return new;
	return root;

}

void midprint(LnkBiTree *root)
{
	if (root)
	{
		midprint(root->lchild);
		printf("%d ", root->data);
		midprint(root->rchild);
	}
	else
		return;
}

void levelprint(LnkBiTree *root)
{
	if (root)
	{
		LnkQueue *lq = initQueue();
		LnkBiTree *t = NULL;
		int therow = 0, nextrow = 0;
		printf("%d\n", root->data);
		enQueue(lq, root);
		therow++;
		while (queueIsEmpty(lq))
		{
			t = delQueue(lq);
			therow--;
			if (t->lchild)
			{
				printf("%d ", t->lchild->data);
				enQueue(lq, t->lchild);
				nextrow++;
			}
			if (t->rchild)
			{
				printf("%d ", t->rchild->data);
				enQueue(lq, t->rchild);
				nextrow++;
			}

			if (0 == therow)
			{
				printf("\n");
				therow = nextrow;
				nextrow = 0;
			}
		}
	}
	else
		return;
}

//二叉排序树的分层打印
/*
void levelprint(LnkBiTree *root)
{
if(root)
{
LnkQueue *lq = initQueue();
LnkBiTree *t = NULL;
int temp = 0;
printf("%d\n",root->data);
enQueue(lq,root);
therow++;
while(queueIsEmpty(lq))
{
t=delQueue(lq);

if(temp>t->data)
printf("\n");

if(t->lchild)
{
printf("%d ",t->lchild->data);
enQueue(lq,t->lchild);
}
if(t->rchild)
{
printf("%d ",t->rchild->data);
enQueue(lq,t->rchild);
}
temp=t->data;
}
printf("\n");
}
}
*/
void destroytree(LnkBiTree **root)
{
	LnkBiTree *l = NULL;
	LnkBiTree *r = NULL;
	if (*root)
	{
		l = (*root)->lchild;
		r = (*root)->rchild;
		free(*root);
		*root = NULL;

		destroytree(&l);
		destroytree(&r);
	}
	else
		return;
}

LnkBiTree *MidAndPreToBiTree(int *pre, int *mid)
{
	int index1 = 0, index2 = 0;
	LnkBiTree *root = NULL;
	LnkBiTree *temp = NULL;
	LnkBiTree *new = NULL;

	LnkStack *stk = initStack();
	while (mid[index2]&&pre[index1])
	{
		if (0 == index1 || pre[index1 - 1] != mid[index2])
		{
			new = InitTreeNode(pre[index1]);
			Push(stk, new);
			if (0 == index1)
			{
				root = new;
				temp = root;
			}
			else
			{
				temp->lchild = new;
				temp = temp->lchild;
			}
			index1++;
		}
		else if (pre[index1 - 1] == mid[index2])
		{
			temp = Pop(stk);
			index2++;
			while (getTop(stk)&&mid[index2] == getTop(stk)->data->data)
			{
				temp = Pop(stk);
				index2++;
			}
			new = InitTreeNode(pre[index1]);
			Push(stk, new);
			index1++;
			temp->rchild = new;
			temp=temp->rchild;
		}
	}
	return root;
}






