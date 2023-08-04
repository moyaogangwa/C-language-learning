#include <stdio.h>
#include "MidAndPreToBiTree.h"



int main()
{
	int pre[10] = {5,4,3,2,6,1,7};
	int mid[10] = {3,4,6,2,5,1,7};
	LnkBiTree *root = MidAndPreToBiTree(pre,mid);
	midprint(root);
	printf("\n");
	levelprint(root);
	destroytree(&root);
	return 0;
}