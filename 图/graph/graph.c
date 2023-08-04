#include "graph.h"
#include "LnkQueue.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

AdjGraph *initGraph()
{
	AdjGraph *Graph = malloc(sizeof(*Graph));
	Graph->verNum = 0;
	Graph->arcNum = 0;
	// 将第一个参数所对应的地址 后续的空间按第三个参数设置的字节数 按字节设置为第二个参数
	memset(Graph->V, 0, sizeof(Graph->V[0])*MAXSIZE);
	memset(Graph->Adj, 0, sizeof(Graph->Adj[0][0])*MAXSIZE*MAXSIZE);

	return Graph;
}

int findVertexIndex(AdjGraph *Graph, VType Ver)
{
	int i = 0;
	while(Graph->V[i] != Ver && Graph->V[i])
		i++;
	
	return i;
}

void createGraph(AdjGraph *Graph)
{
	// 输入顶点
	fgets(Graph->V, MAXSIZE, stdin);
	// 求顶点个数 -- 把吸收掉回车符 替换成'\0'	
	Graph->V[strlen(Graph->V) - 1] = 0;
	Graph->verNum = strlen(Graph->V);
	
	// 输入顶点之间的关系
	VType V1,V2;
	AdjType w;
	int index1, index2;
	while(1)
	{
		scanf("%c %c %d", &V1, &V2, &w);
		// 输入的末尾 你输入了换行符 输入缓冲区会有一个换行符
		getchar();		
		if ( V1 == '#' || V2 == '#' || w == -1)
		{
			printf("input Ok\n");
			break;
		}
		
		// 保存顶点与顶点之间的关系
		// 1. 找顶点对应的下标
		index1 = findVertexIndex(Graph, V1);
		index2 = findVertexIndex(Graph, V2);
		if ( index1 >= Graph->verNum || index2 >= Graph->verNum)
		{
			printf("input err\n");
			continue;
		}
		// 2. 保存顶点与顶点之间的关系
		Graph->Adj[index1][index2] = w;
	}
	
}

void printGraph(AdjGraph *Graph)
{
	int i,j;
	// 先输出顶点
	for (i=0; i<Graph->verNum; i++)
		printf("\t%c ", Graph->V[i]);
	printf("\n");
		
	// 输出顶点关系
	for (i=0; i<Graph->verNum; i++)
	{
		printf("%c\t", Graph->V[i]);
		for ( j=0; j<Graph->verNum; j++)
		{
			printf("%d\t", Graph->Adj[i][j]);
		}
		printf("\n");
	}
}

void BFS(AdjGraph *Graph)
{
	LnkQueue *Queue = initQueue();
	int flag[MAXSIZE] = {0};		// flag 是一个标记数组，flag[0]对应着Graph->V[0]
									// 1 表示被访问 0 表示未被访问
	int i;
	int index1 = 0;								
	
	// 从某个顶点开始访问 -- 约定在入队之前进行访问
	printf("%c ", Graph->V[0]);
	// 将访问完的元素标志位 设置为1
	flag[0] = 1;
	enQueue(Queue, 0);

	while ( queueIsEmpty(Queue) )
	{
		// 出队队头元素
		index1 = delQueue(Queue);
		
		// 入队出队元素的所有未被访问邻结点
		for ( i=0; i<Graph->verNum; i++ )
		{
			// 表示 出队元素 和 其他顶点有关系
			if ( Graph->Adj[index1][i] != 0 && flag[i] == 0 )
			{
				// 入队该 邻结点 --  并且访问之，设置其标志位
				printf("%c ", Graph->V[i]);
				flag[i] = 1;
				enQueue(Queue, i);
			}
		}
		
		// 如果队列为空 -- 	解决孤岛问题
		if ( !queueIsEmpty(Queue) )
		{
			// 判断标志数组中是否还有未被访问的顶点
			for ( i=0; i<Graph->verNum; i++ )
			{
				// 如果顶点未被访问，则将该顶点入队并继续按照广度优先搜索的规则遍历这个图
				if ( flag[i] == 0 )
				{
					printf("%c ", Graph->V[i]);
					// 将访问完的元素标志位 设置为1
					flag[i] = 1;
					enQueue(Queue, i);	
					break;					
				}
			}
			
		}
		
	}
	printf("\n");
	queueDestory(Queue);
}

// 深度优先搜索的辅助数组
int visted[MAXSIZE] = {0};
void DFSTraver(AdjGraph *Graph)
{	
	int i;
	DFS(Graph, 0);
	// 访问 孤岛中的顶点
	for ( i=0; i<Graph->verNum; i++ )
	{
		if ( visted[i] == 0 )
			DFS(Graph, i);
	}
	printf("\n");
}

// 深度优先搜索 访问某个顶点的邻结点
void DFS(AdjGraph *Graph, int vertexIndex)
{
	int i;
	
	printf("%c ", Graph->V[vertexIndex]);
	visted[vertexIndex] = 1;
	
	// 访问 vertexIndex 对应的第一个邻结点 
	for ( i=0; i<Graph->verNum; i++)
	{
		if ( Graph->Adj[vertexIndex][i] && visted[i] == 0 )
		{
			// 访问V0的邻结点
			DFS( Graph, i );
		}	
	}
}

// 标记当前的最短路径
int S[MAXSIZE] = {0};
// 保存当前最短路径
int dist[MAXSIZE] = {0};

char way[MAXSIZE][MAXSIZE]={0};

void Dijistra(AdjGraph *Graph, int vertexIndex)
{
    // 将 源点 到 终点的当前路径长度保存进 dist 数组
    int i,min,index,n=0;
	int lt = 0;
    // 自己到自己
    S[vertexIndex] = 1;
	way[vertexIndex][0]=Graph->V[vertexIndex];
    for (i=0; i<Graph->verNum; i++)
    {
        // 没有关系就表示为无穷
        if ( Graph->Adj[vertexIndex][i] == 0 )
            dist[i] = MAXDIST;
        else
            dist[i] = Graph->Adj[vertexIndex][i];
    }
    
    // 找最短路径的次数 和 顶点数有关
    while( n++ < Graph->verNum )
    {
		way[n-1][0]=Graph->V[vertexIndex];
        // step1 找当前dist[]中未被标记为最短路径的最小值，并且将其标记为最优路径
        min = MAXDIST;
        for (i=0; i<Graph->verNum; i++)
        {
            if ( S[i] == 0 && dist[i] < min )
            {
                min = dist[i];
                // 保存其下标
                index = i;
            }           
        }

        // 找到的当前的最短路径为最优路径
        S[index] = 1;
		lt = strlen(way[index]);
		way[index][lt]=Graph->V[index];
		way[index][lt+1]=0;

        // step2 去尝试更新其他未被标记为最短路径的邻接点
        for (i=0; i<Graph->verNum; i++)
        {
            if ( S[i] == 0 && Graph->Adj[index][i] && dist[index] + Graph->Adj[index][i] < dist[i] )
            {
                dist[i] = dist[index] + Graph->Adj[index][i];
				strcpy(way[i],way[index]);
            }           
        }
    }

	for ( i=0; i<Graph->verNum; i++ )
	{
		printf("%c->%c:%d  way:%s\n", Graph->V[vertexIndex], Graph->V[i], dist[i],way[i]);
	}		
	
}
