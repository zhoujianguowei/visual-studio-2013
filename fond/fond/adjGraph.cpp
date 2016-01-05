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
		cout << "������Ȩͼ" << endl;
		break;
	case 1:
		cout << "������Ȩͼ" << "e(u,v,weight)��ʽ,��0 3 5��ʾ�ڵ�0->3����������ȨֵΪ5" << endl;
		for (i = 0; i < edgeNum; i++)
		{
			/*
			�����ڵ�����ĵ������
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
	cout << "����ڵ������������Լ�ͼ������0Ϊ��Ȩͼ��1Ϊ��Ȩͼ" << endl;
	cin >> n >> m >> choice;
	printGraph(createGraph(n, m, choice), n);

}

