#include"post_leetcode.h"
using namespace std;
void printMatrix(vector<vector<int>> res)
{
	int i = 0;
	for (; i < res.size(); i++)
		printVec(res.at(i));

}
int main()
{
	//int sum = 0,j;
	//for (j = 1; j < 101; j++)
	//	sum += j;
	////cout << "sum=" << sum << endl;
	//vector<int> nums;
	//srand(time(NULL));
	//for (j = 0; j < 10; j++)
	//	nums.push_back(rand() % 101);
	//cout << "sorted before:" << endl;
	//printVec(nums);
	//cout << "sorted after:" << endl;
	//quick_sort(nums);
	//printVec(nums);
	int nums[] = { 5, 5, 3, 5, 1, -5, 1, -2 };
	vector<vector<int>> res = fourSum(getVec(nums, 8), 4);
	printMatrix(res);
	return 0;
}