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
				// 如果要排升序，那么当a[end]比x还大时，就得把a[end]向后移动
				a[end + 1] = a[end];
				end--;
			}
			else
			{
				// 由于我们是从数组最前面开始排序，所以，x前面一定是升序，比较到前面那个数小于等于x，就说明前面的都小于等于x
				// 所以直接break出去就可以
				break;
			}
		}
		// 由于a[end]小于等于x，所以a[end+1]就是x应该在的位置
		a[end + 1] = x;
	}
}



void ShellSort(int* a, int n)
{
	assert(a);

	int gap = n;

	// 多次预排加一次插入排序(gap=1)
	while (gap > 1)
	{
		// 防止gap到不了1
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
			// 记录最大和最小数据的下标
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
		// 由于mini与begin交换，所以现在最小值在begin，mini位置放的是原来begin的值
		// 但是万一最大值在begin位置呢？所以必须判断，如果在，就把原begin位置上放的值（也就是现在mini位置放的值），与end交换
		if (maxi == begin)
		{
			maxi = mini;
		}
		Swap(&a[maxi], &a[end]);
		begin++;
		end--;
	}
}

// 排升序，建大堆
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


// 冒泡排序
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

// 快速排序递归实现
// 快速排序hoare版本
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
	// 三数取中，然后交换中数和最左数，保证key永远在最左边
	int mid = SelectMid(a, left, right);
	Swap(&a[left], &a[mid]);
	int keyi = left;

	while (left < right)
	{
		// 右边先走，找小;保证找数时left<right，并且右下标所指数小于key时才停止
		//不是小于等于是因为如果碰到如 1 1 1 1 1 1等类似数组时，会死循环
		while (left < right && a[keyi] <= a[right])
		{
			--right;
		}

		// 左边再走，找大
		while (left < right && a[keyi] >= a[left])
		{
			++left;
		}

		//找完或者相遇后，交换
		Swap(&a[left], &a[right]);
	}
	// 相遇后，将相遇位置的树与key数交换
	Swap(&a[left], &a[keyi]);

	return left;
}
// 快速排序挖坑法
int PartSort2(int* a, int left, int right)
{
	assert(a);
	// 三数取中
	int mid = SelectMid(a, left, right);
	Swap(&a[left], &a[mid]);
	 // 保存key值
	int pit = a[left];

	while (left < right)
	{
		// 右边先走，找小
		while (left < right && pit <= a[right])
		{
			--right;
		}
		// 找到直接放到坑里，此时，左边作坑
		a[left] = a[right];

		// 左边再走，找大
		while (left < right && pit >= a[left])
		{
			++left;
		}
		// 此时，右边作坑
		a[right] = a[left];
	}
	// 相遇后，把key放到坑里
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