#include"leetcode.h"
void getLetterCombination(string digits, vector<string> &res, unordered_map<char, string> umap)
{
	int i, j;
	vector<string> temp;
	if (digits.size() == 0)
		return;
	string phone = umap.find(digits.at(0))->second;
	if (res.size() == 0)
	{
		for (j = 0; j < phone.size(); j++)
		{
			res.push_back(phone.substr(j, 1));
		}
	}
	else
	{
		for (i = 0; i < phone.length(); i++)
		{
			for (j = 0; j < res.size(); j++)
			{
				string mid = res.at(j);
				temp.push_back(mid.append(phone.substr(i, 1)));
			}
		}
		res = temp;

		//return;

	}
	getLetterCombination(digits.substr(1), res, umap);

}
vector<string> letterCombinations(string digits)
{
	vector<string> res;
	unordered_map<char, string> umap;
	umap.insert(make_pair('2', "abc"));
	umap.insert(make_pair('3', "def"));
	umap.insert(make_pair('4', "ghi"));
	umap.insert(make_pair('5', "jkl"));
	umap.insert(make_pair('6', "mno"));
	umap.insert(make_pair('7', "pqrs"));
	umap.insert(make_pair('8', "tuv"));
	umap.insert(make_pair('9', "wxyz"));
	bool containsZeroOrOne = false;
	int i;
	//vector<char> letters;
	for (i = 0; i < digits.length(); i++)
		if (digits.at(i) == '0' || digits.at(i) == '1')
		{
			containsZeroOrOne = true;
			break;

		}
	if (!containsZeroOrOne)
	{
		getLetterCombination(digits, res, umap);
	}


	return res;
}