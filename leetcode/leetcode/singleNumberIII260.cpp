#include"leetcode.h"
/*
Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once.

For example:

Given nums = [1, 2, 1, 3, 2, 5], return [3, 5].

Note:
The order of the result is not important. So in the above example, [5, 3] is also correct.
Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?
*/
vector<int> singleNumberIII(vector<int>& nums)
{
	unordered_map<int, int> unMap;
	unordered_map<int, int>::iterator mapIte;
	bool *repeatFlag=new bool[nums.size()];
	memset(repeatFlag, false, sizeof(repeatFlag));
	for (int i = 0; i<nums.size(); i++)
	{
		if (unMap.size() == 0)
		{
			unMap.insert(make_pair(nums[i], i));
			continue;
		}
		mapIte = unMap.find(nums[i]);
		if (mapIte != unMap.end())
		{
			repeatFlag[mapIte->second] = true;
			repeatFlag[i] = true;
		}
		else
			unMap.insert(make_pair(nums[i], i));

	}
	vector<int> res;
	for (int i = 0; i<nums.size(); i++)
	{
		if (repeatFlag[i] == false)
			res.push_back(nums[i]);
	}
	return res;
}