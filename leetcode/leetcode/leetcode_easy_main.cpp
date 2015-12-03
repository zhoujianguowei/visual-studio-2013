#include"leetcode.h"
int main()
{

	ListNode *head2 = new ListNode(-1);
	head2->next = new ListNode(5);
	head2->next->next = new ListNode(11);
	ListNode *head4 = new ListNode(6);
	head4->next = new ListNode(10);
	vector<ListNode *> lists;
	lists.push_back(NULL);
	lists.push_back(head2);
	lists.push_back(NULL);
	lists.push_back(head4);
	mergeKLists(lists);
	return 0;
}

