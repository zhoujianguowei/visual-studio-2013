#define _CRT_SECURE_NO_WARNINGS
#include"fond.h"
#include <cstdio>
#include<algorithm>
#include <cstring>
#include <iostream>
#include <vector> 
#define max(a,b) (a)>(b)?(a):(b)
using namespace std;
int main()
{
	int f[100][100]; char s1[100]; char s2[100];
	int i, j, x, y, n;


	while (scanf("%d%s%d%s", &x, s1 + 1, &y, s2 + 1) > 0)
	{
	/*	memset(s1, 0, sizeof(s1));
		memset(s2, 0, sizeof(s2));*/
		memset(f, 0, sizeof(f));

		for (i = 1; i <= x; i++)
		{
			for (j = 1; j <= y; j++)
			{
				f[i][j] = max(f[i - 1][j], f[i][j - 1]);
				if (s1[i] == s2[j])
				{

					f[i][j] = max(f[i][j], 1 + f[i - 1][j - 1]);

				}
			}
		}
		int k = f[x][y];
		printf("%d", k);

	}
	system("pause");
	return 0;

}

