#include"leetcode.h"
inline ListNode *mergeTwoLists(ListNode *head1, ListNode *head2)
{
	ListNode * resHead = (ListNode*)(malloc(sizeof(ListNode)));
	ListNode *temp = resHead;
	temp->next = NULL;
	ListNode* temp1 = head1, *temp2 = head2;
	while (temp1&&temp2)
	{
		if (temp1->val < temp2->val)
		{
			temp->next = temp1;
			temp1 = temp1->next;
		}
		else
		{
			temp->next = temp2;
			temp2 = temp2->next;
		}
		temp = temp->next;
	}
	if (temp1)
		while (temp1)
		{
			temp->next = temp1;
			temp1 = temp1->next;
			temp = temp->next;
		}
	else if (temp2)
		while (temp2)
		{
			temp->next = temp2;
			temp2 = temp2->next;
			temp = temp->next;
		}
	return resHead->next;
}
ListNode* mergeKLists(vector<ListNode*>& lists)
{
	//ListNode *mergeTwoLists(ListNode *head1, ListNode *head2);
	ListNode *mergeTwoHead = NULL;
	for (int i = 0; i < lists.size(); i++)
	{
		mergeTwoHead = mergeTwoLists(mergeTwoHead, lists[i]);
	}
	return	mergeTwoHead;

}
