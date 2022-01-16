# define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

//int main()
//{
//	/*char* str[3] = { "stra", "strb", "strc" };
//	char* p = str[0];
//	int i = 0;
//	while (i < 3)
//	{
//		printf("%s ", p++);
//		i++;
//	} 
//	return 0;*/
//
//	/*int m[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
//	int(*p)[4] = (int(*)[4])m;
//	printf("%d", p[1][2]);
//	return 0;*/
//
//	char p1[15] = "abcd", * p2 = "ABCD", str[50] = "xyz";
//	strcpy(str + 2, strcat(p1 + 2, p2 + 1));
//	printf("%s", str);
//	return 0;
//}

char* f(char* str, char ch)
{
	char* it1 = str;
	char* it2 = str;
	while (*it2 != '\0')
	{
		while (*it2 == ch)
		{
			it2++;
		} 
		*it1++ = *it2++;
	} 
	*it1 = 0;
	return str;
} 

//int main() {
//	char a[10];
//	strcpy(a, "abcdcccd");
//	printf("%s", f(a, 'c'));
//	return 0;
//}

// ¼òÐ´×Ö·û

#include <stdio.h>
#include <string.h>

//int main()
//{
//    char a[101] = { 0 };
//    int n;
//    scanf("%d", &n);
//
//    while (n--)
//    {
//        scanf("%s", a);
//        int len = strlen(a);
//
//        if (len >= 10)
//        {
//            char* end = a + len - 1;
//            printf("%c%d%c\n", *a, len - 2, *end);
//            continue;
//        }
//
//        printf("%s\n", a);
//    }
//
//    return 0;
//}

char* replaceSpaces(char* S, int length) {
    if (S == NULL)
        return S;
    int len = strlen(S);
    int gap = len - length;
    char* end = S + len - 1, * rend = S + length - 1;
    *(end + 1) = 0;
    while (rend >= S)
    {
        if (*rend == ' ')
        {
            *end-- = '0';
            *end-- = '2';
            *end-- = '%';
            rend--;
            gap -= 2;
        }
        else
            *end-- = *rend--;
    }
    return S + gap;
}

int main()
{
    char a[] = "ds sdfs afs sdfa dfssf asdf             ";
    char* ret = replaceSpaces(a, 27);

    printf("%s", ret);
    return 0;
}