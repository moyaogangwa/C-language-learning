#ifndef __BISORTTREE_H__
#define __BISORTTREE_H__ 1

//ͷ�ļ�
#include <stdio.h>
#include <stdlib.h>


//��������
typedef int TElemType;

typedef struct bitreenode
{
	TElemType data;
	struct bitreenode *lchild;
	struct bitreenode *rchild;
}LnkBiTree;


//��������
LnkBiTree *createbitree();

void createtnode(LnkBiTree **newtnode,TElemType data);

void addtnode(LnkBiTree **bitree,LnkBiTree *newtnode);

void midprint(LnkBiTree *bitree);

void levelPrint(LnkBiTree* root);

void destroytree(LnkBiTree **bitree);



#endif   /*BiSortTree.h*/