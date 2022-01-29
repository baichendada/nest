# define _CRT_SECURE_NO_WARNINGS

//char* makeGood(char* s) {
//    int len = strlen(s);
//    int i, before = -1;
//
//    while (len != before)
//    {
//        before = len;
//
//        for (i = 0; i < len; i++)
//        {
//            if (s[i] >= 'a' && s[i] <= 'z')
//            {
//                if (s[i + 1] + 32 == s[i])
//                {
//                    for (; i + 2 <= len; i++)
//                    {
//                        s[i] = s[i + 2];
//                    }
//                    len -= 2;
//                }
//            }
//            else
//            {
//                if (s[i + 1] - 32 == s[i])
//                {
//                    for (; i + 2 <= len; i++)
//                    {
//                        s[i] = s[i + 2];
//                    }
//                    len -= 2;
//                }
//            }
//
//        }
//    }
//
//    return s;
//}

#include <stdio.h>
#include <string.h>

char* makeGood(char* s) 
{
    int len = strlen(s);

    for (int i = 0; i < len; i++)
    {
        if (s[i + 1] + 32 == s[i] || s[i + 1] - 32 == s[i])
        {
            for (int j = i + 2; j <= len; j++)
            {
                s[j] = s[j + 2];
            }
            len -= 2;

            if (i != 0)
                i -= 2;
            else
                --i;
        }
    }

    return s;
}

int main()
{
    char a[10] = "abBAcC";
    makeGood(a);
    return 0;
}

// 模拟栈实现
char* makeGood(char* s) {
    int len = strlen(s);
    char* stack = (char*)malloc(len + 1);
    int top = 0;

    for (int i = 0; i < len; i++)
    {
        // 入栈
        stack[top++] = s[i];

        if (top > 1 && (stack[top - 2] + 32 == s[i] || stack[top - 2] - 32 == s[i]))
        {
            top -= 2;
        }
    }
    stack[top] = 0;
    return stack;
}


int a[1000];
void PrevTra(struct TreeNode* root, int* pi)
{
    if (root == NULL)
        return;

    int flag = 1;
    for (int j = 0; j < *pi; j++)
    {
        if (a[j] == root->val)
        {
            flag = 0;
            break;
        }
    }

    if (flag)
    {
        a[(*pi)++] = root->val;
    }

    PrevTra(root->left, pi);
    PrevTra(root->right, pi);

    return;
}

int numColor(struct TreeNode* root) {
    int i = 0;
    PrevTra(root, &i);
    return i;
}

int a[1001];
void PrevTra(struct TreeNode* root)
{
    if (root)
    {
        a[root->val]++;
        PrevTra(root->left);
        PrevTra(root->right);
    }
}

int numColor(struct TreeNode* root) {
    memset(a, 0, sizeof(a));
    PrevTra(root);
    int num = 0;
    for (int i = 0; i < 1001; i++)
    {
        if (a[i])
            num++;
    }
    return num;
}