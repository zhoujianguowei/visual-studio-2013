#include"leetcode.h"

int main()
{
	int nums[] = { 5, 7, 7, 8, 8, 10 };
	vector<int> res = searchRange(getVec(nums, 6), 8);
	cout << "begin:" << res[0] << " end:" << res[1];
	return 0;
}

