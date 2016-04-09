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
/*
it's a wrong attemp,as in fact ,if a dfs path has visited a vertex ,it may be visted again
*/
string isBeneficial(int n)
{
	int i, j,k;
	bool isValid = false;
	for (k = 0; k < n; k++)
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
			{
				if (graph[i][j] < graph[i][k] * graph[k][j])
					graph[i][j] = graph[i][k] * graph[k][j];
			}
	for (i = 0; i < n; i++)
		if (graph[i][i]>1)
		{
			isValid = true;
			break;
		}
	if (isValid)
		return "Yes";
	else
		return "No";
}
int fourth_main()
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