#include"leetcode.h"

void traverse_uniq_element(vector<vector<int>>& res, vector<int>& sortedCandidates, vector<int> candidateSum, int extra, int index, vector<int> subRes)
{
	if (index < 0)
		return;
	if (extra == 0)
	{
		res.push_back(reverseVector(subRes));
		/*if (!subRes.empty())
		{
			extra = subRes.back();
			vector<int>::iterator endIterator = subRes.end();
			subRes.erase(--endIterator);
			traverse_uniq_element(res, sortedCandidates, candidateSum, extra, index - 1, subRes);

		}*/
		return;
	}
	if (extra > candidateSum[index])
		return;
	if (index == 0)
	{
		if (extra == sortedCandidates[index])
		{
			subRes.push_back(extra);
			res.push_back(reverseVector(subRes));
		}
		return;
	}
	int currentData = sortedCandidates[index];
	int diffIndex = index;
	while (diffIndex >= 0 && sortedCandidates[diffIndex] == currentData)
		diffIndex--;
	traverse_uniq_element(res, sortedCandidates, candidateSum, extra, diffIndex, subRes);//不添加当前元素
	if (extra >= sortedCandidates[index])
	{
		subRes.push_back(sortedCandidates[index]);
		traverse_uniq_element(res, sortedCandidates, candidateSum, extra - sortedCandidates[index], index - 1, subRes);
	}

}
vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
{

	quick_sort(candidates);
	vector<vector<int>> res;
	vector<int> candidatesSum;

	int i, j, sum = 0;
	for (int i = 0; i < candidates.size(); i++)
	{
		sum += candidates[i];
		candidatesSum.push_back(sum);
	}
	for (i = 0; i < candidates.size(); i++)
	{
		if (candidates[i] > target)
			break;
	}
	i--;
	if (i < 0)
		return res;
	vector<int> subRes;
	traverse_uniq_element(res, candidates, candidatesSum, target, i, subRes);
	return res;
}

