#include"leetcode.h"
int cout_prime(int n)
{
	if (n < 2)
		return 0;
	if (n < 4)
		return n - 1;
	vector<int> nums;
	nums.resize(n + 1, 1);
	int i, j;
	for (i = 2; i <= n / 2; i++)
		for (j = 2 * i; j <= n; j += i)
		{
			nums[j] = 0;
		}
	int count = 0;
	for (int i = 2; i <= n; i++)
		if (nums[i] == 1)
		{
			count++;
			//cout << setw(4) << i;
		}
	return count;
}

/*
删除排序数组中的重复元素
*/
ListNode* deleteDuplicates(ListNode* head)
{
	if (head == NULL || head->next == NULL)
		return head;
	ListNode* pre = head, *back = NULL, *adj = NULL;
	bool isHeadFirst = false;
	bool loop = false;
	if (head == NULL || head->next == NULL)
		return head;
	ListNode* newHead = (ListNode*)(malloc(sizeof(ListNode)));
	newHead->next = head;
	head = newHead;
	pre = head;
	while (pre)
	{
		loop = false;
		back = pre->next;
		while (back&&back->next)
		{
			if (back->next->val != back->val)
				break;

			back = back->next;
			loop = true;
		}
		if (loop)
			pre->next = back->next;
		else
		{
			pre->next = back;
			pre = back;
		}
	}
	head = head->next;
	return head;
}

int main()
{
	int array1[] = { 1, 5, 6, 9, 10 };
	int array2[] = { 2, 4, 5, 8 };
	int array3[] = { 3, 7, 11, 40, 52, 99 };
	ListNode *head1 = getListNode(array1,5);
	ListNode *head2 = getListNode(array2, 4);
	ListNode *head3 = getListNode(array3, 6);
	vector<ListNode*> lists;
	lists.push_back(head1);
	lists.push_back(head2);
	lists.push_back(head3);
	mergeKLists(lists);
	return 0;
}

