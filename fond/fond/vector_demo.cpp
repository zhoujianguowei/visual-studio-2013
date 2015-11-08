#include"fond.h"
void vector_man()
{
	vector<int> v;
	v.reserve(5);
	int i = 0;
	for (; i < 10; i++)
		v.push_back(i);
	cout << "v[3]="<<v[3]<<endl;
	i--;
	while (!v.empty())
	{
		cout << v.at(i--);
		v.pop_back();

	}
}