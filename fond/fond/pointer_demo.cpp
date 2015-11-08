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
	int (*p)[4] = array; //本质上int二重数组名的类型是 (*)[4],即指向数组的指针
	int *q = array[0];
	//普通指针使用说明
	cout << "普通指针的使用"<<endl;
	while (q < array[0] + 12)
	{
		cout << setw(4) << *q++;
		if ((q - array[0]) % 4 == 0)
			cout << "\n";
	}

	//指向数组的指针使用
	cout << "指向数组的指针的使用" << endl;
	while (p < array + 3)
	{
		for (int i = 0; i < 4; i++)
			cout << setw(6) << *(*p + i);  //*p代表的是一个数组的地址
		p++;
		cout << endl;
	}

}
void recall()
{
	rowPointer();
	int(*func)(int);
	func = getSum;
	cout << "指向函数的指针的使用" << endl;
	cout << "sum of 100:" << func(100);

}
