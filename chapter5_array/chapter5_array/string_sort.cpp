#include"chapter5_array.h"
string ready_str_array[1000];
void string_sort(int str_n)
{
	int i = 0, j, min_index=0,n;
	string min_str;
	bool changed = false;
	while (i<str_n)
	{
		cin >> ready_str_array[i++];
	}
	for (i = 0; i < str_n - 1; i++)
	{
		changed = false;
		for (j = i; j < str_n; j++)
		{
			if (ready_str_array[j]<ready_str_array[min_index])
			{
				min_str = ready_str_array[j];
				min_index = j;
				changed = true;
			}
		}
		if (changed)

		{
			ready_str_array[min_index] = ready_str_array[i];
			ready_str_array[i] = min_str;
		}
	}
	cout << "output:" << endl;
	for (i = 0; i < str_n; i++)
		cout << ready_str_array[i] << "  ";

}