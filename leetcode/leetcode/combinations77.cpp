#include"leetcode.h"
vector<vector<int>> combine(int n, int k)
{
	vector<vector<int>> res;
	vector<int> subRes;
	if (k == 1)
	{
		for (int i = 1; i <= n; i++)
		{
			subRes.push_back(i);
			res.push_back(subRes);
			subRes.clear();
		}
		return res;
	}
	else
	{
		vector<vector<int>> previousRes = combine(n - 1, k - 1);
		for (unsigned int i = 0; i < previousRes.size(); i++)
		{
			for (unsigned int j = previousRes[i].back() + 1; j <= n; j++)
			{
				subRes = previousRes[i];
				subRes.push_back(j);
				res.push_back(subRes);
				subRes.clear();
			}
		}
		return res;
	}
}