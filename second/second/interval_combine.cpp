#include<iostream>
using namespace std;
struct INTERVAL
{
	int left;
	int right;
};
#define MAXN 50000
INTERVAL intervals[MAXN];
inline void swap_interval(INTERVAL *a, INTERVAL *b)
{
	INTERVAL temp = *a;
	*a = *b;
	*b = temp;
}
int quick_sort(INTERVAL *p, int i, int j)
{
	INTERVAL mid = p[j];
	//INTERVAL temp;
	int left, right;
	left = i - 1;
	for (right = i; right < j; right++)
	{
		if ((p + right)->left <= mid.left)
		{
			left++;
			swap_interval(p + right, p + left);
		}
	}
	swap_interval(p + left + 1, p + j);
	return left + 1;

}
void partition(INTERVAL *p, int i, int j)
{
	if (i < j)
	{
		int temp = quick_sort(p, i, j);
		partition(p, i, temp - 1);
		partition(p, temp + 1, j);
	}
}
/*
方法二，算法复杂度只有n
*/
int main()
{
	int n;
	int i = 0;
	cin >> n;
	int min, max;
	int left,right;
	INTERVAL * p = intervals;
	while (i < n)
	{
		int a, b;
		cin >> a >> b;
		p[i].left = a;
		p[i].right = b;
		if (i == 0)
		{
			min = a;
			max = b;
			left = a;
			right = b;
		}
		else
		{
			if (a < min)
				min = a;
			if (b > max)
				max = b;
		}
		i++;
	}
	while (p - intervals < n)
	{


	}



}
int main_interval_combine()
{
	int n;
	int i = 0;
	cin >> n;
	while (i < n)
	{
		int a, b;
		cin >> a >> b;
		intervals[i].left = a;
		intervals[i].right = b;
		i++;
	}
	int left, right;
	partition(intervals, 0, n - 1);
	left = intervals[0].left;
	right = intervals[0].right;
	for (i = 1; i < n; i++)
	{
		if (intervals[i].left>right)
			break;
		else  if (intervals[i].right>right)
			right = intervals[i].right;
	}
	if (i == n)
		cout << left << " " << right;
	else
		cout << "no";
	return 0;
}