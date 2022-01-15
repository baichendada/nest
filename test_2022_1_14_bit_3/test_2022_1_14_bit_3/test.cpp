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
    // ���ж������ַ��������Ƿ����
    int a[52] = { 0 };
    int len = strlen(s1);
    int len2 = strlen(s2);
    if (len != len2)
    {
        return false;
    }
    // ����һ�����飬ͳ�Ƹ���
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


    // �ٱ���һ����һ�����飬ÿ����һ����ĸ����Ӧλ��--������ж�a����������Ƿ�Ϊ0
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

    // ����һ�����飬ͳ�Ƹ���
    for (int i = 0; i < len; i++)
    {
        a[s[i]]++;
    }

    // �ж�һ���ַ����Ƿ������ɻ����ַ���
    // 1.�ַ�����������һ��ֻ����һ�ε��ַ�
    // 2.�ַ����г��˿��ܳ���һ�ε��ַ����������ַ���Ҫ����ż����

    int the_one = 0;// ֻ��Ϊ0��1

    for (int i = 0; i < 128; i++)
    {
        // ������Ϊ1ʱ�����the_oneΪ0����++�����the_one���ڵ���0�����Ѿ��г���һ�εģ�����false
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
        // �����ִ���2��ʱ�����Ϊż������ͨ����Ϊ����������뱣֤the_one Ϊ1
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