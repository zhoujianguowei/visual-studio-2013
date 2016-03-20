#include"leetcode.h"
int main()
{

	/*vector<vector<char>> board;
	for (int i = 0; i < 9; i++)
	{
	vector<char> vec;
	for (int j = 0; j < 9; j++)
	{
	vec.push_back(j + '1');
	}
	board.push_back(vec);
	}
	cout<<isValidSudoku(board);*/
	//letterCombinations("23");
	srand(time(NULL));
	vector<int> nums;
	for (int i = 0; i < 40; i++)
		nums.push_back(rand() %51);
	cout << "origin list:" << endl;
	printVec(nums);
	simple_quick_sort(nums, 0, nums.size() - 1);
	cout << "sorted list:" << endl;
	printVec(nums);


	return 0;
}



























