#include"leetcode.h"
string convert(string s, int numRows)
{
	/*
	十分无聊的题目，当是首行或者末行时候，周期重复2(numRows-1)(numRows  zigtag显示行数)
	如果是中间行，那么周期重复也是如此，不过中间需要加上2*(numRows-rowCount-1)  (rowCount为具体行数-1)
	*/
	string result = "";
	int rowCount = 0,length=s.length();
	if (length <= 1 || numRows > length||numRows==1)
		return s;

	while (rowCount < numRows)
	{
		for (int i = rowCount; i < length; i += 2 * (numRows - 1))
		{
			result.push_back(s[i]);
			if (rowCount> 0 && rowCount < length - 1)
			{
				int j = 2 * (numRows -rowCount-1);
				if (j>0&&i + j < length)
					result.push_back(s[i + j]);
			}
		}
		rowCount++;
	}
	return result;
}