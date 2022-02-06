# define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//void strcut(char* s, char a[][30], int* pi)
//{
//    char* next = s;
//    char* cur = s;
//
//    while (*s)
//    {
//        while (*s != ' ' && *s != 0)
//        {
//            s++;
//        }
//        if (*s != 0)
//        {
//            next = s + 1;
//            *s = 0;
//            int tmp = atoi(s - 1);
//            *(s - 1) = 0;
//            (*pi)++;
//            strcpy(a[tmp - 1], cur);
//            s = next;
//            cur = next;
//        }
//        else
//        {
//            *s = 0;
//            int tmp = atoi(s - 1);
//            *(s - 1) = 0;
//            (*pi)++;
//            strcpy(a[tmp - 1], cur);
//            break;
//        }
//    }
//}
//char* sortSentence(char* s) {
//    char* tmp = (char*)calloc(strlen(s) + 1, 1);
//    char a[9][30] = { 0 };
//    int cnt = 0;
//    strcut(s, a, &cnt);
//
//    for (int i = 0; i < cnt - 1; i++)
//    {
//        int len = strlen(a[i]);
//        a[i][len] = ' ';
//        a[i][len + 1] = 0;
//    }
//
//    for (int i = 0; i < cnt; i++)
//    {
//        strcat(tmp, a[i]);
//    }
//
//    return tmp;
//}
//
//int main()
//{
//    char s[] = "is2 sentence4 This1 a3";
//    //char a[9][30] = { 0 };
//    //int cnt = 0;
//    //strcut(s, a, &cnt);
//    char* ret = sortSentence(s);
//
//    printf("%s", ret);
//    return 0;
//}


void strcut(char* s, char a[][30], int* pi)
{
    char* cur = s;
    while (*s)
    {
        while (*s != ' ' && *s != 0)
        {
            s++;
        }
        char ch = *s;
        *s = 0;
        int tmp = atoi(s - 1);
        *(s - 1) = 0;
        (*pi)++;
        strcpy(a[tmp - 1], cur);
        if (ch != 0)
        {
            cur = s = s + 1;
        }
    }
}
char* sortSentence(char* s) {
    char* tmp = (char*)calloc(strlen(s) + 1, 1);
    char a[9][30] = { 0 };
    int cnt = 0;
    strcut(s, a, &cnt);

    for (int i = 0; i < cnt - 1; i++)
    {
        int len = strlen(a[i]);
        a[i][len] = ' ';
        a[i][len + 1] = 0;
    }

    for (int i = 0; i < cnt; i++)
    {
        strcat(tmp, a[i]);
    }

    return tmp;
}

void strcut(char* s, char a[][30], int* pi)
{
    // 记录每个单词的开头
    char* head = s;
    while (*s)
    {
        // 遍历s，直到遇到空格或者 \0 停止 
        while (*s != ' ' && *s != 0)
        {
            s++;
        }
        // 记录当前s所指向的字符，可能为空格或者\0
        char ch = *s;
        // 将单词分割
        *s = 0;
        // 将单词尾的数字字符转化为整形，也可以直接用 int tmp = *s - '0';
        int tmp = atoi(s - 1);
        // 将数字位置置为空格，以便于拷贝
        *(s - 1) = ' ';
        // 记录有多少个单词
        (*pi)++;
        // 按单词尾数字拷贝到相应的位置
        strcpy(a[tmp - 1], head);
        if (ch != 0)
        {
            // 如果没有到s末尾，继续下一个单词
            head = s = s + 1;
        }
    }
}
char* sortSentence(char* s) {
    // 用来存放单词
    char a[9][30] = { 0 };
    int cnt = 0;
    strcut(s, a, &cnt);
    memset(s, 0, strlen(s));
    // 追加字符串
    for (int i = 0; i < cnt; i++)
    {
        strcat(s, a[i]);
    }
    // 在倒数第二个位置，也就是多余空格的位置放上 \0
    s[strlen(s) - 1] = 0;
    return s;
}


int cmp(const void* e1, const void* e2)
{
    return *((int*)e1) - *((int*)e2);
}

int findLHS(int* nums, int numsSize) {
    // 对数组排升序
    qsort(nums, numsSize, sizeof(int), cmp);

    int prev = 0;
    int num = 0;
    // 双指针法，指针 prev 指向 与 i 指向的数字相差为1的数字中第一个数字
    for (int i = 1; i < numsSize; i++)
    {
        // 当两者差大于1时，prev向前移动，直到两者的差小于等于1
        while (nums[i] - nums[prev] > 1)
        {
            prev++;
        }
        // 当两者差等于1时，记录最长和谐子序列的长度
        if (nums[i] - nums[prev] == 1)
        {
            num = i - prev + 1 > num ? i - prev + 1 : num;
        }
    }

    return num;
}