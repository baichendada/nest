# define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>

//void GetNext(const char* sub, int* next, int lenSub)
//{
// if (lenSub == 1)
	//{
	//next[0] = -1;
	//return;
	//}
//	// next[i]是sub[i]匹配不到以后跳到的位置
//	// sub[0 , next[i] - 1] 和 [i - k,i - 1]是相等的
//	// 但是sub[i]和sub[next[i]]不一定相等，只是它们前面有一段相等
//	next[0] = -1;
//	next[1] = 0;
//	int i = 2;// 从2开始遍历
//	int k = 0;// 上一个数的next值，当前也就是next[1]，也就是0
//
//	while (i < lenSub)
//	{
//		// 当sub[i-1]和sub[k]相同时，说明正好可以和前面相同的续上
//		// 已知next[i-1] = k，则next[i] = k + 1
//		if (k == -1 || sub[i - 1] == sub[k])
//		{
//			next[i] = k + 1;
//			++i;
//			++k;
//		}
//		else
//		{
//			k = next[k];
//		}
//	}
//}

void SupGetNext(const char* sub, int* next, int lenSub)
{
	if (lenSub == 1)
	{
		next[0] = -1;
		return;
	}
	// next[i]是sub[i]匹配不到以后跳到的位置
	// sub[0 , next[i] - 1] 和 [i - k,i - 1]是相等的
	// 但是sub[i]和sub[next[i]]不一定相等，只是它们前面有一段相等
	next[0] = -1;
	next[1] = 0;
	if (sub[0] == sub[1])
	{
		next[1] = -1;
	}
	int i = 2;// 从2开始遍历
	int k = 0;// 上一个数的next值，当前也就是next[1]，也就是0

	while (i < lenSub)
	{
		// 当sub[i-1]和sub[k]相同时，说明正好可以和前面相同的续上
		// 已知next[i-1] = k，则next[i] = k + 1
		if (k == -1 || sub[i - 1] == sub[k])
		{
			next[i] = k + 1;
			// 如果回退的字符和当前的字符相等，说明一旦这个字符不等于主串的字符，回退的字符也不等于主串的字符
			// 还要回退，这样是很浪费时间的，所以我们直接让这个字符回退到回退字符的回退位置
			if (sub[k + 1] == sub[i])
			{
				next[i] = next[k + 1];
			}
			++i;
			++k;
		}
		else
		{
			k = next[k];
		}
	}
}

int KMP(const char* str, const char* sub, int pos)
{
	assert(str && sub);
	int lenStr = strlen(str);
	int lenSub = strlen(sub);

	if (lenStr == 0 || lenSub == 0)
		return -1;
	if (pos < 0 || pos >= lenStr)
		return -1;

	int i = pos;// 记录主串遍历下标
	int j = 0;// 记录模式串的下标
	// 获取next数组
	int* next = (int*)malloc(sizeof(int) * lenSub);
	if (next == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}
	

	SupGetNext(sub, next, lenSub);
	

	while (i < lenStr && j < lenSub)
	{
		if (j == -1 || str[i] == sub[j])
		{
			++i;
			++j;
		}
		else
		{
			j = next[j];
		}
	}
	free(next);
	if (j == lenSub)
		return i - j;
	return -1;
}


int main()
{
	//printf("%d\n", KMP("ababcabcdabcde", "abcd", 0));// 5
	//printf("%d\n", KMP("ababcabcdabcde", "ab", 0));// 0
	//printf("%d\n", KMP("ababcabcdabcde", "abcdf", 0));// -1
	//printf("%d\n", KMP("ababcabcdabcde", "abcde", 0));// 9
	//printf("%d\n", KMP("ababcabcdabcde", "f", 0));// -1
	//printf("%d\n", KMP("aaaaaaab", "ab", 0));// 6
	printf("%d\n", KMP("ababababc", "abc", 0));
	return 0;
}

