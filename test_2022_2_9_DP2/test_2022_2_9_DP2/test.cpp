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
    
    int uniquePaths(int m, int n) {
        long long ret = 1;

        for (int i = n, j = 1; j < m; i++, j++)
            ret = ret * i / j;

        return ret;
    }
};


class Solution {
public:
    int minPathSum(vector<vector<int> >& grid) {
        int m = grid.size();
        int n = grid[0].size();

        for (int i = 1; i < m; i++)
            grid[i][0] = grid[i - 1][0] + grid[i][0];

        for (int i = 1; i < n; i++)
            grid[0][i] = grid[0][i - 1] + grid[0][i];

        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
                grid[i][j] = min(grid[i - 1][j], grid[i][j - 1]) + grid[i][j];
        }

        return grid[m - 1][n - 1];
    }
};