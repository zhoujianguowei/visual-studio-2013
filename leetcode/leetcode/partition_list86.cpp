#include"leetcode.h"
ListNode* partition(ListNode* head, int x)
{
	ListNode *greater = (ListNode*)(malloc(sizeof(ListNode))), *greaterTemp = greater;
	ListNode *less = (ListNode*)(malloc(sizeof(ListNode))), *lessTemp = less;
	greater->next = NULL;
	less->next = NULL;
	ListNode *iterator = head;
	while (iterator)
	{
		if (iterator->val >= x)
		{
			greaterTemp->next = iterator;
			greaterTemp = iterator;
		}
		else	if (iterator->val < x)
		{
			lessTemp->next = iterator;
			lessTemp = iterator;
		}
		iterator = iterator->next;
	}
	lessTemp->next = greater->next;
	head = less->next;
	greaterTemp->next = NULL;
	return head;
}