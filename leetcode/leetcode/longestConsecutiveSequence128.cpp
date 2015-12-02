#include"leetcode.h"
vector<int> getMinMax(vector<int> &nums)
{
	int min = nums[0], max = nums[0];
	for (int i = 1; i<nums.size(); i++)
	{
		if (nums[i]>max)
			max = nums[i];
		if (nums[i]<min)
			min = nums[i];
	}
	vector<int> res;
	res.push_back(min);
	res.push_back(max);
	return res;
}
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
	vector<int> res = getMinMax(nums);
	int maxLength = res.back() - res.front() + 1;
	bool *filters = new bool[maxLength];
	memset(filters, false, maxLength*sizeof(bool));
	int i = 0;
	for (; i<nums.size(); i++)
		filters[nums[i] - res.front()] = true;
	int maxConsLength = 0;
	int tempMaxLength = 0;
	for (i = 0; i<maxLength; i++)
	{
		if (filters[i] == true)
			tempMaxLength++;
		else
		{
			maxConsLength = maxConsLength<tempMaxLength ? tempMaxLength : maxConsLength;
			tempMaxLength = 0;
		}
	}
	maxConsLength = maxConsLength<tempMaxLength ? tempMaxLength : maxConsLength;
	delete[] filters;
	return maxConsLength;

}