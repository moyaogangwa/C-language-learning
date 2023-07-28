#include "BiSortTree.h"
#include <stdio.h>

int main()
{
	LnkBiTree *root = createbitree();
	
	midprint(root);
	printf("\n");
	
	levelprint(root);
	
	destroytree(&root);
	
	return 0;
}