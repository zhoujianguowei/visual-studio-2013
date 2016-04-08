#include"post_leetcode.h"
using namespace std;
void printMatrix(vector<vector<int>> res)
{
	int i = 0;
	for (; i < res.size(); i++)
		printVec(res.at(i));

}

int main()
{
	int nodes[] = { 1, 2, 3, 4, 5 ,6,7,8,9,10,11};
	reverseKGroup(getPointer(nodes, 11), 20);
	return 0;
}