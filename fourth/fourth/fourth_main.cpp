#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<iomanip>
#include<vector>
using namespace std;
const float MAX_FLOAT = 888888888.0f;
vector<int> getWeight_Speed(vector<int> wi, vector<int> si, int i, int j)
{
	vector<int> ws;
	int weight = 0, minSpeed = si[i];
	for (int k = i; k <= j; k++)
	{
		weight += wi[k];
		minSpeed = minSpeed < si[k] ? minSpeed : si[k];

	}
	ws.push_back(weight);
	ws.push_back(minSpeed);
	return ws;
}
float getMinTime(vector<int> si, vector<int> wi, int bridgeLoad, int bridgeLength, int veNum)
{
	int i, j;
	float *opt = new float[veNum + 1];
	opt[0] = 0;
	vector< vector<float> > e;
	for (i = 0; i < veNum; i++)
	{
		vector<float> iE;
		for (j = 0; j < veNum; j++)
		{
			vector<int> ws = getWeight_Speed(si, wi, i, j);
			if (ws[0] > bridgeLoad)
				while (j < veNum)
				{
					iE.push_back(MAX_FLOAT);
					j++;
				}
			else
			{
				iE.push_back(60.0f*bridgeLength / ws[1]);
			}
		}
		e.push_back(iE);
	}
	for (i = 0; i < veNum; i++)
	{
		float minTime = MAX_FLOAT;
		for (j = i; j >=0; j--)
		{
			vector<float> ie = e[j];
			float time = ie[i] + opt[j];
			if (time >= MAX_FLOAT)
				break;
			minTime = minTime < time ? minTime : time;
		}
		opt[i + 1] = minTime;
	}
	return opt[veNum];
}
int main()
{
	/*float c = 1.254;
	cout << setiosflags(ios::fixed) << setprecision(1) << c << endl;*/
	int bridgeLoad, bridgeLength, veNum;
	while (1)
	{
		scanf("%d%d%d", &bridgeLoad, &bridgeLength, &veNum);
		if (bridgeLoad == 0 && bridgeLength == 0 && veNum == 0)
			break;
		vector<int> wi;
		vector<int> si;
		for (int i = 0; i < veNum; i++)
		{
			int w, s;
			cin >> w >> s;
			wi.push_back(w);
			si.push_back(s);
		}
		cout << setiosflags(ios::fixed) << setprecision(1) << getMinTime(wi, si, bridgeLoad, bridgeLength, veNum) << endl;

	}
	return 0;
}