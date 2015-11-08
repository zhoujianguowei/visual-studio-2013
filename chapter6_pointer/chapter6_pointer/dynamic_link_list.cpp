#include"chapter6_pointer.h"
NODE* create(int *array,int n)
{
	NODE *p = new NODE[n];
	NODE *header = p;
	int i = 0;
	while (i++<n)
	{
		//p++;
		p->data = *array++;
		p->next = (1+p);
		p++;
	}
	p--;
	p->next= NULL;
	return header;
}
void print(NODE* head)
{
	NODE *temp = head;
	while (temp)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}
void del(NODE *head,int pos)
{
	if (pos < 0)
		return;
	NODE *temp = head,*pre=head;
	int i = 0;
	while (i++ < pos&&temp)
	{
		pre = temp;
		temp = temp->next;
	}
	if (!temp)
		cout << "out of range";
	else
	{
		if (temp == head)
		{ 
			cout << "del " << head->data;
			head = head->next;
		}
		else
		{
			cout << "del " << temp->data;
			pre->next = temp->next;
		}
	}
}
void free(NODE* head)
{
	delete[]head;
}