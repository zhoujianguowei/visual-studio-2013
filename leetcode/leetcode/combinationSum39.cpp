#include"leetcode.h"

void traverse_all_element(vector<vector<int>>& res, vector<int>& sortedCandidates, int extra, int index, vector<int> subRes)
{
	if (extra == 0)
	{
		res.push_back(reverseVector(subRes));
		return;
	}
	/*else if (sortedCandidates[index] > extra)
		return;*/
	else if (index == 0)
	{
		int i = extra / sortedCandidates[index];
		extra = extra % sortedCandidates[index];
		if (extra == 0)
		{
			vector<int> revSubRes;
			while (i--)
			{
				subRes.push_back(sortedCandidates[index]);
			}
			res.push_back(reverseVector(subRes));
		}
		return;
	}
	int i = 0, length = extra / sortedCandidates[index];
	for (; i <= length; i++)
	{
		if (i == 0)
		{
			traverse_all_element(res, sortedCandidates, extra, index - 1, subRes);
			continue;
		}
		subRes.push_back(sortedCandidates[index]);
		extra -= sortedCandidates[index];
		traverse_all_element(res, sortedCandidates, extra, index - 1, subRes);
	}
}
vector<vector<int>> combinationSum(vector<int>& candidates, int target)
{
	quick_sort(candidates);
	vector<vector<int>> res;
	int i, j;
	for (i = 0; i < candidates.size(); i++)
	{
		if (candidates[i] > target)
			break;
	}
	i--;
	if (i < 0)
		return res;
	vector<int> subRes;
	traverse_all_element(res, candidates, target, i, subRes);
	return res;
}
