#include"post_leetcode.h"
ListNode *getPointer(int nums[], int n)
{
	ListNode *head=NULL, *cur=NULL,*node=NULL;
	int i;
	for (i = 0; i < n; i++)
	{
		if (head == NULL)
		{
			head = new ListNode(nums[0]);
			cur= head;
			continue;
		}
		node = new ListNode(nums[i]);
		cur->next = node;
		cur = node;
	}
	return head;
}
ListNode *reverseList(ListNode *head, int n)
{	
	ListNode *pre=head, *cursor=head->next, *temp=NULL;
	int i=1;
	while (i < n&&cursor)
	{
		temp = cursor->next;
		cursor->next = head;
		head = cursor;
		cursor = temp;
		i++;
	}
	pre->next = temp;
	return head;

}