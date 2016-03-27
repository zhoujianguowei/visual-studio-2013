#include"fond.h"
const int MAXN = 100;
void printMatrix(vector<vector<int>> matrix)
{
	for (int i = 0; i < matrix.size(); i++)
	{
		for (int j = 0; j < matrix[i].size(); j++)
			cout << matrix[i][j] << "  ";
		cout << endl;
	}

}
void getMatrix(int n)
{
	vector<vector<int>> result;
	vector<vector<int>> initR;
	vector<vector<int>> tempR;
	initR.resize(n);
	int i, j, k;
	for (i = 0; i <n; i++)
	{
		for (j = 0; j < n; j++)
		{
			int value;
			cin >> value;
			initR[i].push_back(value);
		}
	}
	tempR = initR;
	result = tempR;
	cout << "matrix:" << 1 << endl;
	printMatrix(initR);
	for (int count = 2; count < 20; count++)
	{
		cout << "matrix " << count << endl;
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
				for (k = 0; k < n; k++)
				{
					if (initR[i][k] + result[k][j] == 2)
					{
						tempR[i][j] = 1;
						break;
					}
				}
		result = tempR;
		printMatrix(result);
		cout << "***********************" << endl;
	}

}