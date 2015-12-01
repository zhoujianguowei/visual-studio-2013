#include"leetcode.h"
int getMax(vector<int> nums)
{
	if (nums.size() < 1)
		return 0;
	int max = nums[0];
	for (int i = 1; i < nums.size(); i++)
		max = nums[i]>max ? nums[i] : max;
	return max;
}
int firstMissingPositive(vector<int>& nums)
{
	int max = getMax(nums);
	int *filter = new int[max];
	memset(filter, -1, sizeof(int)*max);
	int index = -1,i=0;
	for (; i < nums.size(); i++)
		if (nums[i] >= 1 && nums[i]<=max)
		filter[nums[i] - 1] = 1;
	for (i = 0;i<max;i++)
		if (filter[i] != 1)
		{
			index = i;
			break;
		}
	delete filter;
	return i == max ? (max + 1) : (index + 1);
}