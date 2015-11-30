#include"leetcode.h"
#pragma warning(disable:4146)
void reverseWords(string &s)
{
	if (s.length() == 0)
		return;
	string anotherS;
	vector<string> strVec;
	int i = 0;
	while (i < s.length() && s.at(i) == ' ')
		i++;
	if (i == s.length())
	{
		s = "";
		return;
	}
	int length = 0;
	int firstIndex = i;
	for (; i < s.length(); i++)
	{
		if (s.at(i) == ' ')
		{
			anotherS.assign(s.substr(firstIndex, length));
			strVec.push_back(anotherS);
			while (i<s.length()&&s.at(i) == ' ')
				i++;
			firstIndex = i;
			i--;
			length = 0;
		}
		else
			length++;
	}
	if (s.at(s.length() - 1) != ' ')
	{
		anotherS.assign(s.substr(firstIndex, length));
	    strVec.push_back(anotherS);
	}
	s.assign("");
	for (i = strVec.size() - 1; i >= 0; i--)
		s.append(strVec[i] + " ");
	s.erase(s.length()-1);


}
int main()
{
	int nums[] = { 6, 7, 0, 1, 2, 4, 5 };
	string s = "1 ";
	reverseWords(s);
	cout << "after :\"" << s<<"\"";
	return 0;
}

