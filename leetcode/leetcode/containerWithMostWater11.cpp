#include"leetcode.h"
int min(int x, int y)
{
	return x < y ? x : y;
}
int maxArea(vector<int>& height)
{
	int left = 0,  right = height.size() - 1;
	if (height.size() <= 1)
		return 0;
	int capacity = 0,volume=0;
	while (left < right)
	{
		volume = min(height[left], height[right])*(right - left);
		if (volume > capacity)
			capacity = volume;
		if (height[right] < height[left])
			right--;
		else
			left++;
	}
	return capacity;
}