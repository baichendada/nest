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
//	// next[i]��sub[i]ƥ�䲻���Ժ�������λ��
//	// sub[0 , next[i] - 1] �� [i - k,i - 1]����ȵ�
//	// ����sub[i]��sub[next[i]]��һ����ȣ�ֻ������ǰ����һ�����
//	next[0] = -1;
//	next[1] = 0;
//	int i = 2;// ��2��ʼ����
//	int k = 0;// ��һ������nextֵ����ǰҲ����next[1]��Ҳ����0
//
//	while (i < lenSub)
//	{
//		// ��sub[i-1]��sub[k]��ͬʱ��˵�����ÿ��Ժ�ǰ����ͬ������
//		// ��֪next[i-1] = k����next[i] = k + 1
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
	// next[i]��sub[i]ƥ�䲻���Ժ�������λ��
	// sub[0 , next[i] - 1] �� [i - k,i - 1]����ȵ�
	// ����sub[i]��sub[next[i]]��һ����ȣ�ֻ������ǰ����һ�����
	next[0] = -1;
	next[1] = 0;
	if (sub[0] == sub[1])
	{
		next[1] = -1;
	}
	int i = 2;// ��2��ʼ����
	int k = 0;// ��һ������nextֵ����ǰҲ����next[1]��Ҳ����0

	while (i < lenSub)
	{
		// ��sub[i-1]��sub[k]��ͬʱ��˵�����ÿ��Ժ�ǰ����ͬ������
		// ��֪next[i-1] = k����next[i] = k + 1
		if (k == -1 || sub[i - 1] == sub[k])
		{
			next[i] = k + 1;
			// ������˵��ַ��͵�ǰ���ַ���ȣ�˵��һ������ַ��������������ַ������˵��ַ�Ҳ�������������ַ�
			// ��Ҫ���ˣ������Ǻ��˷�ʱ��ģ���������ֱ��������ַ����˵������ַ��Ļ���λ��
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

	int i = pos;// ��¼���������±�
	int j = 0;// ��¼ģʽ�����±�
	// ��ȡnext����
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

