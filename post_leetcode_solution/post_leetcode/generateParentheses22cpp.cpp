#include"post_leetcode.h"
void generaeRecursiveFunc(string s, vector<string> &sVec, int totalLeftBracket, int  n, stack<char> parenthesisStack)
{
	int i = 0;
	if (totalLeftBracket == n)
	{
		for (i = s.size(); i < 2 * n; i++)
			s.append(1, ')');
		sVec.push_back(s);
		return;
	}
	if (parenthesisStack.empty())
	{
		parenthesisStack.push('(');
		totalLeftBracket++;
		s.append(1, '(');
		generaeRecursiveFunc(s, sVec, totalLeftBracket, n, parenthesisStack);
	}
	else
	{
		parenthesisStack.push('(');
		totalLeftBracket++;
		s.append(1, '(');
		generaeRecursiveFunc(s, sVec, totalLeftBracket, n, parenthesisStack);
		parenthesisStack.pop();
		totalLeftBracket--;
		s.erase(s.end()-1);
		parenthesisStack.pop();
		s.append(1, ')');
		generaeRecursiveFunc(s, sVec, totalLeftBracket, n, parenthesisStack);
	}

}
vector<string> generateParenthesis(int n)
{
	vector<string> res;
	string s;
	stack<char> parenthesisStack;
	generaeRecursiveFunc(s, res, 0, n, parenthesisStack);
	return res;
}