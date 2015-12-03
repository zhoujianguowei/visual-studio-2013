#include"leetcode.h"
int main()
{
	ListNode *head1 = new ListNode(3);
	head1->next = new ListNode(11);
	head1->next->next = new ListNode(15);
	ListNode *head2 = new ListNode(2);
	head2->next = new ListNode(7);
	ListNode *head3 = new ListNode(10);
	head3->next = new ListNode(15);
	head3->next->next = new ListNode(17);
	head3->next->next->next = new ListNode(19);
	vector<ListNode *> lists;
	lists.push_back(head1);
	lists.push_back(head2);
	lists.push_back(NULL);
	lists.push_back(head3);
	mergeKLists(lists);
	return 0;
}

