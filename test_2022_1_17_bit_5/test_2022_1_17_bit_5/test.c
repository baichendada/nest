# define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

struct st
{
	int* p;
	int i;
	char a;
};

enum weekday
{
	sun,
	mon = 3,
	tue,
	wed
};
int main()
{
	//char arr[2][4];
	//strcpy(arr[0], "you");
	//strcpy(arr[1], "me");
	//arr[0][3] = '&';
	//printf("%s \n", arr);

	/*int sz = sizeof(struct st);
	printf("%d", sz);*/

	enum weekday workday;
	workday = sun;
	printf("%d\n", workday);
	return 0;
}

char* compressString(char* S) {
    int len = strlen(S);
    char* begin = S;
    char* ret = (char*)calloc(2 * len + 1, 1);
    int num = 0;// ���ٵĿռ���±�
    // ��begin��Ϊ\0����ѭ��
    while (*begin)
    {
        // ͳ�Ƹ���
        int count = 1;
        while (*begin == *(begin + 1))
        {
            count++;
            begin++;
        }
        ret[num++] = *begin++;
        // ������ת��Ϊ�ַ���
        int cnt = 0;
        char str[10] = { 0 };
        while (count)
        {
            int nums = count % 10;
            str[cnt++] = nums + '0';
            count /= 10;
        }

        while (cnt--)
        {
            ret[num++] = str[cnt];
        }

    }
    // �����˷�\0
    ret[num] = 0;
    // �Ƚ��ַ�������
    if (len <= num)
    {
        return S;
    }

    return ret;
}

int exchangeBits(int num) {
    return ((0x55555555 & num) << 1) | ((0xaaaaaaaa & num) >> 1);
}