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

        const int M = m + 1; // ������
        const int N = A.size() + 1; // ��Ʒ����
        vector<int> ret(M, 0);

        for (int i = 1; i < N; i++)
        {
            // ������㷨�ڼ����i��Ԫ��ʱ��ֻ�õ���i-1�е�Ԫ�أ����Զ�ά�Ŀռ�����Ż�Ϊһά�ռ�
            // ���������һά��������Ҫ�Ӻ���ǰ���㣬��Ϊ�����Ԫ�ظ�����Ҫ����ǰ���Ԫ��δ���£�ģ���ά�������һ�е�ֵ��
            // �������ǹ۲쵽�����е�Ԫ��ֻ��Ҫ�õ���һ�е�Ԫ�أ����Դ�ǰ���󣬴Ӻ���ǰ����ͬ
            // ���õ���һ��Ԫ�ص��±겻�ᳬ������Ԫ�ص��±�
            for (int j = m; j >= 0; j--)
            {
                if (j >= A[i - 1])
                    ret[j] = max(ret[j], ret[j - A[i - 1]] + V[i - 1]);
            }
        }

        return ret[m];
    }
};