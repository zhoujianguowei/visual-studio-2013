#include<iostream>
using namespace std;
const int N = 8;
int result[N][N];
int col_limit[N];
int left_top_limit[2 * (N - 1) + 1];
int left_bottom_limit[2 * (N - 1) + 1];
int num;
void init()
{
	int i;
	for (i = 0; i < N; i++)
	{
		col_limit[i] = 1;
	}
	for (i = 0; i <= 2 * (N - 1); i++)
	{
		left_top_limit[i] = 1;
		left_bottom_limit[i] = 1;
	}
}
void get_result(int num)
{
	cout << "No. " << num<<endl;
	int i, j;
	for (j = 0; j < N; j++)
	{
		for (i = 0; i < N; i++)
		{
			cout << result[i][j] << " ";
		}
		cout << endl;
	}

}
void try_out(int i)
{
	//int recordColumn = -1;
	for (int j = 0; j < N; j++)
	{
		if (col_limit[j] & left_top_limit[i - j + 7] & left_bottom_limit[i + j])
		{
			result[i][j] = 1;
			col_limit[j] = 0;
			left_top_limit[i - j + 7] = 0;
			left_bottom_limit[i + j] = 0;
			if (i < N - 1)
				try_out(i + 1);
			else
			{
				num++;
				get_result( num);

			}
			/*if (num == 5)
				return;*/
			col_limit[j] = 1;
			left_top_limit[i - j + 7] = 1;
			left_bottom_limit[i + j] = 1;
			result[i][j] = 0;
		}
	}
}
int main()
{
	init();
	try_out(0);
	return 0;
}