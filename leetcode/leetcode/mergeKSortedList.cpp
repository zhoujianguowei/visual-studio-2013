#include"leetcode.h"

ListNode* mergeKLists(vector<ListNode*>& lists)
{
	ListNode* head = (ListNode*)(malloc(sizeof(ListNode)));
	head->next = NULL;
	ListNode* p = head;
	int overListCount = 0;
	while (overListCount < lists.size())
	{
		int minIndex = -1;
		int min = -1;
		bool changed = false;
		overListCount = 0;
		for (int i = 0; i < lists.size(); i++)
		{
			if (lists[i] == NULL)
			{
				overListCount++;
				continue;
			}
			else
			{
				if (!changed)
				{
					min = lists[i]->val;
					minIndex = i;
					changed = true;
					continue;
				}
			}
			if (lists[i]->val < min)
			{
				min = lists[i]->val;
				minIndex = i;
			}
		}
		if (changed)
		{
			lists[minIndex] = lists[minIndex]->next;
			ListNode *addNode = (ListNode*)(malloc(sizeof(ListNode)));
			addNode->next = NULL;
			addNode->val = min;
			p->next = addNode;
			p = addNode;

		}
	}
	return head->next;

}
