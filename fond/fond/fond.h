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
����������еĺͣ����㷨���Ӷ�Ϊnlogn
*/
vector<int> maxSubSum(vector<int> &nums, int left, int right);
/*
ָ��ʹ�����
*/
void recall();
/*
ʹ�ö�̬�滮�������������
*/
int dpGetMaxSubSum(vector<int> nums);
void graph_test();
void getMatrix(int n);