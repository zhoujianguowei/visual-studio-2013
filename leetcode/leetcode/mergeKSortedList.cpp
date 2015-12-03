#include"leetcode.h"
const int MAX_INT=2147483647;
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
			nodes[j] = temp;
			i = j;
			j = 2 * i + 1;
		}
		else
			break;
	}
}
void init(vector<ListNode*> lists, vector<ListNode*>& nodes)
{
	int i = 0;
	for (; i < lists.size(); i++)
	{
		ListNode *head = lists[i];
		if (head == NULL)
			head = new ListNode(MAX_INT);
		nodes.push_back(head);
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
	while (nodes[0]->val!=MAX_INT)
	{
		ListNode *min = nodes[0];
		p->next= min;
		p = p->next;
		min = min->next;
		if (min == NULL)
			min = new ListNode(MAX_INT);
		nodes[0] = min;
		adjustHeap(nodes, 0);
	}

	return newHead->next;
}
