#include"fond.h"
vector<int> getMaxVector(vector<int> a, vector<int> b)
{
	if (a[2] > b[2])
		return a;
	else
		return b;
}
vector<int> maxSubSum(vector<int> &nums, int left, int right)
{
	vector<int> res;
	if (left == right)
	{
		res.push_back(left);
		res.push_back(right);
		res.push_back(nums[left]);
	}
	else

	{
		int middle = left + (right - left) / 2;
		vector<int> leftVector = maxSubSum(nums, left, middle);
		vector<int> rightVector = maxSubSum(nums, middle + 1, right);
		int sum = 0, maxLeft = nums[middle], maxRight = nums[middle + 1];
		int i = 0, indexL = middle, indexR = middle + 1;
		for (i = middle; i >= left; i--)
		{
			sum += nums[i];
			if (sum > maxLeft)
			{
				maxLeft = sum;
				indexL = i;
			}
		}
		sum = 0;
		for (i = middle + 1; i <= right; i++)
		{
			sum += nums[i];
			if (sum > maxRight)
			{
				maxRight = sum;
				indexR = i;
			}
		}
		vector<int> crossVector;
		crossVector.push_back(indexL);
		crossVector.push_back(indexR);
		crossVector.push_back(maxLeft + maxRight);
		res = getMaxVector(getMaxVector(leftVector, rightVector), crossVector);



	}
	return res;

}