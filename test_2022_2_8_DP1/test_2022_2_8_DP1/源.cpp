# define _CRT_SECURE_NO_WARNINGS

class Solution {
public:
    int Fibonacci(int n) {
        int fib1 = 1;
        int fib2 = 1;
        int f;

        if (n == 1 || n == 2)
            return 1;

        for (int i = 3; i <= n; i++)
        {
            f = fib1 + fib2;

            fib2 = fib1;
            fib1 = f;
        }

        return f;
    }
};

class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& dict) {
        if (s.empty())
            return false;
        if (dict.empty())
            return false;

        vector<bool> can_spe(s.size() + 1, false);
        can_spe[0] = true;

        for (int i = 1; i <= s.size(); i++)
        {
            for (int j = i - 1; j >= 0; j--)
            {
                if (can_spe[j] && dict.find(s.substr(j, i - j)) != dict.end())
                {
                    can_spe[i] = true;
                    break;
                }
            }
        }

        return can_spe[s.size()];
    }
};

class Solution {
public:
    int minimumTotal(vector<vector<int> >& triangle) {
        if (triangle.empty())
            return 0;

        int row = triangle.size();

        for (int i = 1; i < row; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                if (j == 0)
                    triangle[i][0] = triangle[i - 1][0] + triangle[i][0];
                else if (j == i)
                    triangle[i][j] = triangle[i - 1][j - 1] + triangle[i][j];
                else
                    triangle[i][j] = min(triangle[i - 1][j], triangle[i - 1][j - 1]) + triangle[i][j];
            }
        }

        int Min = triangle[row - 1][0];

        for (int j = 1; j < row; j++)
            Min = min(Min, triangle[row - 1][j]);

        return Min;
    }
};
