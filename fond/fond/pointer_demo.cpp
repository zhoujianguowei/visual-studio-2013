#include"fond.h"
int getSum(int n)
{
	int sum = 0;
	for (int i = 0; i <= n;i++)
		sum += i;
	return sum;
}
void rowPointer()
{
	int array[][4] = { { 3, 8, 2, 4 }, { 1, 9, 13, 27 }, { 14, 6, 5, 7 } };
	int (*p)[4] = array; //������int������������������ (*)[4],��ָ�������ָ��
	int *q = array[0];
	//��ָͨ��ʹ��˵��
	cout << "��ָͨ���ʹ��"<<endl;
	while (q < array[0] + 12)
	{
		cout << setw(4) << *q++;
		if ((q - array[0]) % 4 == 0)
			cout << "\n";
	}

	//ָ�������ָ��ʹ��
	cout << "ָ�������ָ���ʹ��" << endl;
	while (p < array + 3)
	{
		for (int i = 0; i < 4; i++)
			cout << setw(6) << *(*p + i);  //*p�������һ������ĵ�ַ
		p++;
		cout << endl;
	}

}
void recall()
{
	rowPointer();
	int(*func)(int);
	func = getSum;
	cout << "ָ������ָ���ʹ��" << endl;
	cout << "sum of 100:" << func(100);

}
