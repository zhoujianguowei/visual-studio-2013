#include"post_leetcode.h"
bool isValid(string s)
{
	stack<char> charStack;
	int i = 0;
	char currentChar;
	if (s.empty())
		return true;
	if (s.size()%2)
		return false;
	charStack.push(s.at(0));
	for (i = 1; i < s.size(); i++)
	{
		currentChar = s.at(i);
		if (currentChar == '(' || currentChar == '[' || currentChar == '{')
			charStack.push(currentChar);
		else
		{
			switch (currentChar)
			{
			case ')':
				if (charStack.top() != '(')
					return false;
				break;
			case ']':
				if (charStack.top() != '[')
					return false;
				break;
			case '}':
				if (charStack.top() != '{')
					return false;
				break;
			}
			charStack.pop();
		}
	}

	return charStack.empty();

}