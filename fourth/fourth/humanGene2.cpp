#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<iomanip>
#include<vector>
#include<memory.h>
#include<map>
#include<string>
using namespace std;
int score[5][5] = { { 5, -1, -2, -1, -3 }, { -1, 5, -3, -2, -4 },
{ -2, -3, 5, -2, -2 }, { -1, -2, -2, 5, -1 }, { -3, -4, -2, -1,0 }};
map<char, int> omap;
const int N = 110;
int matrix[N][N];
int getMax(int x, int y)
{
	return x > y ? x : y;
}
int getMaxScore(string src, string des)
{
	int i, j;
	for (i = 1; i <=src.length(); i++)
		for (j = 1; j <= des.length(); j++)
		{
			int a = omap.find(src.at(i-1))->second;
			int b = omap.find(des.at(j-1))->second;
			int c = omap.find('-')->second;
			int rowMatch = matrix[i][j-1] + score[c][b];
			int colMatch = matrix[i-1][j] + score[a][c];
			int rowCol = matrix[i-1][j-1] + score[a][b];
			matrix[i][j] = getMax(rowMatch, getMax(colMatch, rowCol));
		}
	return matrix[src.length()][des.length()];
}

int third_main()
{
	int n, i = 0;
	char vertext[5] = { 'A', 'C', 'G', 'T', '-' };
	for (i = 0; i < 5; i++)
		omap.insert(make_pair(vertext[i], i));
	i = 0;
	cin>> n;
	while (n--)
	{
		int srcLen, desLen;
		string src, des;
		cin >> srcLen >> src;
		cin >> desLen >> des;
		matrix[0][0] = 0;
		for (i = 1; i<=srcLen; i++)
		{
			matrix[i][0]=matrix[i-1][0]+score[omap.find(src.at(i-1))->second][omap.find('-')->second];
		}
		for (i = 1; i <=desLen; i++)
			matrix[0][i]=matrix[0][i-1]+score[omap.find('-')->second][omap.find(des.at(i-1))->second];
		cout << getMaxScore(src, des)<<endl;
	}
	return 0;
}

