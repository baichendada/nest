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
    int num = 0;// 开辟的空间的下标
    // 当begin不为\0进入循环
    while (*begin)
    {
        // 统计个数
        int count = 1;
        while (*begin == *(begin + 1))
        {
            count++;
            begin++;
        }
        ret[num++] = *begin++;
        // 将个数转化为字符串
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
    // 别忘了放\0
    ret[num] = 0;
    // 比较字符串长度
    if (len <= num)
    {
        return S;
    }

    return ret;
}

int exchangeBits(int num) {
    return ((0x55555555 & num) << 1) | ((0xaaaaaaaa & num) >> 1);
}