#ifndef __GRAPH_H__
#define __GRAPH_H__

typedef char VType;
typedef int AdjType;

#define MAXSIZE 256
#define MAXDIST 65535

typedef struct adj
{
    VType  V[MAXSIZE];						// 保存顶点
    AdjType Adj[MAXSIZE][MAXSIZE];			// 保存关系
    int verNum;						// 保存顶点个数
    int arcNum;						// 保存边或者弧的条数
}AdjGraph;

/*
	initGraph：初始化一个图
		
	返回值：
		返回图指针
*/
AdjGraph *initGraph();

/*
	createGraph：创建一个图
		Graph：指向一个你要创建的图
	返回值：
	
*/
void createGraph(AdjGraph *Graph);

/*
	findVertexIndex：找出图中顶点下标
		Graph：指向一个图
		Ver：你想要找的那个顶点
	返回值：
		成功，返回顶点下标
		失败，返回顶点数
*/
int findVertexIndex(AdjGraph *Graph, VType Ver);

/*
	BFS：广度优先搜索
		Graph：指向一个图		
	返回值：
	
*/
void BFS(AdjGraph *Graph);

/*
	DFSTraver：深度优先搜索
		Graph：指向一个图		
	返回值：
	
*/
void DFSTraver(AdjGraph *Graph);

/*
	DFS：深度优先递归搜索
		Graph：指向一个图
		vertexIndex：深度优先搜索访问的顶点
	返回值：
	
*/
void DFS(AdjGraph *Graph, int vertexIndex);

/*
	Dijistra：迪杰斯特拉求最短路径
		Graph：指向一个图
		vertexIndex：指定出发源点
	返回值：
	
*/
void Dijistra(AdjGraph *Graph, int vertexIndex);

/*
	printGraph：输出邻接表
		Graph：指向一个图
	返回值：
	
*/
void printGraph(AdjGraph *Graph);

#endif /* Graph.h */