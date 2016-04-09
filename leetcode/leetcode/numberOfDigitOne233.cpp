#include"leetcode.h"
/*
Given an integer n, count the total number of digit 1 appearing in all non-negative integers less than or equal to n.

For example:
Given n = 13,
Return 6, because digit 1 occurred in the following numbers: 1, 10, 11, 12, 13.
*/
int digitOneCombination(int numLength, int k)
{
	int combination = getDistinctCombination(numLength, k);
	return combination*(int)pow(9, numLength - k);
}
int countDigitOne(int n)
{
	int i = 1,j,sum=0;
	string digitStr;
	for (i = 1; i <= n; i++)
	{
		digitStr = intParseStr(i);
		for (j = 0; j < digitStr.size(); j++)
			if (digitStr.at(j) == '1')
				sum++;
	}
	return sum;

}