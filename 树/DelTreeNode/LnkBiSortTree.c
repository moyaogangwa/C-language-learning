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
		
		// ��װ�ɽ��
		LnkBiTree *BiNode = malloc(sizeof(*BiNode));
		BiNode->data = data;
		BiNode->lchild = NULL;
		BiNode->rchild = NULL;
		
		// �ѽ����ӽ�������
		root = addNodeToBiSortTree(root, BiNode);
	}
	
	return root;
}

LnkBiTree *addNodeToBiSortTree(LnkBiTree *root, LnkBiTree *BiNode)
{
	LnkBiTree *p = root;
	
	// �������һ�ÿ���
	if ( root == NULL )
		return BiNode;
	
	// �ҵ�����λ�� -- �������֮�� ѭ������
	while(1)
	{
		// ��� ������Ľ������н���
		if ( BiNode->data > p->data )
		{
			// ��� ���н��û�����������������Ľ����Ϊ pָ�����������
			if ( p->rchild == NULL )
			{
				p->rchild = BiNode;
				break;
			}
			// ����� ����������������ұ߱Ƚ�
			p = p->rchild;
		}
		// ��� ������Ľ������н��С
		else if ( BiNode->data < p->data )
		{
			// ��� ���н��û�����������������Ľ����Ϊ pָ�����������
			if ( p->lchild == NULL )
			{
				p->lchild = BiNode;
				break;
			}
			// ����� �����������������߱Ƚ�
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
	
	// �Ȱ�����������Ĺ�����ʸ���������
	midPrint(root->lchild);
	
	// ���ʸ����
	printf ("%d ", root->data);
	
	// ������������Ĺ�����ʸ���������
	midPrint(root->rchild);
}

void destoryBiSortTree(LnkBiTree **root)
{
	LnkBiTree *l = NULL;
	LnkBiTree *r = NULL;
	
	if ( *root == NULL )
		return ;
	// �����ٸ���� -- ����֮ǰ��Ҫ�����������������������ĵ�ַ
	l = (*root)->lchild;  
	r = (*root)->rchild;
	free(*root);
	*root = NULL;
	
	// �ٰ����������Ĺ���ȥ���ٸ���������
	destoryBiSortTree(&l);
	
	// �ٰ����������Ĺ���ȥ���ٸ���������
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
	LnkBiTree *p = root;		// p ��ɾ���Ľ��
	LnkBiTree *pre = p;			// pre ��¼p�ĸ��ڵ�
	
	LnkBiTree *p1 = NULL;		// p ��ɾ���Ľ��
	LnkBiTree *pre1 = NULL;			// pre ��¼p�ĸ��ڵ�
	
	// ��������� 
	if ( root )
	{
		// ��ɾ��λ��
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
		
		// �ҵ��� -- ����ɾ��
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
			// 2.������������
			else if (p->lchild&&p->rchild)
			{
				// �Ҷ����ֵ -- ���ұ�����С�� ���ߴ����������					
				pre1 = p;
				p1 = p->rchild;
				
				while(p1->lchild)
				{
					pre1 = p1;
					p1 = p1->lchild;
				}
				
				// �������   
				// 1. p��������û��������
				if ( p1 == p->rchild )
				{
					p->data = p1->data;
					p->rchild = p1->rchild;
					p1->rchild = NULL;
					free(p1);
				}
				else  //2.p����������������
				{
					p->data=p1->data;
					if(p1->rchild)
						pre1->lchild=p1->rchild;
					else
						pre1->lchild=NULL;
					free(p1);
				}					
			}				
			// 3.������������������
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
	// ������ǿ���
	if ( root )
	{
		LnkBiTree *t = NULL;
		LnkQueue * lq = initQueue();
		// currLevel ��ǰ��Ľ���� ��nextLevel ��һ��Ľ����
		int currLevel = 0, nextLevel = 0;
				
		// ��Ӹ��ڵ�
		enQueue(lq, root);
		currLevel = 1;
		
		while ( queueIsEmpty(lq) )
		{						
			// ���Ӷ�ͷ ��Ӷ�ͷԪ�ص���������
			t = delQueue(lq);				

			// currLevel == 0��ʾ��ǰ�����������
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
			
			// ����ʱ ��ǰ������ -1
			// ���Ӻ��ȷ���
			printf ("%d ", t->data);
			currLevel--;
		}
		printf ("\n");

		queueDestory(lq);		
	}
	
}