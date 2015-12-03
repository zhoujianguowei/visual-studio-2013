#include"leetcode.h"

/*
the index is beginning at 0,
and the heap is small,first heap_down, and then ,heap_up
*/
void adjustHeap(vector<ListNode*> &nodes, int adIndex)
{
	int i = adIndex, j = 2 * i + 1;
	int size = nodes.size();
	while (j < size)
	{
		if (j + 1 < size&&nodes[j]->val > nodes[j + 1]->val)
			j = j + 1;
		if (nodes[i]->val>nodes[j]->val)
		{
			ListNode *temp = nodes[i];
			nodes[i] = nodes[j];
			nodes[j] = nodes[i];
			i = j;
			j = 2 * i + 1;
		}
		else
			break;
	}
	if (adIndex == 0)
		return;
	i = adIndex;
	j = (i - 1) / 2;
	while (i > 0)
	{
		if (nodes[i]->val < nodes[j]->val)
		{
			ListNode *temp = nodes[i];
			nodes[i] = nodes[j];
			nodes[j] = temp;
			i = j;
			j = (i - 1) / 2;
		}
		else
			break;
	}

}
void init(vector<ListNode*>& lists, vector<ListNode*>& nodes)
{
	int i = 0;
	int lackCount = 0;
	for (; i < lists.size(); i++)
	{
		ListNode *head = lists[i];
		if (head != NULL)
		{
			nodes.push_back(head);
			lists[i] = head->next;
		}
		else
			lackCount++;

	}
	if (lackCount)
	{
		for (i = 0; i < lists.size(); i++)
		{
			ListNode *node = lists[i];
			if (node != NULL)
			{
				while (node != NULL&&lackCount)
				{
					nodes.push_back(node);
					lists[i] = node->next;
					node = node->next;
					lackCount--;
				}

			}
			if (lackCount == 0)
				break;
		}

	}


}
ListNode* mergeKLists(vector<ListNode*>& lists)
{
	int lastListIndex = 0;
	int i = 0;
	vector<ListNode*> nodes;
	ListNode *newHead = new ListNode(-1);
	ListNode *p = newHead;
	init(lists, nodes);
	for (i = (nodes.size() - 1) / 2; i >= 0; i--)
	{
		adjustHeap(nodes, i);
	}
	if (nodes.size() == 0)
		return newHead->next;
	while (true)
	{
		ListNode *min = nodes[0];
		p->next= min;
		p = p->next;
		if (min->next != NULL)
		{
			nodes[0] = min->next;
			continue;
		}
		else
			for (i = lastListIndex; i < lists.size(); i++)
			{
				ListNode *node = lists[i];
				if (node != NULL)
				{
					nodes[0] = node;
					lists[i] = node->next;
					lastListIndex = i;
					break;
				}
			}
		adjustHeap(nodes, 0);
		if (nodes.size() < lists.size())
			break;
	}


}
