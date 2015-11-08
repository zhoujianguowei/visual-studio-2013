#include"leetcode.h"
/*
采用夹逼原则求出有序的两个数之和等于另外一个数字
*/
vector<vector<int>> getTwoSum(vector<int> nums, int left, int right, int target)
{
	vector<vector<int>> result;
	vector<int> currentTrip;
	while (left < right)
	{
		if (nums[left] + nums[right] == target)
		{
			vector<int> temp;
			temp.push_back(nums[left]);
			temp.push_back(nums[right]);
			if (!currentTrip.empty() && currentTrip[0] == temp[0] && currentTrip[1] == temp[1])
			{
				left++;
				continue;

			}
			result.push_back(temp);
			currentTrip = temp;
			left++;
		}
		else if (nums[left] + nums[right] < target)
			left++;
		else
			right--;
	}
	return result;
}
vector<vector<int>> threeSum(vector<int>& nums)
{
	/*if (nums.size() < 3)
		return null;*/
	vector<vector<int>> result;

	/*bool isOver = false;*/
	unsigned int i, j;
	if (nums.size() < 3)
		return result;
	quick_sort(nums, 0, nums.size() - 1);
	
	//sort(nums.begin(), nums.end()); 
	/*for (i = 0; i < nums.size() - 2&&nums[i]<=0; i++)
		for (j = i + 1; j < nums.size() - 1; j++)
		{
			int twoSum = nums[i] + nums[j];
			if (twoSum > 0)
			{
				break;

			}
			for (k = j + 1; k < nums.size(); k++)
			{
				vector<int> temp;
				int threeSum = nums[i] + nums[j] + nums[k];
				if (threeSum == 0)
				{
					temp.push_back(nums[i]);
					temp.push_back(nums[j]);
					temp.push_back(nums[k]);
					unsigned int m = 0;
					for (; m < temp.size() && previousVector.size()>0; m++)
						if (temp[m] != previousVector[m])
							break;
					if (m != temp.size())
					{
						result.push_back(temp);
						previousVector = temp;
					}

				}
				else if (threeSum > 0)
				{
					break;
				}
				
			}
		}*/

	for (i = 0; i < nums.size() - 2; i++)
	{
		if (i > 0 && nums[i] == nums[i - 1])
			continue;
		vector<vector<int>> twoVector = getTwoSum(nums, i + 1, nums.size() - 1, 0 - nums[i]);
		if (!twoVector.empty())
		{
			for (j = 0; j < twoVector.size(); j++)
			{
				
				vector<int > temp;
				vector<int> subTwoVector = twoVector[j];
				temp.push_back(nums[i]);
				temp.push_back(subTwoVector[0]);
				temp.push_back(subTwoVector[1]);
				result.push_back(temp);
			}

		}
	}

	return result;

}
