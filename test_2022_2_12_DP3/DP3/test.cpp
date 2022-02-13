# define _CRT_SECURE_NO_WARNINGS

class Solution {
public:
    bool isPal(string& s, int left, int right)
    {
        while (left < right)
        {
            if (s[left] != s[right])
                return false;
            left++;
            right--;
        }

        return true;
    }
    int minCut(string s) {
        if (s.empty())
            return 0;
        int len = s.size();
        int* ret = new int[len + 1];
        // 一个长为 i 的字符串，形成回文字符串，最多要被切 i - 1刀
        for (int i = 0; i <= len; ++i)
        {
            ret[i] = i - 1;
        }

        for (int i = 2; i <= len; ++i)
        {
            for (int j = 0; j <= i; j++)
            {
                // j + 1 到 i 的字符串是否为回文字符串
                if (isPal(s, j, i - 1))
                    ret[i] = min(ret[i], ret[j] + 1);
            }
        }

        return ret[len];
    }
};


class Solution {
public:
    vector<vector<bool> > getMat(string& s)
    {
        int len = s.size();
        vector<vector<bool> > mat = vector<vector<bool> >(len, vector<bool>(len, false));

        for (int i = len - 1; i >= 0; --i)
        {
            // 判断[i , j]范围内是否为回文
            for (int j = i; j < len; ++j)
            {
                if (j == i)
                    mat[i][j] = true;
                else if (j == i + 1)
                    mat[i][j] = (s[i] == s[j]);
                else
                    mat[i][j] = ((s[i] == s[j]) && mat[i + 1][j - 1]);
            }
        }
        return mat;
    }


    int minCut(string s) {
        if (s.empty())
            return 0;
        int len = s.size();
        int* ret = new int[len + 1];
        vector<vector<bool> > mat = getMat(s);
        // 一个长为 i 的字符串，形成回文字符串，最多要被切 i - 1刀
        for (int i = 0; i <= len; ++i)
        {
            ret[i] = i - 1;
        }

        for (int i = 2; i <= len; ++i)
        {
            for (int j = 0; j <= i; ++j)
            {
                // j + 1 到 i 的字符串是否为回文字符串
                if (mat[j][i - 1])
                    ret[i] = min(ret[i], ret[j] + 1);
            }
        }

        return ret[len];
    }
};


