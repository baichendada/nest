# define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

//typedef struct List_t
//{
//	struct List_t* next;
//	struct List_t* prev;
//	char data[0];
//}list_t;
//
//int main()
//{
//	printf("%d", sizeof(list_t));
//	return 0;
//}

void fut(int** s, int p[2][3])
{
	**s = p[1][1];
} 
int main()
{
	int a[2][3] = { 1,3,5,7,9,11 }, * p;
	p = (int*)malloc(sizeof(int));
	fut(&p, a);
	printf("%d", *p);
	return 0;
}



int multiply(int A, int B)
{
	// 思路：二进制乘法竖式
	if (B == 0)
	{
		return 0;
	}

	return (B & 1) ? A + (multiply(A, B >> 1) << 1) : (multiply(A, B >> 1) << 1);
}

#include <stdio.h>

// 判断不大于a的中有多少与7有关的数
int main()
{
    int a;

    while (~scanf("%d", &a))
    {
        int cnt = 0;

        for (int i = 7; i <= a; i++)
        {
            // 是否为7的倍数
            if (i % 7 == 0)
            {
                cnt++;
                continue;
            }
            int tmp = i;
            // 每一位是否等于7
            while (tmp)
            {
                if (tmp % 10 == 7)
                {
                    cnt++;
                    break;
                }
                tmp /= 10;
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}