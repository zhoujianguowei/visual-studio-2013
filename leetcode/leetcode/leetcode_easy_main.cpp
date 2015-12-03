#include"leetcode.h"
int main()
{
	RandomListNode *node1 = new RandomListNode(1);
	RandomListNode *node2 = new RandomListNode(2);
	RandomListNode *node3 = new RandomListNode(3);
	node1->next = node2;
	node2->next = node3;
	node1->random = node3;
	node3->random = node1;
	copyRandomList(node1);
	return 0;
}

