#include<leetcode.h>
/**
18. 4Sum My Submissions QuestionEditorial Solution
Total Accepted: 68373 Total Submissions: 290097 Difficulty: Medium
Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note:
Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a �� b �� c �� d)
The solution set must not contain duplicate quadruplets.
For example, given array S = {1 0 -1 0 -2 2}, and target = 0.

A solution set is:
(-1,  0, 0, 1)
(-2, -1, 1, 2)
(-2,  0, 0, 2)
*/
vector<vector<int>> fourSum(vector<int>& nums, int target);
/**
20. Valid Parentheses My Submissions QuestionEditorial Solution
Total Accepted: 102420 Total Submissions: 351089 Difficulty: Easy
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.

Subscribe to see which companies asked this question
*/
bool isValid(string s);
/**
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

"((()))", "(()())", "(())()", "()(())", "()()()"k
*/
vector<string> generateParenthesis(int n);