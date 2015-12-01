#include"leetcode.h"
vector<Interval> insert(vector<Interval>& intervals, Interval newInterval)
{
	vector<Interval> resInterval;
	if (intervals.size() == 0)
	{
		resInterval.push_back(newInterval);
	}
	else

	{
		int i = 0;
		if (newInterval.end < intervals[0].start)
		{
			intervals.insert(intervals.begin(), newInterval);
			return intervals;
		}
		else if (newInterval.start>intervals[intervals.size() - 1].end)
		{
			intervals.push_back(newInterval);
			return intervals;
		}
		Interval insertInterval;
		int newIntervalLeft = -1, newIntervalRight = -1;
		for (; i < intervals.size(); i++)
		{
			if (newInterval.start>intervals[i].end)
				newIntervalLeft = i;
			if (newInterval.end >= intervals[i].start)
				newIntervalRight = i;
			else
				break;
		}
	
		int j = 0;
		for (; j <= newIntervalLeft; j++)
			resInterval.push_back(intervals[j]);
		if (newIntervalLeft == newIntervalRight)
		{
			resInterval.push_back(newInterval);
			for (j = newIntervalRight + 1; j < intervals.size(); j++)
				resInterval.push_back(intervals[j]);

		}
		else
		{
			insertInterval.start = newInterval.start < intervals[newIntervalLeft + 1].start ? newInterval.start : intervals[newIntervalLeft + 1].start;

			insertInterval.end = newInterval.end > intervals[newIntervalRight ].end ? newInterval.end : intervals[newIntervalRight ].end;
			resInterval.push_back(insertInterval);
			for (j = newIntervalRight + 1; j < intervals.size(); j++)
				resInterval.push_back(intervals[j]);
		}
	}
	return resInterval;

}