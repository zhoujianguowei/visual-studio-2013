#define _CRT_SECURE_NO_WARNINGS
#include<cstdio> 
#include <iostream> 
//#include<stdio.h>

const int N = 1000;
int f[N], rank[N];

inline void init(int n)
{
	for (int i = 0; i <= n; ++i)
		f[i] = i, rank[i] = 0;
}

int find(int x)
{
	if (x == f[x])return x;
	int fa = f[x];
	f[x] = find(f[x]);
	rank[x] = (rank[x] + rank[fa]) % 2;
	return f[x];
}

inline bool Union(int x, int y, int D)
{
	int a = find(x), b = find(y);
	if (a == b)
	{
		if (D == 0 && rank[x] != rank[y]) return false;
		if (D == 1 && rank[x] == rank[y]) return false;
	}
	else
	{
		f[b] = a;
		rank[b] = (rank[x] + D - rank[y] + 2) % 2;
	}
	return true;
	/*if (D == 1){
	rank[a] = (rank[y] - rank[x] + 1) % 2;
	}
	else{
	rank[a] = (rank[y] - rank[x]) % 2;
	}
	return true;*/

}

int main_butterfly()
{
	int n, m;


	while (scanf("%d %d\n", &n, &m) > 0)
	{
		bool ok = true;
		init(n);
		for (int k = 0; k < m; k++)
		{
			int x, y, d;
			scanf("%d %d %d", &x, &y, &d);
			if (!Union(x, y, d)) { ok = false; }
		}
		if (ok) printf("YES\n");
		else printf("NO\n");
	}

	return 0;
}