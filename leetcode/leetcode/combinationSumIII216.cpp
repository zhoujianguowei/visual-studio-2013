#include"leetcode.h"
void getCombinationSum(vector<vector<int>> &res, vector<int> preVec, int k, int extra)
{
	int base = 1;
	if (!preVec.empty())
		base = preVec.back() + 1;
	if (extra <base||base>9)
		return;
	if (k == 1)
	{
		if (extra >= base&&extra <= 9)
		{

			preVec.push_back(extra);
			res.push_back(preVec);
		}
		return;
	}
	int i = base;
	for (; i <= 9; i++)
	{
		preVec.push_back(i);
		getCombinationSum(res, preVec, k-1, extra - i);
		preVec.pop_back();
	}

}
vector<vector<int>> combinationSum3(int k, int n)
{
	vector<vector<int>> res;
	if (k >= 10)
		return res;
	int min = 0, max = 0;
	for (int i = 0; i < k; i++)
	{
		min += (i + 1);
		max += (9 - i);
	}
	if (n<min || n>max)
		return res;
	vector<int >parent;;
	getCombinationSum(res, parent, k, n);
	cout << "size:" << res.size() << endl;
	return res;
}