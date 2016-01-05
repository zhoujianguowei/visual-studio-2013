#include"fond.h"
#define MAX_VERTEX_NUM 50
typedef struct arcnode * Arcnode;
typedef struct vnode *Vnode;
typedef struct graph *Graph;
struct arcnode
{
	int adjv;
	int weight;
	Arcnode next;
};
struct vnode
{
	int vertex;
	Arcnode firstEdge;
};
struct graph
{
	int vertexNum, edgeNum;
	struct vnode* adjList;
};
bool *vVisited;
Graph createGraph(int verNum, int edgeNum, int choice)
{
	Graph g = (Graph)(malloc(sizeof(struct graph)));
	g->adjList = (Vnode)(malloc(sizeof(struct vnode)*verNum));
	int i;
	int u, v, weight;
	vVisited = new bool[verNum]; 
	memset(vVisited, false, sizeof(bool)*verNum);
	switch (choice)
	{
	case 0:
		cout << "创建无权图" << endl;
		break;
	case 1:
		cout << "创建有权图" << "e(u,v,weight)形式,如0 3 5表示节点0->3相连，并且权值为5" << endl;
		for (i = 0; i < edgeNum; i++)
		{
			/*
			类似于单链表的倒序插入
			*/
			cin >> u >> v >> weight;
			Arcnode arcnode = (Arcnode)(malloc(sizeof(struct arcnode)));
			arcnode->next = NULL;
			if (!vVisited[u])
			{
				g->adjList[u].vertex = u;
				g->adjList[u].firstEdge = NULL;
				vVisited[u] = true;
			}
			arcnode->adjv = v;
			arcnode->weight = weight;
			arcnode->next = g->adjList[u].firstEdge;
			g->adjList[u].firstEdge = arcnode;
		}
		break;
	default:
		break;
	}
	return g;
}
void printGraph(Graph g, int vertexNum)
{
	int u, v, weight;
	for (int i = 0; i < vertexNum; i++)
	{
		Arcnode firstEdge = g->adjList[i].firstEdge;
		u = g->adjList[i].vertex;
		while (firstEdge)
		{
			v = firstEdge->adjv;
			weight = firstEdge->weight;
			cout << u << "->" << v <<"="<< weight << "\t";
			firstEdge = firstEdge->next;
		}
		cout << endl;
	}
}
void graph_test()
{
	int n, m, choice;
	cout << "输入节点数，边数，以及图的类型0为无权图，1为有权图" << endl;
	cin >> n >> m >> choice;
	printGraph(createGraph(n, m, choice), n);

}

