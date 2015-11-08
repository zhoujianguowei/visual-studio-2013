#include"chapter6_pointer.h"
void integer_sort(int a, int b, int c)
{
	//int temp;
	change(a, b);
	change(a, c);
	change(b, c);
	cout << setw(-8) << a << "  " << b << "  " << c;
	
}
void change(int &i, int &j)
{
	int temp;
	if (i < j)
	{
		temp = i;
		i = j;
		j = temp;
	}
}
void change_value(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

