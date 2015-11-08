#include"fond.h"
void printArray(vector<int> sums)
{
	for (unsigned int i = 0; i < sums.size(); i++)
		cout << setw(4) << sums[i];
	cout << endl;
}
int main()
{
	/*int integerArray[] = { 5, 2, 7, 3, 4 };
	getCutMax(integerArray, 5, 1);*/
	//vector_man();
	srand((unsigned)time(NULL));
	vector<int> subSums;
	for (int i = 0; i < 100; i++)
		subSums.push_back(rand()%100 - 50);
	cout << "initial:" << "\n";
	printArray(subSums);
	vector<int> maxSumsRes = maxSubSum(subSums, 0, subSums.size() - 1);
	cout << "max sub sequence:" << endl;
	printArray(maxSumsRes);
	cout << "dp max sub sum:" << dpGetMaxSubSum(subSums);
	//recall();

	return 0;
}