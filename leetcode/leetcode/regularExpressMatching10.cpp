#include"leetcode.h"
/*
Implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "a*") → true
isMatch("aa", ".*") → true
isMatch("ab", ".*") → true
isMatch("aab", "c*a*b") → true
字符串操作时无法ac的，因为字符串效率太低，需要使用指针
*/
bool isPointerMatch(char *s, char *p)
{
	if (*p == '\0')
		return  !(*s);
	if (*(p + 1) == '\0')
	{
		if (*p == '.' || *p == *s)
			return isPointerMatch(s + 1, p + 1);
		return false;
	}
	if (*(p + 1) == '*')
	{
		while (*p != '\0'&&*s != '\0')
		{
			if (*p =='.' || *s == *p)
			{
				if (isPointerMatch(s, p + 2))
					return true;
				s++;
				continue;
			}
			break;
		}
		return isPointerMatch(s, p + 2);
	}
	if (*p == '.'&&*s|| *s == *p)  // "..*"和""空串情况
		return isPointerMatch(s + 1, p + 1);
	return false;
}
bool isMatch(string s, string p)
{
	if (s.size() == 0 || p.size() == 0)
		return !s.size() && !p.size();
	string cs = s.substr(0, 1);
	string cp = p.substr(0, 1);
	if (p.size() == 1)
	{
		if (cp == "." || cp == cs)
			return isMatch(s.substr(1, s.size() - 1), p.substr(1, p.size() - 1));
		return false;
	}
	if (p.substr(1, 1) == "*")
	{
		//bool isAccept
		while (s.size() > 0 && p.size() > 0)
		{
			cs = s.substr(0, 1);
			if (cp == "." || cp == cs)
			{
				if (isMatch(s, p.substr(2)))
					return true;
				s = s.substr(1);
				continue;
			}
			/*if (cp == cs)
			{
			s = s.substr(1);
			continue;
			}*/
			break;

		}
		return isMatch(s, p.substr(2));
	}
	if (cp == "." || cp == cs)
		return isMatch(s.substr(1), p.substr(1));

	return false;
}