#ifndef __AVL_H__
#define __AVL_H__

typedef int TElemType;

typedef struct binode
{
    TElemType data;
    
    struct binode *lchild;		// 保存左子树
   	struct binode *rchild;		// 保存右子树
}LnkBiTree;

/*
	createAVL：创建一棵平衡二叉排序树
	
	返回值：
		返回根节点	
*/
LnkBiTree *createAVL();

/*
	addNodeToAVL：往一棵平衡二叉排序树中添加结点
		root：指向一棵树
		BiNode：要添加的结点
	返回值：
		返回根节点
*/
LnkBiTree *addNodeToAVL(LnkBiTree *root, LnkBiTree *BiNode);

/*
	SingleRightRotate：单向右旋平衡处理
		root：你要进行旋转的树
	返回值：
		返回旋转之后的树的结点
*/
LnkBiTree *SingleRightRotate(LnkBiTree *root);

/*
	SingleLeftRotate：单向左旋平衡处理
		root：你要进行旋转的树
	返回值：
		返回旋转之后的树的结点
*/
LnkBiTree *SingleLeftRotate(LnkBiTree *root);

/*
	DoubleLeftToRightRotate：双向旋转先左后右
		root：你要进行旋转的树
	返回值：
		返回旋转之后的树的结点
*/
LnkBiTree *DoubleLeftToRightRotate(LnkBiTree *root);

/*
	DoubleRightToLeftRotate：双向旋转 先右后左
		root：你要进行右旋的树
	返回值：
		返回旋转之后的树的结点
*/
LnkBiTree *DoubleRightToLeftRotate(LnkBiTree *root);

/*
	midPrint: 中序遍历
		root：指向一棵树
	返回值：
	
*/
void midPrint(LnkBiTree *root);

/*
	levelPrint：按层次进行遍历
		root：指向一棵树
	返回值：
	
*/
void levelPrint(LnkBiTree *root);

/*
	H：求树的高度
		root：指向一棵树
	返回值：
	
*/
int H(LnkBiTree *root);

/*
	destoryBiSortTree:销毁一棵树
		root：指向一棵树
	返回值：
	
*/
void destoryAVL(LnkBiTree **root);

#endif /* AVL.h */