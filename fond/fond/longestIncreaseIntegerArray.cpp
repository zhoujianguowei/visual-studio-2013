#include"fond.h"

void reversePrintVec(vector<int> result)
{
	cout << "\n"<<"result array:" << endl;
	for (int i = result.size() - 1; i >= 0; i--)
		cout << result[i] << "  ";
	cout << endl;
}
int getLongestArray(vector<int> nums)
{
	vector<int> maxTail;
	maxTail.resize(nums.size() + 1, INT_MIN);
	vector<int> opt;
	opt.resize(nums.size() + 1);
	int i, j;
	for (i = 1; i < opt.size(); i++)
	{
		int maxLength = 0;
		int maxSub = INT_MIN;
		for (j = 0; j < i; j++)
		{
			if (maxTail[j] <= nums[i - 1])
			{
				if (opt[j] + 1>maxLength)
				{
					maxLength = opt[j] + 1;
				}
			}

		}
		if (maxLength > opt[i - 1])
			maxSub = nums[i - 1];
		else
		{
			maxSub = nums[i - 2];
			maxLength = opt[i - 1];
		}
		opt[i] = maxLength;
		maxTail[i] = maxSub;
	}
	vector<int> result;
	for (int i = nums.size(); i>=1; i--)
	{
		if (opt[i] == opt[i - 1])
			continue;
		else
			result.push_back(nums[i - 1]);

	}
	reversePrintVec(result);
	return opt[nums.size()];
}
