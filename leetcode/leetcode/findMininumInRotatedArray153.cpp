#include"leetcode.h"
/*
this is another version,which is a approach to duplicate problem
if (left == right)
min = min > nums[left] ? nums[left] : min;
if (left > right)
return;
int middle = left + (right - left) / 2;
if (nums[left] >=nums[right])
{
if(nums[middle]==nums[left]&&nums[middle]==nums[right])
min=min>nums[left]?nums[left]:min;
if(nums[middle]>nums[left])
min=min>nums[left]?nums[left]:min;
else
binary_get_min(nums,min,left+1,middle);
if(nums[middle]<nums[right])
min=min>nums[right]?nums[right]:min;
else
binary_get_min(nums,min,middle+1,right);

}
min = min > nums[left] ? nums[left] : min;

*/
void binary_get_min(vector<int> nums,int &min, int left, int right)
{
	if (left == right)
		min = min > nums[left] ? nums[left] : min;
	if (left > right)
		return;
	int middle = left + (right - left) / 2;
	if (nums[left] > nums[right])
	{
		if (nums[left] <= nums[middle])  //左边是有序的
			min = min > nums[left] ? nums[left] : min;
		else 
			binary_get_min(nums, min, left+1, middle);
		if (nums[middle] <= nums[right]) //右边是有序的
			min = min > nums[middle] ? nums[middle] : min;
		else
			binary_get_min(nums, min, middle+1, right);
	}
	min = min > nums[left] ? nums[left] : min;
}
/*
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

You may assume no duplicate exists in the array.
*/
int findMin(vector<int>& nums)
{
	if (nums.size() == 0)
		return 0;
	int min = nums[0];
	binary_get_min(nums, min, 0, nums.size() - 1);
	return min;
}