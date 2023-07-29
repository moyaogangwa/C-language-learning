#ifndef __LNKBISORTTREE_H__
#define __LNKBISORTTREE_H__

typedef int TElemType;

typedef struct binode
{
    TElemType data;
    
    struct binode *lchild;		// ����������
   	struct binode *rchild;		// ����������
}LnkBiTree;

/*
	createBiSortTree������һ�ö���������
	
	����ֵ��
		���ظ��ڵ�	
*/
LnkBiTree *createBiSortTree();

/*
	addNodeToBiSortTree����һ�ö�������������ӽ��
		root��ָ��һ����
		BiNode��Ҫ��ӵĽ��
	����ֵ��
		���ظ��ڵ�
*/
LnkBiTree *addNodeToBiSortTree(LnkBiTree *root, LnkBiTree *BiNode);

/*
	midPrint: �������
		root��ָ��һ����
	����ֵ��
	
*/
void midPrint(LnkBiTree *root);

/*
	levelPrint������ν��б���
		root��ָ��һ����
	����ֵ��
	
*/
void levelPrint(LnkBiTree *root);

/*
	H�������ĸ߶�
		root��ָ��һ����
	����ֵ��
	
*/
int H(LnkBiTree *root);

/*
	deleteNodeBiSortTree���Ӷ�������ɾ��һ�����
		root��ָ��һ����
		x��Ҫɾ��������
	����ֵ��
		����root
*/
LnkBiTree *deleteNodeBiSortTree(LnkBiTree *root, TElemType x);

/*
	destoryBiSortTree:����һ����
		root��ָ��һ����
	����ֵ��
	
*/
void destoryBiSortTree(LnkBiTree **root);

#endif /* LnkBiSortTree.h */