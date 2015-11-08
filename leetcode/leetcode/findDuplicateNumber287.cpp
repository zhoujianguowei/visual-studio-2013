#include"leetcode.h"
int findDuplicate(vector<int>& nums)
{
	if (nums.empty())
		return 0;
	int previous=nums[0];
	quick_sort(nums,0,nums.size()-1);
	for (unsigned int i = 0; i < nums.size(); i++)
	{
		if (i > 0 && nums[i] == previous)
			break;
		previous = nums[i];
		
	}
	return previous;
}