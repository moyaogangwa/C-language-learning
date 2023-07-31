#include "AVL.h"
#include "LnkQueue.h"
#include <stdio.h>
#include <stdlib.h>

LnkBiTree *createAVL()
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
		
		// 把结点添加进入树中 -- 插入会导致不平衡
		root = addNodeToAVL(root, BiNode);
	}
	
	return root;
}

LnkBiTree *addNodeToAVL(LnkBiTree *root, LnkBiTree *BiNode)
{
	LnkBiTree *p = root;
	
	// 如果树是一棵空树
	if ( root == NULL )
		return BiNode;
	
	// 如果 待插入的结点比树中结点大
	if ( BiNode->data > p->data )
	{
		// 将BiNode 往p的右子树中添加
		p->rchild = addNodeToAVL(p->rchild, BiNode);
		
		// 只有可能导致右边的高度比左边高
		// 如果不平衡
		if ( H( p->rchild ) - H( p->lchild ) > 1 )
		{
			// 1.右深右插 -- BiNode的数据比p->rchild->data 还要大
			if ( BiNode->data > p->rchild->data )
				p = SingleLeftRotate(p);
			
			// 2.右深左差
			else
				p = DoubleRightToLeftRotate(p);
		}
	}
	// 如果 待插入的结点比树中结点小
	else if ( BiNode->data < p->data )
	{
		p->lchild = addNodeToAVL(p->lchild, BiNode);
		
		// 只有可能导致左边的高度比右边高
		// 如果不平衡
		if ( H( p->lchild ) - H( p->rchild ) > 1 )
		{
			// 1.左深左插 -- BiNode的数据比p->rchild->data 还要大
			if ( BiNode->data < p->lchild->data )
				p = SingleRightRotate(p);
			
			// 2.左深右差
			else
				p = DoubleLeftToRightRotate(p);
		}
	}
	else
	{
		free(BiNode);
	}

	
	return p;
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

void destoryAVL(LnkBiTree **root)
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
	destoryAVL(&l);
	
	// 再按照销毁树的规则去销毁根的右子树
	destoryAVL(&r);
	
}

int H(LnkBiTree *root)
{
    if ( root == NULL )
        return 0;
    
    int l = H(root->lchild);
    int r = H(root->rchild);
    
    return  1 + (l>r?l:r);
}

LnkBiTree *SingleRightRotate(LnkBiTree *root)
{
	LnkBiTree *k = root;
	LnkBiTree *k1 = k->lchild;
	
	k->lchild = k1->rchild;
	k1->rchild = k;	
 	
	return k1;
}

LnkBiTree *SingleLeftRotate(LnkBiTree *root)
{
	LnkBiTree *k = root;
	LnkBiTree *k1 = k->rchild;
	
	k->rchild = k1->lchild;
	k1->lchild = k;
 	
	return k1;
}

LnkBiTree *DoubleLeftToRightRotate(LnkBiTree *root)
{
	LnkBiTree *k = root;
	LnkBiTree *k1 = k->lchild;
	
	k->lchild = SingleLeftRotate(k1);
	k = SingleRightRotate(k);
 	
	return k;
}

LnkBiTree *DoubleRightToLeftRotate(LnkBiTree *root)
{
	LnkBiTree *k = root;
	LnkBiTree *k1 = k->rchild;
	
	k->rchild = SingleRightRotate(k1);
	k = SingleLeftRotate(k);
 	
	return k;
}