/*
* Dinic algo for max flow
*
* This implementation assumes that #nodes, #edges, and capacity on each edge <= INT_MAX,
* which means INT_MAX is the best approximation of INF on edge capacity.
* The total amount of max flow computed can be up to LLONG_MAX (not defined in this file),
* but each 'dfs' call in 'dinic' can return <= INT_MAX flow value.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <assert.h>
#include <queue>
#include <vector>

#define N (100+2)
#define M (N*N+4*N)

typedef long long LL;

using namespace std;

struct edge
{
	int v, cap, next;
};
edge e[M];

//cur主要用来记录网络流的路径，用来指明s-t路径的父亲节点。类似于parent，不过应对的是层次网络
int head[N], level[N], cur[N]; // the array of head denotes the id of edge,beginning from index 0
int num_of_edges;

/*
* When there are multiple test sets, you need to re-initialize before each
*/
void dinic_init(void)
{
	num_of_edges = 0;
	memset(head, -1, sizeof(head));
	return;
}

/*
采用邻接表的形式构建图，不过不同于传统的邻接表构件形式，
next指向的是要添加的边的id，同时也创建了逆向邻接表，主要是用来构造
剩余图-residual graph,c1是边e(u,v)上面的权，c2是边e'(v,u)上面的权
head[u]是传统邻接表创建方式中的以u为弧尾（箭头指向的是弧头）的第一条边的id编号
*/
int add_edge(int u, int v, int c1, int c2)
{
	int& i = num_of_edges;

	//断言设置，如果不满足条件，程序直接退出
	assert(c1 >= 0 && c2 >= 0 && c1 + c2 >= 0); // check for possibility of overflow
	e[i].v = v;
	e[i].cap = c1;
	e[i].next = head[u];
	head[u] = i++;

	e[i].v = u;
	e[i].cap = c2;
	e[i].next = head[v];
	head[v] = i++;
	return i;
}

void print_graph(int n)
{
	for (int u = 0; u < n; u++)
	{
		printf("%d: ", u);
		for (int i = head[u]; i >= 0; i = e[i].next)
		{
			printf("%d(%d)", e[i].v, e[i].cap);
		}
		printf("\n");
	}
	return;
}

/*
* Find all augmentation paths in the current level graph
* This is the recursive version
*/
int dfs(int u, int t, int bn)
{
	if (u == t) return bn;
	int left = bn;
	for (int i = head[u]; i >= 0; i = e[i].next)
	{
		int v = e[i].v;
		int c = e[i].cap;
		if (c > 0 && level[u] + 1 == level[v])
		{
			int flow = dfs(v, t, min(left, c));
			if (flow > 0)
			{
				e[i].cap -= flow;
				e[i ^ 1].cap += flow;           //由于正向边的id都是偶数设为2*i,
				                                //二进制最低位为0,对应的逆向边为2*i+1,i^1其实就等于2*i+1
				cur[u] = v;
				left -= flow;
				if (!left) break;              //flow已经达到上限，跳出循环，同时返回flow上限
			}
		}
	}
	if (left > 0) level[u] = 0;        //从s->u的路径上面的所有边的权值都大于(bn-left),下次dfs不再经过u
	return bn - left;   //实际上就是返回的就是flow
}

bool bfs(int s, int t)
{
	memset(level, 0, sizeof(level));
	level[s] = 1;
	queue<int> q;
	q.push(s);
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		if (u == t) return true;
		for (int i = head[u]; i >= 0; i = e[i].next)
		{
			int v = e[i].v;
			if (!level[v] && e[i].cap > 0)
			{
				level[v] = level[u] + 1;
				q.push(v);
			}
		}
	}
	return false;
}

LL dinic(int s, int t)
{
	LL max_flow = 0;

	while (bfs(s, t))
	{
	
		memcpy(cur, head, sizeof(head));
		max_flow += dfs(s, t, INT_MAX);
	}
	return max_flow;
}

int upstream(int s, int n)
{
	int cnt = 0;
	vector<bool> visited(n);
	queue<int> q;
	visited[s] = true;
	q.push(s);
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		for (int i = head[u]; i >= 0; i = e[i].next)
		{
			int v = e[i].v;
			if (e[i].cap > 0 && !visited[v])
			{
				visited[v] = true;
				q.push(v);
				cnt++;
			}
		}
	}
	return cnt; // excluding s
}

int main()
{
	int m, n, s, t;
	int pig[M + 1], pre[M + 1];//pre用来标记第pig stall是否已经有人有了钥匙
	bool con[N + 1];
	FILE *fin;

	/*fin = fopen("pigs.dat", "r");
	assert(fin);*/
	fin = stdin;

	fscanf(fin, "%d %d", &m, &n);
	dinic_init();
	s = 0, t = n + 1;
	for (int i = 1; i <= m; i++)
	{
		fscanf(fin, "%d", &pig[i]);
	}
	memset(pre, -1, sizeof(pre));
	for (int i = 1; i <= n; i++)
	{
		int nkeys;
		fscanf(fin, "%d", &nkeys);
		memset(con, 0, sizeof(con));
		int cap = 0;
		for (int j = 1; j <= nkeys; j++)
		{
			int ph;
			fscanf(fin, "%d", &ph);
			int cust = pre[ph];
			//第j个pig stall第一次被打开
			if (cust < 0)
			{
				cap += pig[ph];
			}
			//第j个pig stall已经被打开，在顾客之间建立一条权值为无穷大
			else if (!con[cust])
			{
				add_edge(cust, i, INT_MAX, 0);
			}
          //保存最近持有钥匙的人的信息，其实没必要更新
			pre[ph] = i;
		}
		if (cap > 0)
		{
			add_edge(s, i, cap, 0);
		}
		int npigs;
		fscanf(fin, "%d", &npigs);
		if (npigs > 0)
		{
			add_edge(i, t, npigs, 0);
		}
	}
	//print_graph(n+2);
	int flow = dinic(s, t);
	printf("%d\n", flow);

	return 0;
}
