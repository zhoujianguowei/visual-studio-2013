#include"leetcode.h"
/*
Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.

For example, given n = 12, return 3 because 12 = 4 + 4 + 4; given n = 13, return 2 because 13 = 4 + 9.
*/
/*
there are more than three methods ,one is simple and efficient but you have to acquire number theory ,
here provide a traditional solution -dp
*/

int numSquares(int n)
{
	vector<int> res;
	res.push_back(0);
	while (res.size() <= n)
	{
		int m = res.size();
		int val = m;
		for (int i = 1; i*i <= m; i++)
		{
			val = min(val,res[m - i*i] + 1);
		}
		res.push_back(val);
	}
	return res[n];
}