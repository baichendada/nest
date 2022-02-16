# define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <vector>
#include <list>
using namespace std;
// ĳ������n����������ҵ����m̨��ͬ�Ļ������мӹ�������ҵi����ļӹ�ʱ��Ϊti���κ���ҵ�ڱ�����ʱ������
// �ϣ�Ҳ���ܽ��в�ִ����ֳ����������дһ���������n����ҵ��m̨�����ӹ���������ʱ��


bool cmp(const int& x, const int& y)
{
	return x > y;
}

int greedStrategy(const vector<int>& works, vector<int>& machines)
{
	// ������ʱ�䳤������
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
		sort(events.begin(), events.end()); /* ��start������������� */
		int curDay = 1;
		int i = 0;
		int n = events.size();
		int ans = 0;
		while (i < n || !pq.empty()) {
			/* ���д洢�Ѿ���ʼ�Ļ���, ������ʱ��С�������� */
			while (i < n && events[i][0] == curDay) {
				pq.push(events[i][1]);
				i++;
			}
			/* �Ѿ������Ļ��� */
			while (!pq.empty() && pq.top() < curDay) {
				pq.pop();
			}
			/* ̰��˼��, ѡ����������Ļ���μ� */
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
	// ���ս���ʱ����絽������
	sort(act.begin(), act.end(), cmp);
	// ��¼һ����Ľ���ʱ��
	int end = 1;
	int num = 0;

	// ����ÿһ���
	for (auto e : act)
	{
		// ��һ����Ŀ�ʼʱ����ڵ���ǰһ�������л�Ľ���ʱ��ʱ��ִ������
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
		//������������
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
		//������������
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