# define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <assert.h>
#include <string.h>

// str是主串，也就是要被查找的字符串
// tar是子串，也就是目标字符串
int BF(const char* str, const char* tar)
{
	assert(str && tar);
	if (str == NULL || tar == NULL)
		return -1;

	int lenStr = strlen(str);
	int lenTar = strlen(tar);
	int i = 0, j = 0;

	while (i < lenStr && j < lenTar)
	{
		// 两个字符相等，一起向后走，比较下一个字符
		if (str[i] == tar[j])
		{
			++i;
			++j;
		}
		// 不相等，i 跳到上一次开始的后一个位置，i - j + 1中 j 相当于向后走的步数，因为j每次从0开始
		// i - j就为回到str上一次的起始位置，+1就是向后跳一个位置，也即回到上一次开始的后一个位置
		// 不相等，j回到0位置继续匹配
		else
		{
			i = i - j + 1;
			j = 0;
		}
	}
	// 当子串走完时，说明找到了，返回str上一次的起始位置
	if (j == lenTar)
		return i - j;
	// 子串没走完，主串走完了，就说明没找到，返回-1
	return -1;
}

int main()
{
	printf("%d\n", BF("ababcabcdabcde", "abcd"));// 5
	printf("%d\n", BF("ababcabcdabcde", "abcde"));// 9
	printf("%d\n", BF("ababcabcdabcde", "ab"));// 0
	printf("%d\n", BF("ababcabcdabcde", "abcdf"));// -1
	
	return 0;
}