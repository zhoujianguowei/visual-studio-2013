#include"leetcode.h"
/*
Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

For example:
Given the below binary tree and sum = 22,
5
/ \
4   8
/   / \
11  13  4
/  \    / \
7    2  5   1
return
[
[5,4,11,2],
[5,8,4,5]
]
*/
void getPathSum(vector<vector<int>>&res, TreeNode* root, vector<int> vec, int sum)
{
	if (root == NULL)
		return;
	if (root->left == NULL&&root->right == NULL)
	{
		if (root->val == sum)
		{
			vec.push_back(sum);
			res.push_back(vec);
		}
		return;
	}
	vec.push_back(root->val);
	getPathSum(res, root->left, vec, sum - root->val);
	getPathSum(res, root->right, vec, sum - root->val);

}
vector<vector<int>> pathSum(TreeNode* root, int sum)
{
	vector<vector<int>> res;
	vector<int> vec;
	getPathSum(res, root, vec, sum);
	return res;
}