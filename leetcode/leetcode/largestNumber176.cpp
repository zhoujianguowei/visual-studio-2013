#include"leetcode.h"
string intParseStr(int num)
{
	//bool isNegative = num < 0 ? true : false;
	if (num == 0)
		return "0";
	int i, j = num;
	bool isNegative = num < 0 ? true : false;
	string s=isNegative?"-":"";
	stack<char> numStack;
	while (j)
	{
		i = j % 10 ;
		j /= 10;
		numStack.push(i);
	}
	while (!numStack.empty())
	{
		s.append(1, numStack.top()+'0');
		numStack.pop();
	}
	return s;
}


int largerIntCmp(int num1, int num2)
{
	string num1Str = intParseStr(num1);
	string num2Str = intParseStr(num2);
	string synNum1 = num1Str + num2Str;
	string synNum2 = num2Str + num1Str;
	return synNum1.compare(synNum2);
}
string largestNumber(vector<int>& nums)
{
	string largeStr;

	int i;
	for (i = 0; i < nums.size(); i++)
	{
		int max = nums[0];
		int maxIndex = 0;
		int j = 1;
		for (; j < nums.size() - i; j++)
		{
			if (largerIntCmp(nums[j], max)>0)
			{
				maxIndex = j;
				max = nums[j];
			}
		}
		j--;
		largeStr.append(intParseStr(max));
		int temp = max;
		nums[maxIndex] = nums[j];
		nums[j] = max;
	}
	i = 0;
	while (i<largeStr.size()&&largeStr.at(i) == '0')
		i++;
	if (i == largeStr.size())
		return "0";
	else
	return largeStr.substr(i);


}