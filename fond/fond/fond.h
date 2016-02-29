#include<iostream>
#include<iomanip>
#include<math.h>
#include<cstdio>
#include<vector>
#include<cstdlib>
#include<string>
#include<stack>
#include<map>
#include<limits.h>
using namespace std;
#define ERROR -1
void getCutMax(int*, int, int);
void vector_man();
int getLongestArray(vector<int> nums);
/*
求最大子数列的和，该算法复杂度为nlogn
*/
vector<int> maxSubSum(vector<int> &nums, int left, int right);
/*
指针使用详解
*/
void recall();
/*
使用动态规划计算最大子数列
*/
int dpGetMaxSubSum(vector<int> nums);
void graph_test();
void getMatrix(int n);