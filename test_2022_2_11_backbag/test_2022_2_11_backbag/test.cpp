# define _CRT_SECURE_NO_WARNINGS

class Solution {
public:
    int backPackII(int m, vector<int>& A, vector<int>& V) {
        if (A.empty() || V.empty() || m < 1)
            return 0;

        const int N = A.size() + 1;
        const int M = m + 1;
        vector<vector<int> > ret;
        ret.resize(N);

        for (int i = 0; i != N; ++i) {
            ret[i].resize(M, 0);
        }

        for (int i = 1; i < N; i++)
        {
            for (int j = 1; j < M; j++)
            {
                if (j < A[i - 1])
                    ret[i][j] = ret[i - 1][j];
                else
                    ret[i][j] = max(ret[i - 1][j], ret[i - 1][j - A[i - 1]] + V[i - 1]);
            }
        }

        return ret[N - 1][m];
    }
};

class Solution {
public:
    int backPackII(int m, vector<int>& A, vector<int>& V) {
        if (A.empty() || V.empty() || m < 1)
            return 0;

        const int M = m + 1; // 包容量
        const int N = A.size() + 1; // 物品数量
        vector<int> ret(M, 0);

        for (int i = 1; i < N; i++)
        {
            // 上面的算法在计算第i行元素时，只用到第i-1行的元素，所以二维的空间可以优化为一维空间
            // 但是如果是一维向量，需要从后向前计算，因为后面的元素更新需要依靠前面的元素未更新（模拟二维矩阵的上一行的值）
            // 并且我们观察到，本行的元素只需要用到上一行的元素，所以从前往后，从后往前都相同
            // 且用到上一行元素的下标不会超过本行元素的下标
            for (int j = m; j >= 0; j--)
            {
                if (j >= A[i - 1])
                    ret[j] = max(ret[j], ret[j - A[i - 1]] + V[i - 1]);
            }
        }

        return ret[m];
    }
};