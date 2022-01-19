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

    // 计算阶乘尾数0的关键是统计阶乘中5这个因数的个数
    while (n)
    {
        // 统计5这个因数在n以内出现了多少次，n/5就可得，如n=16，n / 5 = 3，就是5的个数
        // 但如果 n = 25，这时 n/5 = 5，仍然大于5，就说明 n 及n以内有25这个因数，25 = 5 * 5，所以前面只算了一次5
        // 后面必须再多算一次25因数个数才能算完全，以此类推。
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