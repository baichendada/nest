# define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <assert.h>
#include <string.h>

// str��������Ҳ����Ҫ�����ҵ��ַ���
// tar���Ӵ���Ҳ����Ŀ���ַ���
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
		// �����ַ���ȣ�һ������ߣ��Ƚ���һ���ַ�
		if (str[i] == tar[j])
		{
			++i;
			++j;
		}
		// ����ȣ�i ������һ�ο�ʼ�ĺ�һ��λ�ã�i - j + 1�� j �൱������ߵĲ�������Ϊjÿ�δ�0��ʼ
		// i - j��Ϊ�ص�str��һ�ε���ʼλ�ã�+1���������һ��λ�ã�Ҳ���ص���һ�ο�ʼ�ĺ�һ��λ��
		// ����ȣ�j�ص�0λ�ü���ƥ��
		else
		{
			i = i - j + 1;
			j = 0;
		}
	}
	// ���Ӵ�����ʱ��˵���ҵ��ˣ�����str��һ�ε���ʼλ��
	if (j == lenTar)
		return i - j;
	// �Ӵ�û���꣬���������ˣ���˵��û�ҵ�������-1
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