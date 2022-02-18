# define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

static int des[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
class Solution {
public:
    void Dfs(vector<vector<char>>& board, int row, int col, int x, int y)
    {
        board[x][y] = '*';

        for (int i = 0; i < 4; ++i)
        {
            int newX = x + des[i][0];
            int newY = y + des[i][1];

            if (newX < 0 || newX >= row || newY < 0 || newY >= col)
                continue;
            if (board[newX][newY] == 'O')
                Dfs(board, row, col, newX, newY);
        }
    }
    void solve(vector<vector<char>>& board) {
        int row = board.size();
        int col = board[0].size();

        for (int i = 0; i < row; ++i)
        {
            if (board[i][0] == 'O')
                Dfs(board, row, col, i, 0);
            if (board[i][col - 1] == 'O')
                Dfs(board, row, col, i, col - 1);
        }

        for (int j = 1; j < col - 1; ++j)
        {
            if (board[0][j] == 'O')
                Dfs(board, row, col, 0, j);
            if (board[row - 1][j] == 'O')
                Dfs(board, row, col, row - 1, j);
        }

        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                if (board[i][j] == '*')
                    board[i][j] = 'O';
                else if (board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }

    }
};




//int main()
//{
//    vector<vector<char> > input(4, vector<char>(4, 'X'));
//    input[1][1] = input[1][2] = input[2][2] = input[3][1] = 'O';
//
//    Solution().solve(input);
//    return 0;
//}

static int des[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
class Solution {
public:
    void Dfs(vector<vector<char>>& grid, int row, int col, int x, int y)
    {
        grid[x][y] = '0';

        for (int i = 0; i < 4; ++i)
        {
            int newX = x + des[i][0];
            int newY = y + des[i][1];

            if (newX < 0 || newX >= row || newY < 0 || newY >= col)
                continue;
            if (grid[newX][newY] == '1')
                Dfs(grid, row, col, newX, newY);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int num = 0;

        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                if (grid[i][j] == '1')
                {
                    Dfs(grid, row, col, i, j);
                    ++num;
                }
            }
        }

        return num;
    }
};

static int des[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
class Solution {
public:
    void Dfs(vector<vector<char>>& grid, int row, int col, int x, int y, vector<vector<bool>>& book)
    {
        book[x][y] = true;

        for (int i = 0; i < 4; ++i)
        {
            int newX = x + des[i][0];
            int newY = y + des[i][1];

            if (newX < 0 || newX >= row || newY < 0 || newY >= col)
                continue;
            if (grid[newX][newY] == '1' && book[newX][newY] == false)
                Dfs(grid, row, col, newX, newY, book);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int num = 0;
        vector<vector<bool>> book(row, vector<bool>(col, false));

        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                if (grid[i][j] == '1' && book[i][j] == false)
                {
                    Dfs(grid, row, col, i, j, book);
                    ++num;
                }
            }
        }

        return num;
    }
};

static string harsh[] = { "", "", "abc", "def", "ghi", "jkl", "mno",
"pqrs", "tuv", "wxyz" };
class Solution {
public:
    void Dfs(string& digits, int index, string curStr, vector<string>& ret)
    {
        if (curStr.size() == digits.size())
        {
            if (!curStr.empty())
                ret.push_back(curStr);
            return;
        }
        int curInd = digits[index] - '0';
        for (auto& ch : harsh[curInd])
        {
            Dfs(digits, index + 1, curStr + ch, ret);
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ret;
        Dfs(digits, 0, "", ret);
        return ret;
    }
};