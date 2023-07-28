#ifndef __BISORTTREE_H__
#define __BISORTTREE_H__

//头文件
#include <stdio.h>
#include <stdlib.h>


//变量声明
typedef int TElemType;

typedef struct bitreenode
{
	TElemType data;
	struct bitreenode *lchild;
	struct bitreenode *rchild;
}LnkBiTree;


//函数声明
LnkBiTree *createbitree();

void createtnode(LnkBiTree **newtnode,TElemType data);

void addtnode(LnkBiTree **bitree,LnkBiTree *newtnode);

void midprint(LnkBiTree *bitree);

void befprint(LnkBiTree *bitree);

void destroytree(LnkBiTree **bitree);



#endif   /*BiSortTree.h*/