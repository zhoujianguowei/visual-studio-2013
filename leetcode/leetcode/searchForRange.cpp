#include"leetcode.h"
/*
Given a sorted array of integers, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].
*/
void binarySearch(vector<int> &nums, int low, int high, int target, vector<int> &res)
{
	int left = low, right = high, middle;
	while (left <= right)
	{
		middle = left + (right - left) / 2;
		if (nums[middle]<target)
			left = middle + 1;
		else if (nums[middle]>target)
			right = middle - 1;
		else
		{
			if (res.size()>0)
			{
				if (middle>res[1])
				{
					res.pop_back();
					res.push_back(middle);
				}
				if (middle<res[0])
				{
					int end = res[1];
					res.clear();
					res.push_back(middle);
					res.push_back(end);
				}
			}
			else
			{
				res.push_back(middle);
				res.push_back(middle);
			}
			binarySearch(nums, left, middle - 1, target, res);
			binarySearch(nums, middle + 1, right, target, res);
			return;
		}
	}
}
vector<int> searchRange(vector<int>& nums, int target)
{
	vector<int> res;
	if (nums.size() == 0)
	{
		res.push_back(-1);
		res.push_back(-1);
		return res;
	}
	if (nums.size() == 1)
	{
		if (nums[0] == target)
		{
			res.push_back(0);
			res.push_back(0);
		}
		else
		{
			res.push_back(-1);
			res.push_back(-1);
		}
		return res;
	}
	binarySearch(nums, 0, nums.size() - 1, target, res);
	if (res.size() == 0)
	{
		res.push_back(-1);
		res.push_back(-1);
	}
	return res;

}