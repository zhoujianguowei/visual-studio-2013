#include"fond.h"
#define MAXN 10000
#define N 8
void configureSolution();
void getSolutionDetail();
/*
8个人排队买票，4个人拿着10元，
4个人拿着20元，票价10元，售票处一开始没有钱,
请问能够顺利买票的排队方案数。
*/
int remain_10_count;
int ticket_10_order[N];
int ticket_10_index = 0;
int initial_consumer[] = { 10, 10, 10, 10, 20, 20, 20,20 };
bool bought[N];
int solution_count = 0;
int  solution_detail[MAXN][N/2];
//solution_pointer = solution_detail;


void initial()
{
	for (int i = 0; i < N; i++)
		ticket_10_order[i] = -1;
	remain_10_count = 0;
}
void getSolutionDetail()
{
	int i, j,k;
	for (i = 0; i < solution_count; i++)
	{
		cout << "Num:" <<(i + 1) << endl;
		j = 0;
		
		for (k = 0; k < N; k++)
		{
			if (k == solution_detail[i][j])
			{
				cout << "10 ";
				j++;
			}
			else
				cout << "20 ";
		}
		cout << endl;
	}
}
void try_buy(int count)
{
	for (int i = 0; i < N; i++)
	{
		if (!bought[i])
		{
			if (initial_consumer[i] == 10)
			{
				bought[i] = true;
				remain_10_count++;
				ticket_10_order[ticket_10_index++] = count;
				if (count < N-1)
					try_buy(count + 1);
				else
				{
					configureSolution();
				}
				bought[i] = false;
				remain_10_count--;
				ticket_10_index--;

			}
			else if (initial_consumer[i] == 20)
			{
				if (remain_10_count < 1)
					return;
				remain_10_count--;
				bought[i] = true;
				if (count < N-1)
					try_buy(count + 1);
				else
				{
					configureSolution();
				}
				bought[i] = false;
				remain_10_count++;
			}
		}
	}

}
void configureSolution()
{
	int i, j;
	if (solution_count == 0)
	{
		for (j = 0; j < N/2; j++)

			solution_detail[solution_count][j] = ticket_10_order[j];
		solution_count++;
		return;

	}
	for (j = 0; j < solution_count; j++)
	{
		for (i = 0; i < N/2; i++)
			if (solution_detail[j][i] != ticket_10_order[i])
				break;
		if (i == N/2)
			break;
	}

	if (j == solution_count)
	{
		for (j = 0; j < N/2; j++)
			solution_detail[solution_count][j] = ticket_10_order[j];
		solution_count++;
	}
	//tail_solution = solution_detail[solution_count++];


	//cout << solution_count << ":" << endl;
}
int main_buy_ticket()
{

	try_buy(0);
	getSolutionDetail();
	//cout << "solution count:" << solution_count;
	return 0;
}