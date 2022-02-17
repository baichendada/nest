# define _CRT_SECURE_NO_WARNINGS

class Solution {
public:
    int balancedStringSplit(string s) {
        int len = s.size();
        int cnt = 0, num = 0;

        for (int i = 0; i < len; ++i)
        {
            if (s[i] == 'R')
                --cnt;
            else
                ++cnt;

            if (cnt == 0)
                ++num;
        }

        return num;
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int day = prices.size();
        int profit = 0;

        for (int i = 1; i < day; ++i)
        {
            if (prices[i] > prices[i - 1])
                profit += prices[i] - prices[i - 1];
        }

        return profit;
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int day = prices.size();
        vector<vector<int> > ret(day, vector<int>(2, 0));
        ret[0][0] = 0;
        ret[0][1] = -prices[0];

        for (int i = 1; i < day; ++i)
        {
            ret[i][0] = max(ret[i - 1][0], ret[i - 1][1] + prices[i]);
            ret[i][1] = max(ret[i - 1][1], ret[i - 1][0] - prices[i]);
        }

        return ret[day - 1][0];
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int day = prices.size();
        int ret[2];
        ret[0] = 0;
        ret[1] = -prices[0];
        int tmp0 = ret[0];
        int tmp1 = ret[1];

        for (int i = 1; i < day; ++i)
        {
            ret[0] = max(tmp0, tmp1 + prices[i]);
            ret[1] = max(tmp1, tmp0 - prices[i]);
            tmp0 = ret[0];
            tmp1 = ret[1];
        }

        return ret[0];
    }
};

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxLen = 0;
        int len = nums.size();

        for (int i = 0; i < len; ++i)
        {
            if (maxLen < i)
                return false;

            maxLen = max(i + nums[i], maxLen);
        }

        return true;
    }
};

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxLen = 0;
        int len = nums.size();

        for (int i = 0; i < len; ++i)
        {
            // 必须要判断前面最大能不能到达这个点
            // 能到达才更新，不能到达就不更新
            if (i <= maxLen)
                maxLen = max(i + nums[i], maxLen);

            // 遇到最大到达距离大于等于最后一个数的下标就返回true
            if (maxLen >= len - 1)
                return true;

        }

        return false;
    }
};