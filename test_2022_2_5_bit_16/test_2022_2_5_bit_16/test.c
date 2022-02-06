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
    // ��¼ÿ�����ʵĿ�ͷ
    char* head = s;
    while (*s)
    {
        // ����s��ֱ�������ո���� \0 ֹͣ 
        while (*s != ' ' && *s != 0)
        {
            s++;
        }
        // ��¼��ǰs��ָ����ַ�������Ϊ�ո����\0
        char ch = *s;
        // �����ʷָ�
        *s = 0;
        // ������β�������ַ�ת��Ϊ���Σ�Ҳ����ֱ���� int tmp = *s - '0';
        int tmp = atoi(s - 1);
        // ������λ����Ϊ�ո��Ա��ڿ���
        *(s - 1) = ' ';
        // ��¼�ж��ٸ�����
        (*pi)++;
        // ������β���ֿ�������Ӧ��λ��
        strcpy(a[tmp - 1], head);
        if (ch != 0)
        {
            // ���û�е�sĩβ��������һ������
            head = s = s + 1;
        }
    }
}
char* sortSentence(char* s) {
    // ������ŵ���
    char a[9][30] = { 0 };
    int cnt = 0;
    strcut(s, a, &cnt);
    memset(s, 0, strlen(s));
    // ׷���ַ���
    for (int i = 0; i < cnt; i++)
    {
        strcat(s, a[i]);
    }
    // �ڵ����ڶ���λ�ã�Ҳ���Ƕ���ո��λ�÷��� \0
    s[strlen(s) - 1] = 0;
    return s;
}


int cmp(const void* e1, const void* e2)
{
    return *((int*)e1) - *((int*)e2);
}

int findLHS(int* nums, int numsSize) {
    // ������������
    qsort(nums, numsSize, sizeof(int), cmp);

    int prev = 0;
    int num = 0;
    // ˫ָ�뷨��ָ�� prev ָ�� �� i ָ����������Ϊ1�������е�һ������
    for (int i = 1; i < numsSize; i++)
    {
        // �����߲����1ʱ��prev��ǰ�ƶ���ֱ�����ߵĲ�С�ڵ���1
        while (nums[i] - nums[prev] > 1)
        {
            prev++;
        }
        // �����߲����1ʱ����¼���г�����еĳ���
        if (nums[i] - nums[prev] == 1)
        {
            num = i - prev + 1 > num ? i - prev + 1 : num;
        }
    }

    return num;
}