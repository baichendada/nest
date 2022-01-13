# define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//void fun(char** p)
//{
//	int i;
//	for (i = 0; i < 4; i++)
//		printf("%s", p[i]);
//}
//
//void f(int** p)
//{
//
//}
//
//int main()
//{
//	/*char* s[6] = { "ABCD", "EFGH", "IJKL", "MNOP", "QRST", "UVWX" };
//	fun(s);
//	printf("\n");*/
//
//	/*int a[4] = { 1,2,3,4 };
//	int b[3][4] = { {1,2,3,4},{5,6,7,8},{9,10,11,12} };
//	int* q[3] = { b[0],b[1],b[2] };
//	f(&a);
//	f(b);
//	f(q);*/
//
//	int* k[10][30];
//	printf("%d\n", sizeof(k));
//	return 0;
//}


//if (str == NULL)
//return -1;
//int len = strlen(str);
//char tmp[len + 1];
//strcpy(tmp, str);
//qsort(tmp, len, 1, cmp_char);
//int i = 0;
//
//for (i = 0; i < len; i += 2)
//{
//    if (tmp[i] != tmp[i + 1])
//        break;
//}
//
//int j = 0;
//if (i < len)
//{
//    for (j = 0; j < len; j++)
//    {
//        if (str[j] == tmp[i])
//            break;
//    }
//}
//else
//return -1;
//
//return j;
//
//
//

// 第一个只出现一次的字符

// 优化思路：统计完每个字母的个数后，直接在原字符串中找就行，不用再开空间
int cmp(const void* e1, const void* e2)
{
    return (*(int*)e1) - (*(int*)e2);
}

//int FirstNotRepeatingChar(char* str) {
//    if (str == NULL)
//        return -1;
//
//    int a[52] = { 0 };
//    int len = strlen(str);
//    // 遍历一遍数组，统计个数
//    for (int i = 0; i < len; i++)
//    {
//        if (str[i] >= 'a' && str[i] <= 'z')
//        {
//            a[str[i] - 'a']++;
//        }
//        else
//        {
//            a[str[i] - 'A' + 26]++;
//        }
//    }
//
//    // 统计哪几个字母出现了一次
//    int i = 0;
//    int k = 0;
//
//    int single[52] = { 0 };
//
//    for (i = 0; i < 52; i++)
//    {
//        if (a[i] == 1)
//        {
//
//            single[k++] = i;
//        }
//    }
//
//    // 遍历一遍数组，记录每个单独的字母在其中的位置，最后比较大小就行
//    int s[52] = { 0 };
//    int cnt = 0;
//    
//        while (--k >= 0)
//        {
//            for (int j = 0; j < len; j++)
//            {
//                if (str[j] >= 'a' && str[j] <= 'z')
//                {
//                    if (str[j] == single[k] + 'a')
//                        s[cnt++] = j;
//                }
//                else
//                {
//                    if (str[j] == single[k] + 'A' - 26)
//                        s[cnt++] = j;
//                }
//            }
//
//        }
//        
//        qsort(s, cnt, 4, cmp);
//        return s[0];
//    
//
//    return -1;
//}

int FirstNotRepeatingChar(char* str) {
    if (str == NULL)
        return -1;

    int a[52] = { 0 };
    int len = strlen(str);

    // 遍历一遍数组，统计个数
    for (int i = 0; i < len; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            a[str[i] - 'a']++;
        }
        else
        {
            a[str[i] - 'A' + 26]++;
        }
    }

    // 遍历原数组，找出最先出现的单独的数

    for (int i = 0; i < len; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            if (a[str[i] - 'a'] == 1)
            {
                return i;
            }
        }
        else
        {
            if (a[str[i] - 'A' + 26] == 1)
            {
                return i;
            }
        }
    }

    return -1;
}

int main()
{
    char str[] = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
    int cnt = FirstNotRepeatingChar(str);


    printf("%d", cnt);
    return 0;
}

// 判断字符是否唯一
bool isUnique(char* astr) {
    if (astr == NULL)
        return true;

    int a[52] = { 0 };
    int len = strlen(astr);
    // 遍历一遍数组，统计个数
    for (int i = 0; i < len; i++)
    {
        if (astr[i] >= 'a' && astr[i] <= 'z')
        {
            a[astr[i] - 'a']++;
        }
        else
        {
            a[astr[i] - 'A' + 26]++;
        }
    }

    for (int i = 0; i < len; i++)
    {
        if (astr[i] >= 'a' && astr[i] <= 'z')
        {
            if (a[astr[i] - 'a'] >= 2)
            {
                return false;
            }
        }
        else
        {
            if (a[astr[i] - 'A' + 26] >= 2)
            {
                return false;
            }
        }
    }
    return true;
}