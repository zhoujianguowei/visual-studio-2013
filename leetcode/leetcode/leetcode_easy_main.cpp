#include"leetcode.h"
int main()
{
	string strArray[] = { "-1","0","3","-2","4","null","null","8" };
	int i = 0;
	vector<string> strVec;
	for (; i <8; i++)
		strVec.push_back(strArray[i]);
	TreeNode * root = createTree(strVec);
	cout << lowestCommonAncestor(root, root->right, root->left->left->left)->val;
	return 0;
}

