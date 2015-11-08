#include<iostream>
using namespace std;
void swap(int&, int&);
#define MAXN 100001   //数组从0开始
int array[MAXN];
void swap(int &a, int&b)
{
	int temp = a;
	a = b;
	b = temp;
}
void adjust_min_tree(int a[], int i, int size)
{
	int j = 2 * i;
	while (j <= size)
	{
		if (j + 1 <= size&&a[j] > a[j + 1])
		{
			j = j + 1;
		}
		if (a[i] > a[j])
		{
			swap(a[i], a[j]);
			i = j;
			j = 2 * i;
		}
		else
			break;
	}
}
void add_item(int a[], int m, int *size)
{
	(*size)++;
	int j = *size;
	int i = *size / 2;
	a[j] = m;
	while (i >= 1)
	{
		if (a[j] < a[i])
		{
			swap(a[i], a[j]);
			j = i;
			i = j / 2;
		}
		else
			break;
	}
}
int del_min(int a[], int *size)
{
	int j = *size;
	int min = a[1];
	swap(a[1], a[*size]);
	(*size)--;
	adjust_min_tree(a, 1, *size);
	return min;
}

void print_array(int* a, int size)
{
	int i = 1;
	cout << "array: ";
	for (; i <= size; i++)
		cout << *(a + i) << "   ";

}
int main_min_tree()
{
	int t, n, type;

	cin >> t;
	while (t--)
	{
		int array_count = 0;
		cin >> n;
		while (n--)
		{
			cin >> type;
			int u;
			if (type == 1)
			{
				cin >> u;
				add_item(array, u, &array_count);
			}
			else if (type == 2)
				cout<<del_min(array, &array_count)<<endl;

		}
	}
	return 0;

}
