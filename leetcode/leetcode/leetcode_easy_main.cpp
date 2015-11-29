#include"leetcode.h"
#pragma warning(disable:4146)
vector<string> summaryRanges(vector<int>& nums)
{
	vector<string> res;
	if (nums.size() == 0)
		return res;
	if (nums.size() == 1)
	{
		res.push_back(intParseStr(nums[0]));
		return res;
	}
	int first = nums[0];
	int second = -1;
	int i;
	string temp;
	for (i = 1; i < nums.size(); i++)
	{
		if (nums[i] == nums[i - 1] + 1)
		{
			if (i != nums.size() - 1)
				continue;
			else
			{
				second = nums[i];
				res.push_back(intParseStr(first) + "->" + intParseStr(second));
			}

		}
		else
		{
			second = nums[i - 1];
			if (first == second)
				res.push_back(intParseStr(first));
			else

				res.push_back(intParseStr(first) + "->" + intParseStr(second));
			first = nums[i];

		}
	}
	if (first > second)
		res.push_back(intParseStr(first));
	return res;
}
int main()
{
	vector<int> vec;
	vec.push_back(-2147483648);
	vec.push_back(-2147483647);
	vec.push_back(2147483647);
	summaryRanges(vec);

	return 0;
}

