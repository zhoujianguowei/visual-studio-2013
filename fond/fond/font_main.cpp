#define _CRT_SECURE_NO_WARNINGS
#include"fond.h"
#include <cstdio>
#include<algorithm>
#include <cstring>
#include <iostream>
#include <vector> 
#define max(a,b) (a)>(b)?(a):(b)
using namespace std;
int main()
{
	FILE *file = fopen("d:\\nice.txt", "rb");
	//bigEndianPut(file);
	bigEndianGet(fopen("d:\\binary.bin", "rb"));
	transferAsiToBiChar(83);


}

