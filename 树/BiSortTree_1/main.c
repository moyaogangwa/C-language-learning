#include "BiSortTree.h"
#include <stdio.h>

int main()
{
	LnkBiTree *root = createbitree();
	
	
	befprint(root);
	
	midprint(root);
	
	destroytree(&root);
	
	return 0;
}