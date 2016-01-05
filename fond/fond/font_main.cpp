#include"fond.h"
void printArray(vector<int> nums)
{
	/*for (unsigned int i = 0; i < sums.size(); i++)
		cout << setw(4) << sums[i];*/
	vector<int>::iterator vecIte = nums.begin();
	while (vecIte != nums.end())
		cout << *vecIte++ << "\t";
	cout << endl;
}
void printVec(vector<int> nums)
{
	for (int i = 0; i < nums.size(); i++)
		cout << nums[i] << "\t";
	cout << "\n";
}
int main()
{
	/*int integerArray[] = { 5, 2, 7, 3, 4 };
	getCutMax(integerArray, 5, 1);*/
	//vector_man();
	/*srand((unsigned)time(NULL));
	vector<int> subSums;
	for (int i = 0; i < 100; i++)
	subSums.push_back(rand()%100 - 50);
	cout << "initial:" << "\n";
	printArray(subSums);
	vector<int> maxSumsRes = maxSubSum(subSums, 0, subSums.size() - 1);
	cout << "max sub sequence:" << endl;
	printArray(maxSumsRes);
	cout << "dp max sub sum:" << dpGetMaxSubSum(subSums);
	*/
	//graph_test();
	//vector<int> vec;
	//int i;
	//for (i = 0; i < 5; i++)
	//	vec.push_back(i + 1);
	//printVec(vec);
	//vector<int>::iterator vecIte = vec.begin();
	//vecIte += 3;
	//vec.insert(vecIte, 13);
	//printVec(vec);
	////cout << "pointer:" << *vecIte;
	//vecIte++;
	//vec.erase(vecIte);
	//printVec(vec);
	//vecIte = vec.end();
	//cout << "pointer:" << *(--vecIte);
	/*map<int, string> uMap;
	uMap.insert(make_pair(3, "zhoujianguo"));
	uMap.insert(make_pair(1, "wanyi"));
	uMap.insert(make_pair(0, "yiwu"));
	map<int, string>::iterator mapIte = uMap.begin();
	cout << "id=" << mapIte->first << "  value:" << mapIte->second << endl;*/
	vector<int> nums;
	srand(time(NULL));
	for (int i = 0; i <11; i++)
		nums.push_back(rand()%100);
	printArray(nums);
	cout << getLongestArray(nums);
	return 0;
}