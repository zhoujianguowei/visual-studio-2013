#include"leetcode.h"
/*
Single Number My Submissions Question
Total Accepted: 99569 Total Submissions: 212059 Difficulty: Medium
Given an array of integers, every element appears twice except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

There are two methods for the problems, tradition is using byte extra to get the single number ,but need extra space. Another by ^, but specified condition.
*/
int singleNumber(vector<int>& nums)
{
	int digits[32];
	memset(digits, 0, sizeof(digits));
	int i, j;
	for (i = 0; i < 32; i++)
		for (j = 0; j < nums.size(); j++)
			digits[i] += (nums[j] >> i)&1;
	int res = 0;
	for (i = 0; i < 32; i++)
		res += (digits[i] % 2) << i;
	return res;
}