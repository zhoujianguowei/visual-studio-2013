#include"leetcode.h"
#define minValue(x,y)(x)>(y)?(y):(x)
/*
Write a program to find the n-th ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For example, 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.

Note that 1 is typically treated as an ugly number.
*/

int nthUglyNumber(int n)
{
	list<int> res;
	res.push_back(1);
	list<int>::iterator l1 = res.begin();
	list<int>::iterator l2 = res.begin();
	list<int>::iterator l3 = res.begin();
	int next = res.back() + 1;
	int min;
	for (int i = 2; i <= n; i++)
	{
		while (*l1 * 2 < next)
			l1++;
		while (*l2 * 3 < next)
			l2++;
		while (*l3 * 5 < next)
			l3++;
		min = minValue(*l1*2, minValue(*l2*3, *l3*5));
		res.push_back(min);
		next = res.back() + 1;
	}
	return res.back();
}