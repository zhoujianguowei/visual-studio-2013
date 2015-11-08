#include"leetcode.h"
#define SPLIT '\v'
string longestPalindrome(string s)
{
	if (s.length() <= 1)
		return s;
	string res,temp;
	int i, j,count=0;
	
	for (i = 0; i < s.length(); i++)
	{
		j = i - 1;
		int tempCount = 1;
		for (; j >= 0 && 2 * i - j < s.length(); j--)
			if (s.at(j) == s.at(2 * i - j))
				tempCount+=2;
			else
			{
				break;
			}
		if (tempCount > count)
		{
			count = tempCount;
			temp = s.substr(i-tempCount/2, tempCount);
		}
		tempCount = 0;
		for (j = i; j >= 0 && 2 * i - j + 1 < s.length(); j--)
			if (s.at(j) == s.at(2 * i - j + 1))
				tempCount += 2;
			else
				break;
		if (tempCount > count)
		{
			count = tempCount;
			temp = s.substr(i - tempCount / 2+1, tempCount);
		}
	}

	return temp;
}