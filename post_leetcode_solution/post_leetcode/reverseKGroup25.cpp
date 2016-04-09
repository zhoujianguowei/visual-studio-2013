#include"post_leetcode.h"
ListNode* reverseKGroup(ListNode* head, int k)
{
	ListNode *pre, *temp, *cursor = head, *preTail=NULL, *curTail;
	if (head == NULL || k == 1)
		return head;
	int m = 1;
	bool isFirst = true;
	while (cursor)
	{
		m = 1;
		pre = cursor;
		if (preTail == NULL)
		{
			preTail = pre;
		}
			curTail = pre;
		cursor = cursor->next;
		for (; m < k&&cursor; m++)
		{
			temp = cursor->next;
			cursor->next = pre;
			pre = cursor;
			cursor = temp;
		}
		if (m != k)
		{
			curTail->next = NULL;
			pre=reverseList(pre, m);
		}
		if (isFirst)
		{
			head = pre;
			isFirst = false;
		}
		if (m == k)
			curTail->next = cursor;
		if (preTail != curTail)
		{
			preTail->next = pre;
			preTail = curTail;
		}

	}
	return head;
}