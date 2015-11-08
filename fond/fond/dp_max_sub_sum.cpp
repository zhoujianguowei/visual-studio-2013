#include"fond.h"
int dpGetMaxSubSum(vector<int> nums)
{
	if (nums.size() < 1)
		return 0;
	int max = nums[0], sum = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		sum += nums[i];
		max = max < sum ? sum : max;
		if (sum < 0)
		{
			sum = 0;
		}
	}
	return max;

}