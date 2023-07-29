#include "LnkBiSortTree.h"
#include <stdio.h>

int main()
{
	LnkBiTree *root = createBiSortTree();
	int n = 0;
	
	midPrint(root);
	printf("\n");
	
	levelPrint(root);
	
	printf("tree height:%d\n" ,H(root));
	
	scanf("%d",&n);
	
	root=deleteNodeBiSortTree(root, n);
	
	midPrint(root);
	
	printf("\n");
	
	levelPrint(root);
	
	destoryBiSortTree(&root);
	
	return 0;
}