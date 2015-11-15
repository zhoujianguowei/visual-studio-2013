#include"leetcode.h"
/*
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.
*/
int binarySearch(vector<int> nums, int left, int right, int target)
{
	if (left == right)
		if (target == nums[left])
			return left;
		else
			return -1;
	int middle = left + (right - left) / 2;
	if (nums[left] > nums[right])
	{
		if (nums[left] <= nums[middle])  //左边是有序的
			if (nums[left] <= target&&nums[middle] >= target)
				return binarySearch(nums, left, middle, target);
			else
				return binarySearch(nums, middle + 1, right, target);
		else if (nums[middle] <= nums[right]) //右边是有序的
			if (nums[middle + 1] <= target&&nums[right] >= target)
				return binarySearch(nums, middle + 1, right, target);
			else
				return binarySearch(nums, left, middle, target);

	}
	while (left <= right)
	{
		middle = left + (right - left) / 2;
		if (target == nums[middle])
			return middle;
		else if (target > nums[middle])
			left = middle + 1;
		else
			right = middle - 1;
	}
	return -1;
}
int search(vector<int>& nums, int target)
{
	return binarySearch(nums, 0, nums.size() - 1, target);
}