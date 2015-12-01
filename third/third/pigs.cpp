#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<memory.h>
#include<vector>
#include<queue>
#include<stdlib.h>
#include<stdio.h>
#define MAX_INT 0x3f3f3f3f
#define MAXM 1002       // the number of pighouse
#define MAXN 102         //# of customer
using namespace std;
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
		for (int i = 0; i <= v; i++)
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
	for (i = 0; i <= v; i++)
		for (j = 0; j <= v; j++)
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
	int M, N;  
	int graph[MAXN][MAXN];
	while (scanf("%d %d", &M, &N)>0)
	{

		int i, j;
		int k, key;
		int pigs[MAXM];
		int visted[MAXM];
		memset(graph, 0, sizeof(graph));
		memset(visted, 0, sizeof(visted));
		for (i = 1; i <= M; i++)
			scanf("%d", &pigs[i]);
		for (i = 1; i <= N; i++)
		{
			scanf("%d", &k);
			for (j = 1; j <= k; j++)
			{
				scanf("%d", &key);
				if (!visted[key])
					graph[0][i] += pigs[key];//源点为0，当某个猪圈第一次打开时，在源点与顾客之间建立边
				else
					graph[visted[key]][i] = MAX_INT;//猪圈不是第一次打开，在该顾客与上一个打开该猪圈的顾客之间建立边
				visted[key] = i;
			}
			scanf("%d", &key);
			graph[i][N + 1] = key;//汇点为N+1，在顾客与汇点之间建立边
		}
		cout << getMaxFlow(N + 1, graph, 0, N + 1);
	}
	
	return 0;
}