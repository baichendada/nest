# define _CRT_SECURE_NO_WARNINGS

class Solution {
public:

    int uniquePaths(int m, int n) {
        if (m == 1 || n == 1)
            return 1;

        return uniquePaths(m - 1, n) + uniquePaths(m, n - 1);
    }
};

class Solution {
public:

    int uniquePaths(int m, int n) {
        if (m == 1 || n == 1)
            return 1;
        vector<vector<int> > a(m, vector<int>(n, 1));


        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
                a[i][j] = a[i][j - 1] + a[i - 1][j];
        }

        return a[m - 1][n - 1];
    }
};

class Solution {
public:
    /**
     *
     * @param m int整型
     * @param n int整型
     * @return int整型
     */
    int uniquePaths(int m, int n) {
        long long ret = 1;

        for (int i = n, j = 1; j < m; i++, j++)
            ret = ret * i / j;

        return ret;
    }
};