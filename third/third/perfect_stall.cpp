#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<memory.h>
#include<vector>
#include<queue>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
#define MAX_INT 0x3f3f3f3f 
#define COWN 201
#define STALLM 201
bool stallChe[STALLM];

bool hasCrossPath(int k, int graph[COWN][COWN], int cowPair[COWN], int n, int stallPair[STALLM], int m)
{
	for (int i = 1; i <= m; i++)
	{
		if (graph[k][i] == 1 && !stallChe[i])
		{
			stallChe[i] = true;
			if (stallPair[i] == -1 || hasCrossPath(stallPair[i], graph, cowPair, n, stallPair,m))
			{
				cowPair[k] = i;
				stallPair[i] = k;
				return true;
			}
		}

	}
	return false;

}
/*
n和m分别是牛的个数，牛栏的个数
*/
int getMaxPairs(int graph[COWN][COWN], int n, int m)
{
	int cowPair[COWN], stallPair[STALLM];
	memset(cowPair, -1, sizeof(int)*(n+1));
	memset(stallPair, -1, sizeof(int)*(m+1));
	int countPairs = 0;
	int i = 1;
	for (; i <=n; i++)
	{
		memset(stallChe, false, sizeof(stallChe));
		if (hasCrossPath(i, graph, cowPair, n, stallPair, m))
			countPairs++;
	}
	return countPairs;
}
int perfect_stall_main()
{
	int N, M;
	int graph[COWN][COWN];
	while (scanf("%d%d", &N, &M) > 0)
	{
		int rowIndex = 1;
		int tempN = N;
		memset(graph, -1, sizeof(graph));
		while (tempN--)
		{
			int stallCount, stallNum;
			cin >> stallCount;
			while (stallCount--)
			{
				cin >> stallNum;
				graph[rowIndex][stallNum] = 1;
			}
			rowIndex++;
		}
		cout << getMaxPairs(graph, N, M) << endl;
		
	}
	return 0;
}