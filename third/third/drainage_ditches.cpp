#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<memory.h>
#include<vector>
#include<queue>
#include<stdlib.h>
#include<stdio.h>
#define MAX_INT 0x3f3f3f3f
#define MAXM 201
#define MAXN 201

using namespace std;
/*
索引数据是从1开始,s和t分别代表起点和汇点的索引
*/
bool bfs(int v, int rGraph[MAXN][MAXN], int parent[MAXN], int s, int t)
{
	bool visited[MAXN];
	memset(visited, false, sizeof(bool)*(v + 1));
	queue<int> nodeQueqe;
	nodeQueqe.push(s);
	parent[s] = -1;
	visited[s] = true;
	while (!nodeQueqe.empty())
	{
		int p = nodeQueqe.front();
		nodeQueqe.pop();
		for (int i = 1; i <= v; i++)
		{
			if (!visited[i] && rGraph[p][i] > 0)
			{
				parent[i] = p;
				nodeQueqe.push(i);
				visited[i] = true;
			}
		}
	}

	return visited[t];
}

int getMaxFlow(int v, int graph[MAXN][MAXN], int s, int t)
{
	int rGraph[MAXN][MAXN];
	int i, j;
	for (i = 1; i <= v; i++)
		for (j = 1; j <= v; j++)
			rGraph[i][j] = graph[i][j];
	int parent[MAXN];
	int max_flow = 0;
	while (bfs(v, rGraph, parent, s, t))
	{
		int min_flow = MAX_INT;
		for (i = t; i != s; i = parent[i])
		{
			int p = parent[i];
			min_flow = min_flow < rGraph[p][i] ? min_flow : rGraph[p][i];
		}
		for (i = t; i != s; i = parent[i])
		{
			rGraph[i][parent[i]] += min_flow;
			rGraph[parent[i]][i] -= min_flow;
		}
		max_flow += min_flow;
	}

	return max_flow;
}
int main()
{
	int n, m;
	int graph[MAXN][MAXN];
	while (scanf("%d %d", &n, &m)>0)
	{

		memset(graph, 0, sizeof(graph));
		for (int i = 1; i <= n; i++)
		{
			int s, e, c;
			cin >> s >> e >> c;
			graph[s][e] += c;
		}
		cout << getMaxFlow(m, graph, 1, m)<<endl;
	}
	/*graph[1][2] = 16;
	graph[1][3] = 13;
	graph[2][3] = 10;
	graph[2][4] = 12;
	graph[3][2] = 4;
	graph[3][5] = 14;
	graph[4][3] = 9;
	graph[4][6] = 20;
	graph[5][4] = 7;
	graph[5][6] = 4;
	cout << "res:"<<getMaxFlow(6, graph, 1, 6);*/
	return 0;
}