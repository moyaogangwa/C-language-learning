#include "BiSortTree.h"
#include <stdio.h>

int main()
{
	LnkBiTree *root = createbitree();
	
	
	preprint(root);
	
	midprint(root);
	
	posprint(root);
	
	destroytree(&root);
	
	return 0;
}