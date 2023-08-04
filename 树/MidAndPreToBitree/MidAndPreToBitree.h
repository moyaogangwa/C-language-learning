#ifndef __MIDANDPRETOBITREE_H__
#define __MIDANDPRETOBITREE_H__ 1

//头文件
#include <stdlib.h>
#include <stdio.h>

//变量声明

typedef int TElemType;

typedef struct binode
{
    TElemType data;
    
    struct binode *lchild;		// 保存左子树
   	struct binode *rchild;		// 保存右子树
}LnkBiTree;




//函数声明

LnkBiTree *CreateBitree();

LnkBiTree *InitTreeNode(TElemType data);

LnkBiTree *AddTreeNode(LnkBiTree *root,LnkBiTree *new);

void midprint(LnkBiTree *root);

void levelprint(LnkBiTree *root);

LnkBiTree *MidAndPreToBiTree(int *pre,int *mid);

void destroytree(LnkBiTree **root);





#endif     /*MidAndPreToBiTree.h*/