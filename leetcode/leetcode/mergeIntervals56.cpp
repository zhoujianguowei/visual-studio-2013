#include"leetcode.h"
void quick_sort_interval(vector<Interval>& intervals, int left, int right)
{
	Interval temp;
	if (left < right)
	{
		int i = left, j = left;
		Interval monitor = intervals[right];
		for (; j < right; j++)
			if (intervals[j].start < monitor.start)
			{
				temp = intervals[i];
				intervals[i] = intervals[j];
				intervals[j] = temp;
				i++;
			}
		intervals[right] = intervals[i];
		intervals[i] = monitor;
		quick_sort_interval(intervals, left, i - 1);
		quick_sort_interval(intervals, i + 1, right);
	}

}

vector<Interval> merge(vector<Interval>& intervals)
{
	
	if (intervals.size() <= 1)
		return intervals;
	vector<Interval> resInterval;
	quick_sort_interval(intervals, 0, intervals.size() - 1);
	Interval newTemp = intervals[0];
	for (int i = 1; i < intervals.size(); i++)
	{
		while (i < intervals.size() && newTemp.end >= intervals[i].start)
		{
			newTemp.end = intervals[i].end>newTemp.end ? intervals[i].end : newTemp.end;
			i++;
		}
		resInterval.push_back(newTemp);
		if (i < intervals.size())
		{
			newTemp = intervals[i];
			if (i == intervals.size() - 1)
				resInterval.push_back(newTemp);
		}

	}
	return resInterval;

}