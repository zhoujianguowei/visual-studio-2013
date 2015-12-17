#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<iomanip>
#include<vector>
using namespace std;
const double MAX_FLOAT = 888888888.0;
double getMinTime(vector<int> wi, vector<int> si, int bridgeLoad, int bridgeLength, int veNum)
{
	int i, j;
	double *opt = new double[veNum + 1];
	opt[0] = 0;
	for (i = 0; i < veNum; i++)
	{
		double minTime = MAX_FLOAT;
		int minSpeed = si[i];
		int sumW = 0;
		for (j = i; j >= 0; j--)
		{
			sumW += wi[j];
			if (sumW > bridgeLoad)
				break;
			minSpeed = minSpeed < si[j] ? minSpeed : si[j];
			double time = opt[j] + (double)(60.0*bridgeLength) /minSpeed;
			minTime = minTime < time ? minTime : time;
		}
		opt[i + 1] = minTime;
	}
	return opt[veNum];
}
int first_main()
{
	int bridgeLoad, bridgeLength, veNum;
	while (1)
	{
		scanf("%d%d%d", &bridgeLoad, &bridgeLength, &veNum);
		if (bridgeLoad == 0 && bridgeLength == 0 && veNum == 0)
			break;
		vector<int> wi;
		vector<int> si;
		wi.reserve(veNum);
		si.reserve(veNum);
		for (int i = 0; i < veNum; i++)
		{
			int w, s;
			cin >> w >> s;
			wi.push_back(w);
			si.push_back(s);
		}
		//printf("%.1f\n", getMinTime(wi, si, bridgeLoad, bridgeLength, veNum));
		cout << setiosflags(ios::fixed) << setprecision(1) << getMinTime(wi, si, bridgeLoad, bridgeLength, veNum) << endl;

	}
	return 0;
}