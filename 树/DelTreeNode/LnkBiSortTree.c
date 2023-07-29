#include "LnkBiSortTree.h"
#include "LnkQueue.h"
#include <stdio.h>
#include <stdlib.h>

LnkBiTree *createBiSortTree()
{
	TElemType data;
	LnkBiTree *root = NULL;
	
	while(1)
	{
		scanf("%d", &data);
		if ( data == 0 )
		{
			printf("data input OK\n");
			break;
		}
		
		// 封装成结点
		LnkBiTree *BiNode = malloc(sizeof(*BiNode));
		BiNode->data = data;
		BiNode->lchild = NULL;
		BiNode->rchild = NULL;
		
		// 把结点添加进入树中
		root = addNodeToBiSortTree(root, BiNode);
	}
	
	return root;
}

LnkBiTree *addNodeToBiSortTree(LnkBiTree *root, LnkBiTree *BiNode)
{
	LnkBiTree *p = root;
	
	// 如果树是一棵空树
	if ( root == NULL )
		return BiNode;
	
	// 找到插入位置 -- 插入结束之后 循环结束
	while(1)
	{
		// 如果 待插入的结点比树中结点大
		if ( BiNode->data > p->data )
		{
			// 如果 树中结点没有右子树，则待插入的结点作为 p指向结点的右子树
			if ( p->rchild == NULL )
			{
				p->rchild = BiNode;
				break;
			}
			// 如果有 右子树，则继续往右边比较
			p = p->rchild;
		}
		// 如果 待插入的结点比树中结点小
		else if ( BiNode->data < p->data )
		{
			// 如果 树中结点没有左子树，则待插入的结点作为 p指向结点的左子树
			if ( p->lchild == NULL )
			{
				p->lchild = BiNode;
				break;
			}
			// 如果有 左子树，则继续往左边比较
			p = p->lchild;
		}
		else
		{
			free(BiNode);
			break;
		}
	}
	
	return root;
}

void midPrint(LnkBiTree *root)
{
	if ( root == NULL )
		return ;
	
	// 先按照中序遍历的规则访问根的左子树
	midPrint(root->lchild);
	
	// 访问根结点
	printf ("%d ", root->data);
	
	// 按照中序遍历的规则访问根的右子树
	midPrint(root->rchild);
}

void destoryBiSortTree(LnkBiTree **root)
{
	LnkBiTree *l = NULL;
	LnkBiTree *r = NULL;
	
	if ( *root == NULL )
		return ;
	// 先销毁根结点 -- 销毁之前需要保留根的左子树和右子树的地址
	l = (*root)->lchild;  
	r = (*root)->rchild;
	free(*root);
	*root = NULL;
	
	// 再按照销毁树的规则去销毁根的左子树
	destoryBiSortTree(&l);
	
	// 再按照销毁树的规则去销毁根的右子树
	destoryBiSortTree(&r);
	
}

int H(LnkBiTree *root)
{
    if ( root == NULL )
        return 0;
    
    int l = H(root->lchild);
    int r = H(root->rchild);
    
    return  1 + (l>r?l:r);
}

LnkBiTree *deleteNodeBiSortTree(LnkBiTree *root, TElemType x)
{
	LnkBiTree *p = root;		// p 找删除的结点
	LnkBiTree *pre = p;			// pre 记录p的父节点
	
	LnkBiTree *p1 = NULL;		// p 找删除的结点
	LnkBiTree *pre1 = NULL;			// pre 记录p的父节点
	
	// 如果树存在 
	if ( root )
	{
		// 找删除位置
		while(p)
		{
			if ( p->data == x )
				break;
			
			pre = p;
			if ( p->data > x )
				p = p->lchild;
			else
				p = p->rchild;
		}
		
		// 找到了 -- 进行删除
		if ( p )
		{
			
			if ( p->lchild == NULL && p->rchild == NULL )
			{
				if(p==root)
				{
					free(p);
					root=NULL;
				}
				else
				{
					if(pre->rchild==p)
					pre->rchild=NULL;
					else
						pre->lchild=NULL;
					free(p);
					p=NULL;
				}
					
			}				
			// 2.左右子树均有
			else if (p->lchild&&p->rchild)
			{
				// 找顶替的值 -- 从右边找最小的 或者从左边找最大的					
				pre1 = p;
				p1 = p->rchild;
				
				while(p1->lchild)
				{
					pre1 = p1;
					p1 = p1->lchild;
				}
				
				// 两种情况   
				// 1. p的右子树没有左子树
				if ( p1 == p->rchild )
				{
					p->data = p1->data;
					p->rchild = p1->rchild;
					p1->rchild = NULL;
					free(p1);
				}
				else  //2.p的右子树有左子树
				{
					p->data=p1->data;
					if(p1->rchild)
						pre1->lchild=p1->rchild;
					else
						pre1->lchild=NULL;
					free(p1);
				}					
			}				
			// 3.有左子树或者右子树
			else
			{
				if(p==root)
				{
					if(p->rchild)
					{
						root=p->rchild;
						free(p);
					}
					else
					{
						root=p->lchild;
						free(p);
					}
				}
				else
				{
					if(p->rchild)
					{
						p1=p->rchild;
						p->data=p1->data;
						p->rchild=p1->rchild;
						p->lchild=p1->lchild;
						free(p1);
					}
					else
					{
						p1=p->lchild;
						p->data=p1->data;
						p->rchild=p1->rchild;
						p->lchild=p1->lchild;
						free(p1);
					}
				}
			}
			
		}
	}
	
	return root;
}

void levelPrint(LnkBiTree *root)
{
	// 如果不是空树
	if ( root )
	{
		LnkBiTree *t = NULL;
		LnkQueue * lq = initQueue();
		// currLevel 当前层的结点数 ，nextLevel 下一层的结点数
		int currLevel = 0, nextLevel = 0;
				
		// 入队根节点
		enQueue(lq, root);
		currLevel = 1;
		
		while ( queueIsEmpty(lq) )
		{						
			// 出队队头 入队队头元素的左右子树
			t = delQueue(lq);				

			// currLevel == 0表示当前层结点访问完了
			if ( currLevel == 0 )
			{
				currLevel = nextLevel;
				nextLevel = 0;
				putchar('\n');
			}
			
			if ( t->lchild )
			{
				enQueue(lq, t->lchild);
				nextLevel++;
			}
			
			if ( t->rchild )
			{
				enQueue(lq, t->rchild);
				nextLevel++;
			}
			
			// 出队时 当前层结点数 -1
			// 出队后先访问
			printf ("%d ", t->data);
			currLevel--;
		}
		printf ("\n");

		queueDestory(lq);		
	}
	
}