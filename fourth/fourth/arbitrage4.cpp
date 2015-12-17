#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<iomanip>
#include<vector>
#include<memory.h>
#include<map>
#include<string>
using namespace std;
const int N=30;
double graph[N][N];
bool *visited;
double dfs(int v,int pre,int n,double rate)
{
	if (!visited[v])
	{
		return rate;
	}
	int i = 0;
	double res = 0.0f;
	for (; i < n; i++)
	{
		if (i != v&&visited[i])
			continue;
		if (graph[pre][i]>0)
		{
			rate *= graph[pre][i];
			if (i != v)
				visited[i] = true;
			else
				visited[i]=false;
			res = dfs(v, i, n, rate);
			if (res < 1)
			{
				visited[v] = true;
				rate /= graph[pre][i];
				continue;
			}
			else
				return res;
		}
	}
	return 0;
}
string isBeneficial(int n)
{
	int i, j;
	bool isValid = false;
	for (i = 0; i < n; i++)
	{
		visited= new bool[n];
		memset(visited, false, n*sizeof(bool));
		visited[i] = true;
		if (dfs(i, i, n, 1.0)>1)
		{
			isValid = true;
			break;
		}
	}
	if (isValid)
		return "Yes";
	else
		return "No";
}
int main()
{
	int n, m;
	int testNum = 1;
	while (cin>>n&&n)
	{
		int i = 0;
		map<string,int> uMap;
		while (i < n)
		{
			string currency;
			cin >> currency;
			uMap.insert(make_pair(currency, i));
			i++;
		}
		for (i = 0; i < n; i++)
			memset(graph[i], 0.0f, sizeof(graph[i]));
		cin >> m;
		while (m--)
		{
			string srcStr, desStr;
			double rate;
			cin >> srcStr >> rate >> desStr;
			int head = uMap.find(srcStr)->second;
			int tail = uMap.find(desStr)->second;
			graph[head][tail] = rate;
		}
		cout <<"Case "<<testNum<<": "<<isBeneficial(n)<<endl;
		testNum++;
	}
	return 0;
}