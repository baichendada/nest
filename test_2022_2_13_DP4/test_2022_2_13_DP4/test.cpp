# define _CRT_SECURE_NO_WARNINGS

class Solution {
public:
    int minDistance(string word1, string word2) {
        if (word1.empty() || word2.empty())
            return max(word1.size(), word2.size());

        int len1 = word1.size();
        int len2 = word2.size();
        vector<vector<int>> ret(len1 + 1, vector<int>(len2 + 1, 0));

        // 初始化
        // j == 0 时
        for (int i = 0; i <= len1; ++i)
            ret[i][0] = i;
        // i == 0 时
        for (int i = 0; i <= len2; ++i)
            ret[0][i] = i;

        for (int i = 1; i <= len1; ++i)
        {
            for (int j = 1; j <= len2; ++j)
            {
                // 删除 or 插入
                ret[i][j] = min(ret[i - 1][j] + 1, ret[i][j - 1] + 1);

                // word1的第 i 个字符，对应索引为i - 1，word2同理
                if (word1[i - 1] == word2[j - 1])
                    ret[i][j] = min(ret[i - 1][j - 1], ret[i][j]);
                else
                    ret[i][j] = min(ret[i - 1][j - 1] + 1, ret[i][j]);
            }
        }

        return ret[len1][len2];
    }
};


class Solution {
public:
    int numDistinct(string S, string T) {
        int lenS = S.size();
        int lenT = T.size();

        vector<vector<int> > ret(lenS + 1, vector<int>(lenT + 1, 0));
        for (int i = 0; i <= lenS; ++i)
            ret[i][0] = 1;

        for (int i = 1; i <= lenS; ++i)
        {
            for (int j = 1; j <= lenT; ++j)
            {
                if (S[i - 1] == T[j - 1])
                    ret[i][j] = ret[i - 1][j] + ret[i - 1][j - 1];
                else
                    ret[i][j] = ret[i - 1][j];
            }
        }


        return ret[lenS][lenT];
    }
};

class Solution {
public:
    int numDistinct(string S, string T) {
        int lenS = S.size();
        int lenT = T.size();

        vector<int> ret(lenT + 1, 0);

        ret[0] = 1;

        for (int i = 1; i <= lenS; ++i)
        {
            for (int j = lenT; j >= 1; --j)
            {
                if (S[i - 1] == T[j - 1])
                    ret[j] = ret[j] + ret[j - 1];
                else
                    ret[j] = ret[j];
            }
        }

        return ret[lenT];
    }
};
