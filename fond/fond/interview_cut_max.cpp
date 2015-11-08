#include"fond.h"
int store[1000];
int storeIndex = 0;
void getCutMax(int*p, int n, int c)
{
	int i, maxIndex = 0, max = *p;
	if (c == 0 || c == n)
	{
		if (c == 0)
			for (i = 0; i < n; i++)
				store[storeIndex++] = p[i];
		cout << "result:" << endl;
		for (i = 0; i < storeIndex; i++)
			cout << store[i];
		storeIndex = 0;
		cout << endl;
		return;
	}


	for (i = 1; i < c + 1; i++)
	{
		if (p[i] > max)
		{
			max = p[i];
			maxIndex = i;
		}
	}
	c -= maxIndex;
	n = n - maxIndex - 1;
	store[storeIndex++] = max;
	p = p + maxIndex + 1;
	getCutMax(p, n, c);


}