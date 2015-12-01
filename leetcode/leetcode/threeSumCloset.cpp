#include"leetcode.h"
/*
Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

For example, given array S = {-1 2 1 -4}, and target = 1.

The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/
int getDiff(vector<int> nums, int firstIndex, int target)
{
	int high = nums.size() - 1;
	int low = firstIndex;
	int diff = nums[high] + nums[low]+target;
	while (high>low)
	{ 
		int twoSumDiff= nums[high] + nums[low]+target;
		if (twoSumDiff == 0)
			return 0;
		else if (twoSumDiff>=diff)
		{ 
			if (diff > 0)
				high--;
			else
			{
				if (twoSumDiff < 0)
				{
					low++;
					diff = twoSumDiff;
				}
				else
				{
					high--;
					diff = abs(twoSumDiff)>abs(diff) ? diff : twoSumDiff;
				}

			}
		}
		else
		{
			if (diff < 0)
			{
				low++;
			}
			else
			{
				if (twoSumDiff > 0)
				{
					high--;
					diff = twoSumDiff;
				}
				else
				{
					low++;
					diff = abs(twoSumDiff) > abs(diff) ? diff : twoSumDiff;
				}
			}

		}
	}
		return diff;

}
int threeSumClosest(vector<int>& nums, int target)
{
	if (nums.size() == 0)
		return target;
	int i, j,sum=0;
	if (nums.size() <= 3)
	{
		for (i = 0; i < nums.size(); i++)
			sum += nums[i];
			return sum;
	}

	quick_sort(nums);
	sum =nums[0] + nums[1] + nums[2];
	int diff = sum - target;
	for (i = 0; i < nums.size() - 2; i++)
	{
		int tempDiff = getDiff(nums,i+1, nums[i]-target);
		if (abs(tempDiff) <abs(diff))
			diff = tempDiff;
	}
	return target + diff;

}