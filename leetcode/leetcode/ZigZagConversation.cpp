#include"leetcode.h"
string convert(string s, int numRows)
{
	/*
	ʮ�����ĵ���Ŀ���������л���ĩ��ʱ�������ظ�2(numRows-1)(numRows  zigtag��ʾ����)
	������м��У���ô�����ظ�Ҳ����ˣ������м���Ҫ����2*(numRows-rowCount-1)  (rowCountΪ��������-1)
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