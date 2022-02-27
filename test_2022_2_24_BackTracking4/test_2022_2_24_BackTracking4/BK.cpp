# define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
using namespace std;

//class Solution {
//public:
//    void Dfs(vector<string>& ret, int cnt, vector<int>& hour, vector<int>& minute,
//        int hourNum, int minNum, int curH, int curM)
//    {
//        if (cnt == 0)
//        {
//            if (curH < 12 && curM < 60)
//            {
//                string h = to_string(curH);
//                string min = to_string(curM);
//                h += ':';
//                h += min;
//                ret.push_back(h);
//            }
//            return;
//        }
//        for (int i = hourNum; i < hour.size(); ++i)
//        {
//            cur += hour[hourNum];
//
//        }
//    }
//    vector<string> readBinaryWatch(int turnedOn) {
//
//    }
//};
//
//
int hour[4] = { 1, 2, 4, 8 };
int minute[6] = { 1, 2, 4, 8, 16, 32 };
class Solution {
public:
    int Binary_1(int x)
    {
        int cnt = 0;
        while (x)
        {
            x = x & (x - 1);
            cnt++;
        }
        return cnt;
    }
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> ret;

        for (int h = 0; h < 12; h++)
        {
            for (int min = 0; min < 60; min++)
            {
                if (Binary_1(h) + Binary_1(min) == turnedOn)
                {
                    ret.push_back(to_string(h) + ":" + (min < 10 ? "0" + to_string(min) : to_string(min)));
                }
            }
        }
        return ret;
    }
};

int Time[10] = { 1, 2, 4, 8, 1, 2, 4, 8, 16, 32 };
class Solution {
public:

    void Dfs(vector<string>& ret, int num, int pos, int curHour, int curMinute)
    {
        if (curHour >= 12 || curMinute >= 60)
            return;
        if (num == 0)
        {
            ret.push_back(to_string(curHour) + ":" + (curMinute > 9 ? to_string(curMinute) : "0" + to_string(curMinute)));
            return;
        }

        for (int i = pos; i < 10; ++i)
        {        
            if (i < 4)
            {
                curHour += Time[i];
                Dfs(ret, num - 1, i + 1, curHour, curMinute);
                curHour -= Time[i];
            }
            else
            {
                curMinute += Time[i];
                Dfs(ret, num - 1, i + 1, curHour, curMinute);
                curMinute -= Time[i];
            }
        }

    }
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> ret;

        Dfs(ret, turnedOn, 0, 0, 0);

        return ret;
    }
};

int main()
{
    Solution().readBinaryWatch(9);
    return 0;
}