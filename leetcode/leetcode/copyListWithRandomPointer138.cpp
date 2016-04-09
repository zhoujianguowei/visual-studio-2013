#include"leetcode.h"

/*
һ����ͨ��map��ʵ�֣�û�иı�ԭ������Ľṹ��
����һ���Ǹı�ԭ����Ľṹ��ͨ���޸�ԭ�����next��ָ��ָ���Ӧ���������ָ�루����һ�£�����Ҫ���ڸ���Randomָ�룩
֮���������,����ο�http://www.cnblogs.com/TenosDoIt/p/3387000.html
*/
RandomListNode *restructListNode(RandomListNode *head)
{
	RandomListNode *node=NULL, *p = head;
	RandomListNode* temp=NULL;
	while (p)
	{
		temp = p->next;
		node = new RandomListNode(p->label);
		p->next = node;
		node->next = temp;
		p = temp;
	}
	return head;
}
RandomListNode *cloneRandomPointer(RandomListNode *head)
{
	RandomListNode* p = head;
	RandomListNode *pNext = p->next;
	while (p&&p->next)
	{
		pNext = p->next;
		if (p->random!=NULL)
		pNext->random = p->random->next;
		p = pNext->next;
	}
	return head;
}

RandomListNode *copyRandomList(RandomListNode *head)
{
	if (head == NULL)
		return head;
	head = restructListNode(head);
	head = cloneRandomPointer(head);
	RandomListNode *newHead=NULL, *p = head,*newP=newHead;
	RandomListNode *pNext=NULL;
	while (p&&p->next)
	{
		pNext = p->next;
		if (newHead == NULL)
		{
			newHead = pNext;
			newP = pNext;
		}
		else
		{
			newP->next = pNext;
			newP = pNext;
		}
		p->next = pNext->next;
		p = p->next;
	}
	return newHead;
}