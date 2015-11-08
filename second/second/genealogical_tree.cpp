#include<iostream>
using namespace std;
#define N 100
int in_degree[N + 1];
bool graph[N + 1][N + 1];
bool visited[N + 1];
void init(int n)
{
	int i = 0;
	int a;
	while (n--)
	{
		i++;
		while (1)
		{
			cin >> a;
			if (a == 0)
				break;
			graph[i][a] = true;
			//graph_content[i][j] = a;
		}

	}
}
void computer_in_degree(int n)
{
	int i = 1, j = 1;
	for (; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			if (graph[i][j])
				in_degree[j]++;
		}
	}

}
int main_genealogical_tree()
{
	int n;
	cin >> n;
	init(n);
	computer_in_degree(n);
	int visited_count = 0;
	while (visited_count < n)
	{
		int zero_degree = -1;
		for (int i = 1; i <= n; i++)
			if (in_degree[i] == 0 && !visited[i])
			{
				zero_degree = i;
				break;

			}
		/*if (zero_degree == -1)
			exit(-1);*/
		cout << zero_degree << " ";
		visited[zero_degree] = true;
		visited_count++;
		for (int j = 1; j <= n; j++)
		{
			if (graph[zero_degree][j])
			{
				graph[zero_degree][j] = false;
				in_degree[j]--;
			}
		}

	}

	return 0;
}
