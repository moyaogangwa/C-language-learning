#include "graph.h"

int main()
{
	AdjGraph *graph = initGraph();
	
	createGraph(graph);
	
	printGraph(graph);
	
	BFS(graph);

	DFSTraver(graph);

	Dijistra(graph, 0);
	
	return 0;
}