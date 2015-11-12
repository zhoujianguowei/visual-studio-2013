#include"leetcode.h"
int reverse(int x)
{
	bool isNegative = false;
	stack<int> stack1, stack2;
	int result = 0, jie = 0;

	//stack<int> stack2;
	int i = x, j;
	if (x < 0)
	{
		isNegative = true;
		i = -x;
	}
	else if (x == 0)
		return 0;
	while (i > 0)
	{
		j = i % 10;
		stack1.push(j);
		i /= 10;
	}
	while (!stack1.empty())
	{
		if (jie == 0)
		{
			jie = 1;

		}
		else jie *= 10;
		if (stack1.top()> (pow(2, 31) - 1) / jie || pow(2, 31) - 1 - stack1.top()*jie<result)
		{
			result = 0;
			break;
		}
		result += stack1.top()*jie;
		stack1.pop();
	}

	return isNegative ? -result : result;


}