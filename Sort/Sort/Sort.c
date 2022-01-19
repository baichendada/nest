# define _CRT_SECURE_NO_WARNINGS
#include "Sort.h"
#include "Stack.h"

void ArrayPrint(int* a, int n)
{
	assert(a);
	
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

void InsertSort(int* a, int n)
{
	assert(a);

	for (int i = 0; i < n - 1; i++)
	{
		int end = i;
		int x = a[end + 1];

		while (end >= 0)
		{
			if (a[end] > x)
			{
				// ���Ҫ��������ô��a[end]��x����ʱ���͵ð�a[end]����ƶ�
				a[end + 1] = a[end];
				end--;
			}
			else
			{
				// ���������Ǵ�������ǰ�濪ʼ�������ԣ�xǰ��һ�������򣬱Ƚϵ�ǰ���Ǹ���С�ڵ���x����˵��ǰ��Ķ�С�ڵ���x
				// ����ֱ��break��ȥ�Ϳ���
				break;
			}
		}
		// ����a[end]С�ڵ���x������a[end+1]����xӦ���ڵ�λ��
		a[end + 1] = x;
	}
}



void ShellSort(int* a, int n)
{
	assert(a);

	int gap = n;

	// ���Ԥ�ż�һ�β�������(gap=1)
	while (gap > 1)
	{
		// ��ֹgap������1
		gap = gap / 3 + 1;

		for (int i = 0; i < n - gap; i++)
		{
			int end = i;
			int x = a[end + gap];
			while (end >= 0)
			{
				if(a[end] > x)
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			a[end + gap] = x;
		}

	}
}

void Swap(int* p, int* q)
{
	int tmp = *p;
	*p = *q;
	*q = tmp;
}

void SelectSort(int* a, int n)
{
	assert(a);

	int begin = 0;
	int end = n - 1;

	while (begin < end)
	{
		int maxi = begin;
		int mini = begin;
		for (int i = begin; i <= end; i++)
		{
			// ��¼������С���ݵ��±�
			if (a[i] > a[maxi])
			{
				maxi = i;
			}
			if (a[i] < a[mini])
			{
				mini = i;
			}
		}
		Swap(&a[mini], &a[begin]);
		// ����mini��begin����������������Сֵ��begin��miniλ�÷ŵ���ԭ��begin��ֵ
		// ������һ���ֵ��beginλ���أ����Ա����жϣ�����ڣ��Ͱ�ԭbeginλ���Ϸŵ�ֵ��Ҳ��������miniλ�÷ŵ�ֵ������end����
		if (maxi == begin)
		{
			maxi = mini;
		}
		Swap(&a[maxi], &a[end]);
		begin++;
		end--;
	}
}

// �����򣬽����
void AdjustDwon(int* a, int n, int root)
{
	assert(a);

	int child = 2 * root + 1;

	while (child < n)
	{
		if (child + 1 < n && a[child + 1] > a[child])
		{
			child++;
		}

		if(a[child]>a[root])
		{
			Swap(&a[child], &a[root]);

			root = child;
			child = 2 * root + 1;
		}
		else
		{
			break;
		}
		
	}
}

void HeapSort(int* a, int n)
{
	assert(a);

	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDwon(a, n, i);
	}

	int end = n - 1;

	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDwon(a, end, 0);
		end--;
	}
}


// ð������
void BubbleSort(int* a, int n)
{
	assert(a);

	for (int i = 0; i < n - 1; i++)
	{
		int flag = 1;

		for (int j = 0; j < n - 1 - i; j++)
		{
			if (a[j] > a[j + 1])
			{
				flag = 0;
				Swap(&a[j], &a[j + 1]);
			}
		}
		if (flag)
		{
			break;
		}
	}
}

// ��������ݹ�ʵ��
// ��������hoare�汾
int SelectMid(int* a, int left, int right)
{
	int mid = left + ((right - left) >> 1);

	if (a[left] < a[mid])
	{
		if (a[mid] < a[right])
		{
			return mid;
		}
		else if (a[left] < a[right])
		{
			return right;
		}
		else
		{
			return left;
		}
	}
	else
	{
		if (a[mid] > a[right])
		{
			return mid;
		}
		else if (a[left] < a[right])
		{
			return left;
		}
		else
		{
			return right;
		}
	}
}

int PartSort1(int* a, int left, int right)
{
	assert(a);
	// ����ȡ�У�Ȼ�󽻻�����������������֤key��Զ�������
	int mid = SelectMid(a, left, right);
	Swap(&a[left], &a[mid]);
	int keyi = left;

	while (left < right)
	{
		// �ұ����ߣ���С;��֤����ʱleft<right���������±���ָ��С��keyʱ��ֹͣ
		//����С�ڵ�������Ϊ��������� 1 1 1 1 1 1����������ʱ������ѭ��
		while (left < right && a[keyi] <= a[right])
		{
			--right;
		}

		// ������ߣ��Ҵ�
		while (left < right && a[keyi] >= a[left])
		{
			++left;
		}

		//������������󣬽���
		Swap(&a[left], &a[right]);
	}
	// �����󣬽�����λ�õ�����key������
	Swap(&a[left], &a[keyi]);

	return left;
}
// ���������ڿӷ�
int PartSort2(int* a, int left, int right)
{
	assert(a);
	// ����ȡ��
	int mid = SelectMid(a, left, right);
	Swap(&a[left], &a[mid]);
	 // ����keyֵ
	int pit = a[left];

	while (left < right)
	{
		// �ұ����ߣ���С
		while (left < right && pit <= a[right])
		{
			--right;
		}
		// �ҵ�ֱ�ӷŵ������ʱ���������
		a[left] = a[right];

		// ������ߣ��Ҵ�
		while (left < right && pit >= a[left])
		{
			++left;
		}
		// ��ʱ���ұ�����
		a[right] = a[left];
	}
	// �����󣬰�key�ŵ�����
	a[left] = pit;
	return left;
}

int PartSort3(int* a, int left, int right)
{
	assert(a);
	// ����ȡ��
	int mid = SelectMid(a, left, right);
	Swap(&a[left], &a[mid]);

	// prev������ʼ��cur��ʼ�ӱ�prev+1��λ�ÿ�ʼ
	int keyi = left;
	int prev = left;
	int cur = prev + 1;

	while (cur <= right)
	{
		// ��С�����++prev��ֵ��cur��ͬ��Ϊ�˷�ֹ��Ч����Swap�����Բ�����if��
		if (a[cur] < a[keyi] && ++prev != cur)
		{
			Swap(&a[cur], &a[prev]);
		}
		++cur;
	}
	Swap(&a[keyi], &a[prev]);
	
	return prev;
}

void QuickSort(int* a, int left, int right)
{
	if (left >= right)
		return;

	// С�����Ż�,����С��ʮ��ʱ�����ٵݹ飬ֱ�Ӳ�������
	if (right - left + 1 < 10)
	{
		InsertSort(a + left, right - left + 1);
	}
	else
	{
		int key = PartSort3(a, left, right);
		QuickSort(a, left, key - 1);
		QuickSort(a, key + 1, right);
	}
}


// ��ֹ�ݹ���ȹ���
void QuickSortNonR(int* a, int left, int right)
{
	ST Stack;
	StackInit(&Stack);
	// ����ջ�ṹ���Ƚ����������ʵ��ģ��ջ������Ҫ��ջleft��right
	StackPush(&Stack, left);
	StackPush(&Stack, right);

	// ��ջΪ��ʱ��֤������Ԫ���Ѿ���ɳ�ջ���ݹ��������ѭ������
	while (!StackEmpty(&Stack))
	{
		// ��ջԪ��
		int end = StackTop(&Stack);
		StackPop(&Stack);

		int begin = StackTop(&Stack);
		StackPop(&Stack);

		// С�����Ż�

		if (right - left + 1 < 10)
		{
			InsertSort(a + left, right - left + 1);
		}
		else
		{
			int key = PartSort3(a, begin, end);

			// ��ջԪ�أ�Ϊ��һ�εݹ���׼������ΪҪģ��ջ�ĵ���˳�����Զ���ջ��˳����Ҫ��
			// �������Ҫ��������Ԫ�ص����򣬾͵�����ջ��Ԫ���������

			// ���ұߴ���һ��Ԫ��ʱ����ջ
			if (key + 1 < end)
			{
				StackPush(&Stack, key + 1);
				StackPush(&Stack, end);
			}

			//ͬ�������Ԫ�ش���һ��ʱ����ջ
			if (key - 1 > begin)
			{
				StackPush(&Stack, begin);
				StackPush(&Stack, key - 1);
			}
		}
	}
	StackDestroy(&Stack);
}

void _MergeSort(int* a, int left, int right, int* tmp)
{
	// ���ֵ�ֻʣһ��Ԫ��ʱ�����أ���ʼ����
	if (left >= right)
		return;
	
	// ���м�
	int mid = left + ((right - left) >> 1);

	// ������ҵĹ鲢����
	_MergeSort(a, left, mid, tmp);
	_MergeSort(a, mid + 1, right, tmp);

	// ������ҵ��������ھͿ��Խ����ҿ����������飬��ʼ����
	int begin1 = left, end1 = mid;
	int begin2 = mid + 1, end2 = right;
	// �����i�ǿ�ʼ��λ��Ҫ�뱻���е������left��ͬ����֤��������ͬλ��
	int i = left;

	// ��ʼ���򣬽��������ȷŵ����ٵĿռ���
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
		{
			tmp[i] = a[begin1++];
		}
		else
		{
			tmp[i] = a[begin2++];
		}
		++i;
	}
	// ��δ���������ֱ�ӷŵ�tmp��
	while (begin1 <= end1)
	{
		tmp[i++] = a[begin1++];
	}

	while (begin2 <= end2)
	{
		tmp[i++] = a[begin2++];
	}

	// ��tmp��������copy��ԭ����
	for (int j = left; j <= right; j++)
	{
		a[j] = tmp[j];
	}
}

void MergeSort(int* a, int n)
{
	assert(a);
	assert(n > 0);

	int* tmp = (int*)malloc(sizeof(int) * n);
	if (tmp == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}

	_MergeSort(a, 0, n - 1, tmp);
}

// 1.������
//void MergeSortNonR(int* a, int n)
//{
//	assert(a);
//	assert(n > 0);
//	// ����һ��ռ䣬����ź��������
//	int* tmp = (int*)malloc(sizeof(int) * n);
//	if (tmp == NULL)
//	{
//		printf("malloc fail\n");
//		exit(-1);
//	}
//
//	int gap = 1;
//
//	while(gap < n)
//	{
//		for (int i = 0; i < n; i += 2 * gap)
//		{
//			int begin1 = i, end1 = i + gap - 1;
//			int begin2 = i + gap, end2 = i + 2 * gap - 1;
//			int j = i;
//
//			// ��end1�ʹ��ڵ���nʱ
//			if (end1 >= n)
//			{
//				end1 = n - 1;
//			}
//
//			// ��begin2���ڵ���nʱ���ڶ�����Բ������ˣ�ֱ����begin2>end2
//			if (begin2 >= n)
//			{
//				begin2 = n;
//				end2 = n - 1;
//			}
//
//			// end2���ڵ���0��˵���ڶ�����ܻ�����Ҫ��
//			if (end2 >= n)
//			{
//				end2 = n - 1;
//			}
//
//			while (begin1 <= end1 && begin2 <= end2)
//			{
//				if (a[begin1] < a[begin2])
//				{
//					tmp[j++] = a[begin1++];
//				}
//				else
//				{
//					tmp[j++] = a[begin2++];
//				}
//			}
//
//			while (begin1 <= end1)
//			{
//				tmp[j++] = a[begin1++];
//			}
//
//			while (begin2 <= end2)
//			{
//				tmp[j++] = a[begin2++];
//			}
//
//		}
//
//		// �൱�ڰѲ����������һ��������ٿ�����ȥ
//		for (int i = 0; i < n; i++)
//		{
//			a[i] = tmp[i];
//		}
//
//		gap *= 2;
//	}
//	
//	free(tmp);
//	tmp = NULL;
//}

// 2.ģ��ݹ��
void MergeSortNonR(int* a, int n)
{
	assert(a);
	assert(n > 0);
	// ����һ��ռ䣬����ź��������
	int* tmp = (int*)malloc(sizeof(int) * n);
	if (tmp == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}

	int gap = 1;

	while (gap < n)
	{
		for (int i = 0; i < n; i += 2 * gap)
		{
			int begin1 = i, end1 = i + gap - 1;
			int begin2 = i + gap, end2 = i + 2 * gap - 1;
			int j = i;

			// ��end1���ڵ���n����begin2���ڵ���nʱ��������β���������
			if (end1 >= n || begin2 >= n)
			{
				break;
			}

			// ֻ��end2Խ��ʱ��Ҫ��������
			if (end2 >= n)
			{
				end2 = n - 1;
			}

			while (begin1 <= end1 && begin2 <= end2)
			{
				if (a[begin1] < a[begin2])
				{
					tmp[j++] = a[begin1++];
				}
				else
				{
					tmp[j++] = a[begin2++];
				}
			}

			while (begin1 <= end1)
			{
				tmp[j++] = a[begin1++];
			}

			while (begin2 <= end2)
			{
				tmp[j++] = a[begin2++];
			}

			// ������ֱ�ӿ���,���Ҫ���Ƹ��Ƶı߽�
			for (int k = i; k <= end2; k++)
			{
				a[k] = tmp[k];
			}
		}
		

		gap *= 2;
	}

	free(tmp);
	tmp = NULL;
}



void CountSort(int* a, int n)
{
	assert(a);
	assert(n > 0);

	int max = a[0];
	int min = a[0];

	// ѡ�����ֵ����Сֵ
	for (int i = 1; i < n; i++)
	{
		if (a[i] > max)
		{
			max = a[i];
		}

		if (a[i] < min)
		{
			min = a[i];
		}
	}

	int range = max - min + 1;

	int* count = (int*)calloc(range , sizeof(int));
	if (count == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}
	
	
	//  ����ͳ�������и������ֳ��ֵĴ���
	for (int i = 0; i < n; i++)
	{
		count[a[i] - min]++;
	}

	int j = 0;

	// �����ֵ����֣��Ż�����
	for (int i = 0; i < range; i++)
	{
		while (count[i]--)
		{
			a[j++] = i + min;
		}
	}

}

void _MergeFile(const char* file1, const char* file2, const char* fileSum)
{
	FILE* file_1 = fopen(file1, "r");
	if (file_1 == NULL)
	{
		perror("file_1");
		exit(-1);
	}

	FILE* file_2 = fopen(file2, "r");
	if (file_2 == NULL)
	{
		perror("file_2");
		exit(-1);
	}

	FILE* file_sum = fopen(fileSum, "w");
	if (file_sum == NULL)
	{
		perror("file_sum");
		exit(-1);
	}
	int num1, num2;
	int ret1 = fscanf(file_1, "%d\n", &num1);
	int ret2 = fscanf(file_2, "%d\n", &num2);

	while (ret1 != EOF && ret2 != EOF)
	{
		if (num1 < num2)
		{
			fprintf(file_sum, "%d\n", num1);
			ret1 = fscanf(file_1, "%d\n", &num1);
		}
		else
		{
			fprintf(file_sum, "%d\n", num2);
			ret2 = fscanf(file_2, "%d\n", &num2);
		}
	}

	while (ret1 != EOF)
	{
		fprintf(file_sum, "%d\n", num1);
		ret1 = fscanf(file_1, "%d\n", &num1);
	}

	while (ret2 != EOF)
	{
		fprintf(file_sum, "%d\n", num2);
		ret2 = fscanf(file_2, "%d\n", &num2);
	}

	fclose(file_1);
	fclose(file_2);
	fclose(file_sum);
}

// �ⲿ���򣬴��ݵĲ������ļ�·�����ļ���
void MergeFile(const char* file)
{
	FILE* fout = fopen(file, "r");
	if (fout == NULL)
	{
		perror("fout");
		exit(-1);
	}

	int n = 100000;// �������ڴ��м���ʮ����һ����ʮ��
	int* a = (int*)malloc(sizeof(int) * n);
	int i = 0;// �±�
	int num = 0;// ��Ŷ�ȡ������
	int filei = 1;// �������ļ�������
	char fileName[100] = { 0 };// �������ļ�����

	// ���ļ��п�ʼ�����ݣ�ע���ȡ�ĸ�ʽ
	while (~fscanf(fout, "%d\n", &num))
	{
		if (i < n - 1)
		{
			a[i++] = num;
		}
		else
		{
			// �������һ������
			a[i] = num;
			QuickSort(a, 0, n - 1);
			// �����ݶ�ȡ���ļ��У���������Ĭ�ϱ��浽��Ŀ¼��
			sprintf(fileName, "little%d", filei++);
			FILE* fin = fopen(fileName, "w");
			if (fin == NULL)
			{
				perror("fin");
				exit(-1);
			}

			for (int j = 0; j < n; j++)
			{
				fprintf(fin, "%d\n", a[j]);
			}

			fclose(fin);
			i = 0;
		}
	}

	// ������Щ���ʣ�������
	int flag = 0;
	if (i != 0)
	{
		flag = 1;
		QuickSort(a, 0, i - 1);

		sprintf(fileName, "little%d", filei);

		FILE* fin = fopen(fileName, "w");
		if (fin == NULL)
		{
			perror("fin");
			exit(-1);
		}

		for (int j = 0; j < i; j++)
		{
			fprintf(fin, "%d\n", a[j]);
		}

		fclose(fin);
	}

	int j = 1;

	char fileCall_1[100] = "little1";
	char fileCall_2[100] = "little2";
	char fileFinal[100] = "little1_little2";

	// �����ʣ�����ݣ���ѭ��filei+1������ֻ��ѭ��file��
	if (flag == 0)
	{
		for (j = 3; j <= filei; j++)
		{
			_MergeFile(fileCall_1, fileCall_2, fileFinal);
			strcpy(fileCall_1, fileFinal);
			sprintf(fileFinal, "%s_little%d", fileFinal, j);
			sprintf(fileCall_2, "little%d", j);
		}
	}
	else
	{
		for (j = 3; j <= filei + 1; j++)
		{
			_MergeFile(fileCall_1, fileCall_2, fileFinal);
			strcpy(fileCall_1, fileFinal);
			sprintf(fileFinal, "%s_little%d", fileFinal, j);
			sprintf(fileCall_2, "little%d", j);
		}
	}
	

	fclose(fout);
	free(a);
}