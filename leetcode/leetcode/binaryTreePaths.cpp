#include"leetcode.h"
void getAllPath(TreeNode* root, vector<vector<int>> &res, vector<int> p)
{
	if (root == NULL)
		return;
	if (root->left == NULL&&root->right == NULL)
	{
		p.push_back(root->val);
		res.push_back(p);
		return;
	}
	p.push_back(root->val);
	getAllPath(root->left, res, p);
	getAllPath(root->right, res, p);

}
vector<string> binaryTreePaths(TreeNode* root)
{
	vector<vector<int>> res;
	vector<int> p;
	getAllPath(root, res, p);
	vector<string> strRes;
	string str = "";
	for (int i = 0; i < res.size(); i++)
	{
		str = "";
		p = res[i];
		for (int j = 0; j < p.size(); j++)
		{
			if (j != p.size() - 1)
				str.append(intParseStr(p[j]) + "->");
			else
				str.append(intParseStr(p[j]));
		}
		strRes.push_back(str);
	}
	return strRes;
}