# define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>
#include<math.h>

//void fun(const char* fname,const char* st)
//{
//	FILE* myf;
//	int i;
//	myf = fopen(fname, "w");
//	for (i = 0; i < strlen(st); i++) fputc(st[i], myf);
//	fclose(myf);
//}
//
////int main()
////{
////	fun("test.txt", "new world");
////	fun("test.txt", "hello,");
////	return 0;
////}


//int trailingZeroes(int n) {
//    int cnt = 0;
//    int tmp = n;
//    while (tmp / pow(5, cnt + 1))
//    {
//        cnt++;
//    }
//
//    int num = 0;
//    while (cnt)
//    {
//        num += (tmp / pow(5, cnt--));
//    }
//
//    return num;
//}
//
//
int trailingZeroes(int n) 
{
    int cnt = 0;

    // ����׳�β��0�Ĺؼ���ͳ�ƽ׳���5��������ĸ���
    while (n)
    {
        // ͳ��5���������n���ڳ����˶��ٴΣ�n/5�Ϳɵã���n=16��n / 5 = 3������5�ĸ���
        // ����� n = 25����ʱ n/5 = 5����Ȼ����5����˵�� n ��n������25���������25 = 5 * 5������ǰ��ֻ����һ��5
        // ��������ٶ���һ��25����������������ȫ���Դ����ơ�
        n /= 5;
        cnt += n;
    }
    return cnt;
}

#include <stdio.h>

int main()
{
    float input;
    scanf("%f", &input);
    int a = (int)input;

    if (input - (float)a < 0.5)
        printf("%d", a);
    else
        printf("%d", a + 1);
}