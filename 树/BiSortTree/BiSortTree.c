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
	// �Ȱ�����������Ĺ�����ʸ���������
	midprint(bitree->lchild);
	// ���ʸ����
	printf("%d ",bitree->data);
	// ������������Ĺ�����ʸ���������
	midprint(bitree->rchild);
}

void befprint(LnkBiTree *bitree)
{
	if(NULL==bitree)
		return;
	
	// ���ʸ����
	printf("%d ",bitree->data);
	// ������������Ĺ�����ʸ���������
	midprint(bitree->lchild);
	// ������������Ĺ�����ʸ���������
	midprint(bitree->rchild);
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

void levelPrint(LnkBiTree* root)
{
	// ������ǿ���
	if (root)
	{
		LnkBiTree* t = NULL;
		LnkQueue* lq = initQueue();

		// ���ǰ�ȷ���
		printf("%d ", root->data);
		printf("\n");
		// ��Ӹ��ڵ�
		enQueue(lq, root);

		int temp = 0;

		while (queueIsEmpty(lq))
		{
			// ���Ӷ�ͷ ��Ӷ�ͷԪ�ص���������
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
	
	// �����ٸ���� -- ����֮ǰ��Ҫ�����������������������ĵ�ַ
	free(*bitree);
	*bitree=NULL;
	// �ٰ����������Ĺ���ȥ���ٸ���������
	destroytree(&l);
	//�ٰ����������Ĺ���ȥ���ٸ���������
	destroytree(&r);
	
}






