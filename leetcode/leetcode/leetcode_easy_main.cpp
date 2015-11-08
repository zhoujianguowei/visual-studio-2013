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
	/*ListNode(*head) = new ListNode(3);
	int sums[] = { 1, 2, 3 };
	for (int i = 0; i < 3; i++)
	{
	head[i].val = i+1;
	head[i].next = NULL;

	}
	head->next = &head[1];
	head->next->next = &head[2];
	reverseBetween(head, 2, 3);*/
	/*clock_t start = clock();
	cout << cout_prime(20000000) << "  time:";
	clock_t finish = clock();
	cout << (finish - start) / CLOCKS_PER_SEC << "秒";*/
	/*vector<Interval> intervals;
	Interval interval1;
	interval1.start = 1;
	interval1.end = 4;
	Interval interval2;
	interval2.start = 1;
	interval2.end = 5;
	intervals.push_back(interval1);
	intervals.push_back(interval2);
	merge(intervals);*/
	/*int nums[] = {2,5,3,1,4 };
	sortList(getListNode(nums, 5));*/
	int arrayNums[] = { 1, 2, 3, 5, 7, 9, 12, 1, 3 };
	vector<int> nums;
	for (int i = 0; i < 9; i++)
		nums.push_back(arrayNums[i]);
	return 0;
}

