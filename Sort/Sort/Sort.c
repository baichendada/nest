# define _CRT_SECURE_NO_WARNINGS
#include "Sort.h"

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

void QuickSort(int* a, int left, int right)
{
	if (left >= right)
		return;

	int key = PartSort2(a, left, right);
	QuickSort(a, left, key - 1);
	QuickSort(a, key + 1, right);
}