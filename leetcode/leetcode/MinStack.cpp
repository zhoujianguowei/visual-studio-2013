#include"leetcode.h"
void MinStack::push(int x)
{
	if (nodeList.empty())
	{
		minList.push_front(x);
	}
	else if (x <= minList.front())
		minList.push_front(x);
	nodeList.push_front(x);
		 

}
void MinStack::pop()
{
	int top = this->top();
	nodeList.pop_front();
	if (top == getMin())
	{
		minList.pop_front();
	}

}
int MinStack::top()
{
	return nodeList.front();
}
int MinStack::getMin()
{
	return minList.front();
}
