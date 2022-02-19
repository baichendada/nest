# define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;

//class Solution {
//public:
//    void Dfs(vector<int>& candidates, int target, vector<int> curWay, vector<vector<int>>& ret,
//        int curSum, int prev)
//    {
//        if (curSum >= target)
//        {
//            if (curSum == target)
//                ret.push_back(curWay);
//            return;
//        }
//
//        for (int i = prev; i < candidates.size(); ++i)
//        {
//            if (candidates[i] > target)
//                continue;
//            curWay.push_back(candidates[i]);
//            Dfs(candidates, target, curWay, ret, curSum + candidates[i], i);
//            curWay.pop_back();
//        }
//    }
//    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
//        vector<int> curWay;
//        vector<vector<int>> ret;
//        Dfs(candidates, target, curWay, ret, 0, 0);
//        return ret;
//    }
//};


static int des[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
class Solution {
public:
    void Dfs(vector<vector<int>>& grid, int row, int col, int x, int y, int& s,
        vector<vector<bool>>& book)
    {
        s += 4;
        book[x][y] = true;

        for (int i = 0; i < 4; ++i)
        {
            int newX = x + des[i][0];
            int newY = y + des[i][1];

            if (newX < 0 || newX >= row || newY < 0 || newY >= col)
                continue;
            if (grid[newX][newY] == 1 && book[newX][newY] == false)
                Dfs(grid, row, col, newX, newY, s, book);
            if (grid[newX][newY] == 1 && book[newX][newY] == true)
                --s;
        }
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int s = 0;
        vector<vector<bool>> book(row, vector<bool>(col, false));

        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                if (grid[i][j] == 1)
                {
                    Dfs(grid, row, col, i, j, s, book);
                    goto end;
                }
            }
        }
    end:
        return s;
    }
};
//int main()
//{
//    vector<vector<int>> grid = { {0, 1, 0, 0},{1, 1, 1, 0},{0, 1, 0, 0},{1, 1, 0, 0} };
//    Solution().islandPerimeter(grid);
//    return 0;
//}

static int des[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
class Solution {
public:
    void Dfs(vector<vector<int>>& grid, int row, int col, int x, int y, int& s,
        vector<vector<bool>>& book)
    {
        book[x][y] = true;

        for (int i = 0; i < 4; ++i)
        {
            int newX = x + des[i][0];
            int newY = y + des[i][1];

            if (newX < 0 || newX >= row || newY < 0 || newY >= col || grid[newX][newY] == 0)
            {
                ++s;
                continue;
            }

            if (grid[newX][newY] == 1 && book[newX][newY] == false)
                Dfs(grid, row, col, newX, newY, s, book);
        }
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int s = 0;
        vector<vector<bool>> book(row, vector<bool>(col, false));

        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                if (grid[i][j] == 1)
                {
                    Dfs(grid, row, col, i, j, s, book);
                    goto end;
                }
            }
        }
    end:
        return s;
    }
};

static int des[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
class Solution {
public:
    void Dfs(vector<vector<int>>& grid, int row, int col, int x, int y, int& s)
    {
        grid[x][y] = 2;

        for (int i = 0; i < 4; ++i)
        {
            int newX = x + des[i][0];
            int newY = y + des[i][1];

            if (newX < 0 || newX >= row || newY < 0 || newY >= col || grid[newX][newY] == 0)
            {
                ++s;
                continue;
            }

            if (grid[newX][newY] == 1)
                Dfs(grid, row, col, newX, newY, s);
        }
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int s = 0;

        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                if (grid[i][j] == 1)
                {
                    Dfs(grid, row, col, i, j, s);
                    goto end;
                }
            }
        }
    end:
        return s;
    }
};