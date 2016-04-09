#include"leetcode.h"
/*
Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

For example,
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

Your algorithm should run in O(n) complexity.
*/
int longestConsecutive(vector<int>& nums)
{
	if (nums.size() == 0)
		return 0;
	int maxConsLength=0;
	int tempMax = 0;
	int i = 0;
	unordered_set<int> unSet;
	for (; i < nums.size(); i++)
		unSet.insert(nums[i]);
	while (!unSet.empty())
	{
		tempMax = 0;
		int value = *unSet.begin();
		tempMax++;
		int temp = value; 
		value++;
		while (unSet.find(value) != unSet.end())
		{
			unSet.erase(value);
			tempMax++;
			value++;
		}
		value = temp - 1;
		while (unSet.find(value) != unSet.end())
		{
			unSet.erase(value);
			tempMax++;
			value--;
		}
		unSet.erase(temp);
		maxConsLength = maxConsLength < tempMax ? tempMax : maxConsLength;
	}
	return maxConsLength;


}