# define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

//#define a 10
//void foo();
//int main()
//{
//	printf("%d..", a);
//	foo();
//	printf("%d", a);
//	return 0;
//} 
//
//void foo() {
//#undef a
//#define a 50
//}


//int sequence(int n)
//{
//    if (n == 1)
//        return 1;
//    if (n == 2)
//        return 2;
//
//    return 2 * sequence(n - 1) + sequence(n - 2);
//}
//
//int main()
//{
//    int i;
//    sscanf("%d", &i);
//
//    while (i--)
//    {
//        int n;
//        scanf("%d", &n);
//
//        printf("%d\n", sequence(n) % 32767);
//    }
//    return 0;
//}

int main()
{
    char a[1000];

    while (gets(a))
    {
        char* tmp = a;
        int ch = 0, space = 0, num = 0, others = 0;

        while (*tmp)
        {
            if ((*tmp >= 'a' && *tmp <= 'z') || (*tmp >= 'A' && *tmp <= 'Z'))
            {
                ch++;
            }
            else if (*tmp == ' ')
            {
                space++;
            }
            else if (*tmp >= '0' && *tmp <= '9')
            {
                num++;
            }
            else
            {
                others++;
            }

            tmp++;
        }
        printf("%d\n%d\n%d\n%d\n", ch, space, num, others);
    }
    return 0;
}