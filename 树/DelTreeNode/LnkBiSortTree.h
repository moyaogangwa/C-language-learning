#ifndef __LNKBISORTTREE_H__
#define __LNKBISORTTREE_H__

typedef int TElemType;

typedef struct binode
{
    TElemType data;
    
    struct binode *lchild;		// 保存左子树
   	struct binode *rchild;		// 保存右子树
}LnkBiTree;

/*
	createBiSortTree：创建一棵二叉排序树
	
	返回值：
		返回根节点	
*/
LnkBiTree *createBiSortTree();

/*
	addNodeToBiSortTree：往一棵二叉排序树中添加结点
		root：指向一棵树
		BiNode：要添加的结点
	返回值：
		返回根节点
*/
LnkBiTree *addNodeToBiSortTree(LnkBiTree *root, LnkBiTree *BiNode);

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
	deleteNodeBiSortTree：从二叉树中删除一个结点
		root：指向一棵树
		x：要删除的数据
	返回值：
		返回root
*/
LnkBiTree *deleteNodeBiSortTree(LnkBiTree *root, TElemType x);

/*
	destoryBiSortTree:销毁一棵树
		root：指向一棵树
	返回值：
	
*/
void destoryBiSortTree(LnkBiTree **root);

#endif /* LnkBiSortTree.h */