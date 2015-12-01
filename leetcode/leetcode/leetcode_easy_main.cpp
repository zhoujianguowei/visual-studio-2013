#include"leetcode.h"
TreeNode *p = NULL;
void validBST(TreeNode *root, bool &flag)
{
	if (root == NULL)
		return;
	validBST(root->left, flag);
	if (p != NULL&&p->val >= root->val)
	{
		flag = false;
		return;
	}
	p = root;
	validBST(root->right, flag);
}

bool isValidBST(TreeNode* root)
{
	bool flag = true;
	validBST(root, flag);
	return flag;

}
int main()
{
	//string strArray[] = { "10", "5", "15", "null", "null", "6","20" };
	//string strArKray[] = { "3", "1","5","0","2","4","6","null","null","null","3" };
	string strArray[] = { "1" };
	int i = 0;
	vector<string> strVec;
	for (; i <1; i++)
		strVec.push_back(strArray[i]);
	TreeNode * root = createTree(strVec);
	cout << isValidBST(root);
	return 0;
}

