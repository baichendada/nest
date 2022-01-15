# define _CRT_SECURE_NO_WARNINGS

#include<iostream>
using namespace std;

int main()
{
	const char* s[] = { "black", "white", "pink", "violet" };
	const char** ptr[] = { s + 3, s + 2, s + 1, s }, *** p;
	p = ptr;

	++p;
	cout << **p + 1 << endl;

	char str[sizeof("ab")];
	cout << sizeof("ab") << endl;
	cout << sizeof(str) << endl;

	printf("%d", sizeof("abcd"));
	return 0;
}

bool CheckPermutation(char* s1, char* s2) {
    // 先判断两个字符串长度是否相等
    int a[52] = { 0 };
    int len = strlen(s1);
    int len2 = strlen(s2);
    if (len != len2)
    {
        return false;
    }
    // 遍历一遍数组，统计个数
    for (int i = 0; i < len; i++)
    {
        if (s1[i] >= 'a' && s1[i] <= 'z')
        {
            a[s1[i] - 'a']++;
        }
        else
        {
            a[s1[i] - 'A' + 26]++;
        }
    }


    // 再遍历一遍另一个数组，每遇到一个字母在相应位置--，最后判断a数组的数字是否都为0
    for (int i = 0; i < len; i++)
    {
        if (s2[i] >= 'a' && s2[i] <= 'z')
        {
            a[s2[i] - 'a']--;
        }
        else
        {
            a[s2[i] - 'A' + 26]--;
        }
    }

    for (int i = 0; i < 52; i++)
    {
        if (a[i] != 0)
        {
            return false;
        }
    }

    return true;
}





bool canPermutePalindrome(char* s) {
    int a[128] = { 0 };
    int len = strlen(s);

    // 遍历一遍数组，统计个数
    for (int i = 0; i < len; i++)
    {
        a[s[i]]++;
    }

    // 判断一个字符串是否可以组成回文字符串
    // 1.字符串中至多有一个只出现一次的字符
    // 2.字符串中除了可能出现一次的字符串，其余字符均要出现偶数次

    int the_one = 0;// 只能为0或1

    for (int i = 0; i < 128; i++)
    {
        // 当计数为1时，如果the_one为0，则++；如果the_one大于等于0，则已经有出现一次的，返回false
        if (a[i] == 1)
        {
            if (the_one == 0)
            {
                the_one++;
            }
            else
            {
                return false;
            }
        }
        // 当出现大于2次时，如果为偶数，则通过；为奇数，则必须保证the_one 为1
        if (a[i] > 2)
        {
            if (a[i] % 2 == 1)
            {
                if (the_one == 1)
                {
                    return false;
                }

                if (the_one == 0)
                {
                    the_one++;
                }
            }
        }
    }

    return true;
}