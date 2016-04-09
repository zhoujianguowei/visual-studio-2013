#include"leetcode.h"
map<int, int> nums_map;
vector<vector<int>> get_sub_set(vector<vector<int>> &global_res, vector<int> nums, int k)
{
	vector<vector<int>> local_res;
	vector<int> sub_res;
	int n = nums.size();
	if (k == 1)
	{
		for (int i = 0; i < n; i++)
		{
			sub_res.push_back(nums[i]);
			local_res.push_back(sub_res);
			global_res.push_back(sub_res);
			sub_res.clear();
		}
		return local_res;
	}
	else
	{
		vector<vector<int>>  preRes = get_sub_set(global_res, nums, k - 1);
		for (int i = 0; i < preRes.size(); i++)
		{
			map<int, int>::iterator nums_map_iterator = nums_map.find(preRes[i].back());
			int beginIndex = nums_map_iterator->second+1;
			while (beginIndex < n)
			{
				sub_res = preRes[i];
				sub_res.push_back(nums[beginIndex]);
				local_res.push_back(sub_res);
				global_res.push_back(sub_res);
				sub_res.clear();
				beginIndex++;
			}
		}
		return local_res;
	}
}
void init_nums_map(vector<int> nums)
{
	for (int i = 0; i < nums.size(); i++)
	{
		nums_map.insert(make_pair(nums[i], i));
	}
}
vector<vector<int>> subsets(vector<int>& nums)
{
	vector<vector<int>> global_res;
	vector<int> empty;
	quick_sort(nums);
	init_nums_map(nums);
	global_res.push_back(empty);
	get_sub_set(global_res, nums, nums.size());
	return global_res;
}