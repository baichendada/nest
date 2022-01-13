# define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

//void test1()
//{
//	char a = 101;
//	int sum = 200;
//	a += 27; sum += a;
//	printf("%d\n", sum);
//}
//
//void test2()
//{
//	int value = 1024;
//	char condition = *((char*)(&value));
//	if (condition) value += 1; condition = *((char*)(&value));
//	if (condition) value += 1; condition = *((char*)(&value));
//	printf("%d %d", value, condition);
//}
//
////void func(char para[100])
////{
////	void* p = malloc(100);
////	printf("%d, %d\n", sizeof(para), sizeof(p));
////}
//
//void func(char* p) { p = p + 1; };
//
//
//int main()
//{
//	//test1();
//	//test2();
//
//	/*char s[100];
//	func(s);*/
//
//	char s[] = { '1', '2', '3', '4' };
//	func(s);
//	printf("%c", *s);
//	return 0;
//}
//


//#include <stdio.h>
//#include <math.h>
//
//int main()
//{
//    int max;
//
//    while (~scanf("%d", &max))
//    {
//        int ret = 0;
//        for (int i = 0; i <= max; i++)
//        {
//            
//            if ((i % 10) * (i % 10) % 10 != i % 10)
//                continue;
//            int count = 0;
//            int tmp = i;
//
//            while (tmp)
//            {
//                tmp /= 10;
//                count++;
//            }
//
//            if (i * i % (int)pow(10, count) == i)
//                ret++;
//        }
//
//        printf("%d\n", ret);
//    }
//    return 0;
//}

#include <stdio.h>
#include <math.h>

int main()
{
    int a;
    scanf("%d", &a);
    int count = 0;
    for (int i = 2; i < a; i++)
    {
        int flag = 1;
        for (int j = 2; j <= sqrt(i); j++)
        {
            if (i % j == 0)
            {
                flag = 0;
                break;
            }
        }
        if (flag)
            count++;
    }

    printf("%d\n", count);
    return 0;
}