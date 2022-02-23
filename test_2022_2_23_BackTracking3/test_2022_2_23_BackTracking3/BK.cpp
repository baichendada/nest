#define _CRT_SECURE_NO_WARNINGS

static int des[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
class Solution {
public:
    void Dfs(vector<vector<int>>& grid, int row, int col, int x, int y, int& s)
    {
        // ����һ��½�أ������һ�������Ϊ2�������Ѿ�������
        ++s;
        grid[x][y] = 2;

        for (int i = 0; i < 4; ++i)
        {
            int newX = x + des[i][0];
            int newY = y + des[i][1];
            //  �ж��������Ƿ�Խ��
            if (newX < 0 || newX >= row || newY < 0 || newY >= col)
                continue;
            // ��������������ػ�û�б�����
            if (grid[newX][newY] == 1)
                Dfs(grid, row, col, newX, newY, s);
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int Max = 0;
        int row = grid.size();
        int col = grid[0].size();

        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                int s = 0;
                if (grid[i][j] == 1)
                    Dfs(grid, row, col, i, j, s);
                // ����������ֵ
                Max = max(s, Max);
            }
        }

        return Max;
    }
};