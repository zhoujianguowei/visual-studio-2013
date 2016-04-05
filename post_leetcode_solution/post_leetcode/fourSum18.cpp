#include"post_leetcode.h"
vector<vector<int>> fourSum(vector<int>& nums, int target)
{
	vector<vector<int>> res;
	if (nums.size() < 4)
		return res;
	quick_sort(nums);
	int i,j;
	int current;
	int size = nums.size();
	int previous = *(nums.end()-1);
	for (i = size-1; i >2; i--)
	{
		current = nums[i];
		//skip duplication,and ensure nums[i]==nums[i+1] be used only once
		if (i < size - 1 && previous == current)
		{
			nums.erase(nums.end() - 1);
			continue;
		}
		previous = nums[i];
		nums.erase(nums.end() - 1);
		vector<vector<int>> threeSumRec = threeSum(nums, target-current);
		for (j = 0; j < threeSumRec.size(); j++)
		{
			vector<int> subThreeSumVec = threeSumRec.at(j);
			subThreeSumVec.push_back(current);
			res.push_back(subThreeSumVec);
		}

	}
	return res;
}