#include"chapter5_array.h"
int flagArray[100000];
void sort_order( int up_bound)
{
	//int flagArray[up_bound];
	int i, j, count = 0;
	for (i = 2; i <= up_bound; i++)
	{
		for (j = 2 * i; j <= up_bound; j += i)
		{
			flagArray[j] = 1;
		}
	}
	for (i = 2; i <= up_bound; i++)
	{
		if (flagArray[i] == 0)
		{
			count++;
			cout << i << "   ";
		if (!(count % 10))
			cout << endl;
		}


	}
	cout << endl;

}