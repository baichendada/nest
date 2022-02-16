# define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <vector>
#include <list>
using namespace std;
// 某工厂有n个独立的作业，由m台相同的机器进行加工处理。作业i所需的加工时间为ti，任何作业在被处理时不能中
// 断，也不能进行拆分处理。现厂长请你给他写一个程序：算出n个作业由m台机器加工处理的最短时间


bool cmp(const int& x, const int& y)
{
	return x > y;
}

int greedStrategy(const vector<int>& works, vector<int>& machines)
{
	// 按工作时间长短排序
	sort(works.begin(), works.end(), cmp);
	int workNum = works.size();
	int machineNum = machines.size();

	if (workNum <= machineNum)
		return works[0];

	for (int i = 0; i < workNum; ++i)
	{
		int flag = 0;

		for (int j = 1; j < machineNum; ++j)
		{
			if (machines[j] < machines[flag])
				flag = j;
		}

		machines[flag] += works[i];
	}

	int max = 0;
	for(int e : machines)
	{ 
		if (e > max)
			max = e;
	}

	return max;
}


class Solution {
public:
	int maxEvents(vector<vector<int>>& events) {
		sort(events.begin(), events.end(), [](vector<int>& a, vector<int>& b) {
			if (a[1] != b[1]) return a[1] < b[1];
			return a[0] < b[0];
			});

		int num = 0;
		vector<bool> used(100001, false);

		for (auto e : events)
		{
			for (int i = e[0]; i <= e[1]; ++i)
			{
				if (!used[i])
				{
					used[i] = true;
					++num;
					break;
				}
			}
		}

		return num;
	}
};


class Solution {
public:
	int maxEvents(vector<vector<int>>& events) {
		priority_queue<int, vector<int>, greater<int>> pq;
		sort(events.begin(), events.end()); /* 按start对数组进行排序 */
		int curDay = 1;
		int i = 0;
		int n = events.size();
		int ans = 0;
		while (i < n || !pq.empty()) {
			/* 队列存储已经开始的会议, 按结束时间小根堆排序 */
			while (i < n && events[i][0] == curDay) {
				pq.push(events[i][1]);
				i++;
			}
			/* 已经结束的会议 */
			while (!pq.empty() && pq.top() < curDay) {
				pq.pop();
			}
			/* 贪心思想, 选择最早结束的会议参加 */
			if (!pq.empty()) {
				pq.pop();
				ans++;
			}
			curDay++;
		}
		return ans;
	}
};

bool cmp(const pair<int, int>& a, const pair<int, int>& b)
{
	return a.second < b.second;
}

int greedyActivitySelector(const vector<pair<int, int>>& act)
{
	// 按照结束时间从早到晚排序
	sort(act.begin(), act.end(), cmp);
	// 记录一个活动的结束时间
	int end = 1;
	int num = 0;

	// 遍历每一个活动
	for (auto e : act)
	{
		// 当一个活动的开始时间大于等于前一个被举行活动的结束时间时，执行这个活动
		if (e.first >= end)
		{
			end = e.second;
			++num;
		}
	}
	return num;
}


class Solution {
public:
	static bool cmp(const vector<int>& a, const vector<int>& b)
	{
		return a[1] < b[1];
	}
	int eraseOverlapIntervals(vector<vector<int>>& intervals) {
		if (intervals.size() == 0)
			return 0;
		sort(intervals.begin(), intervals.end(), cmp);
		int num = 1;
		int end = intervals[0][1];

		for (int i = 1; i < intervals.size(); ++i)
		{
			if (end <= intervals[i][0])
			{
				end = intervals[i][1];
				++num;
			}
		}

		return intervals.size() - num;
	}
};

class Solution {
public:
	static bool cmp(const vector<int>& a, const vector<int>& b)
	{
		return a[1] < b[1];
	}
	int eraseOverlapIntervals(vector<vector<int>>& intervals) {
		if (intervals.size() == 0)
			return 0;
		sort(intervals.begin(), intervals.end(), cmp);
		int num = 0;
		int end = INT_MIN;

		for (auto e : intervals)
		{
			if (end <= e[0])
			{
				end = e[1];
				++num;
			}
		}

		return intervals.size() - num;
	}
};


class Solution {
public:
	static bool cmp(const vector<int>& a, const vector<int>& b)
	{
		//按起点递增排序
		if (a[0] != b[0])
			return a[0] < b[0];
		return a[1] < b[1];
	}
	int eraseOverlapIntervals(vector<vector<int>>& intervals) {
		if (intervals.empty())
			return 0;
		sort(intervals.begin(), intervals.end(), cmp);
		int Dnum = 0;
		int end = intervals[0][1];
		int prev = intervals[0][0];

		for (int i = 1; i < intervals.size(); ++i)
		{
			if (end > intervals[i][0])
			{
				if (end > intervals[i][1])
				{
					prev = intervals[i][0];
					end = intervals[i][1];
				}
				++Dnum;
			}
			else
			{
				prev = intervals[i][0];
				end = intervals[i][1];
			}

		}

		return Dnum;
	}
};

class Solution {
public:
	static bool cmp(const vector<int>& a, const vector<int>& b)
	{
		//按起点递增排序
		if (a[0] != b[0])
			return a[0] < b[0];
		return a[1] < b[1];
	}
	int eraseOverlapIntervals(vector<vector<int>>& intervals) {
		if (intervals.empty())
			return 0;
		sort(intervals.begin(), intervals.end(), cmp);
		int Dnum = 0;
		int prev = 0;

		for (int i = 1; i < intervals.size(); ++i)
		{
			if (intervals[prev][1] > intervals[i][0])
			{
				if (intervals[prev][1] > intervals[i][1])
				{
					prev = i;
				}
				++Dnum;
			}
			else
			{
				prev = i;
			}

		}

		return Dnum;
	}
};