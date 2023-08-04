#ifndef __MIDANDPRETOBITREE_H__
#define __MIDANDPRETOBITREE_H__ 1

//ͷ�ļ�
#include <stdlib.h>
#include <stdio.h>

//��������

typedef int TElemType;

typedef struct binode
{
    TElemType data;
    
    struct binode *lchild;		// ����������
   	struct binode *rchild;		// ����������
}LnkBiTree;




//��������

LnkBiTree *CreateBitree();

LnkBiTree *InitTreeNode(TElemType data);

LnkBiTree *AddTreeNode(LnkBiTree *root,LnkBiTree *new);

void midprint(LnkBiTree *root);

void levelprint(LnkBiTree *root);

LnkBiTree *MidAndPreToBiTree(int *pre,int *mid);

void destroytree(LnkBiTree **root);





#endif     /*MidAndPreToBiTree.h*/