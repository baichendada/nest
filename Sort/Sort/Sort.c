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

int PartSort3(int* a, int left, int right)
{
	assert(a);
	// 三数取中
	int mid = SelectMid(a, left, right);
	Swap(&a[left], &a[mid]);

	// prev从最左开始，cur开始从比prev+1的位置开始
	int keyi = left;
	int prev = left;
	int cur = prev + 1;

	while (cur <= right)
	{
		// 找小，如果++prev后值与cur相同，为了防止无效调用Swap，所以不进入if内
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

	// 小区间优化,数据小于十个时，不再递归，直接插入排序
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


// 防止递归深度过深
void QuickSortNonR(int* a, int left, int right)
{
	ST Stack;
	StackInit(&Stack);
	// 利用栈结构的先进后出的特性实现模拟栈，我们要入栈left和right
	StackPush(&Stack, left);
	StackPush(&Stack, right);

	// 当栈为空时，证明所有元素已经完成出栈（递归结束），循环结束
	while (!StackEmpty(&Stack))
	{
		// 出栈元素
		int end = StackTop(&Stack);
		StackPop(&Stack);

		int begin = StackTop(&Stack);
		StackPop(&Stack);

		// 小区间优化

		if (right - left + 1 < 10)
		{
			InsertSort(a + left, right - left + 1);
		}
		else
		{
			int key = PartSort3(a, begin, end);

			// 入栈元素，为下一次递归做准备，因为要模拟栈的调用顺序，所以对入栈的顺序有要求
			// 我们如果要先完成左边元素的排序，就得先入栈右元素相关数据

			// 当右边大于一个元素时，入栈
			if (key + 1 < end)
			{
				StackPush(&Stack, key + 1);
				StackPush(&Stack, end);
			}

			//同理，当左边元素大于一个时，入栈
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
	// 当分的只剩一个元素时，返回，开始排序。
	if (left >= right)
		return;
	
	// 找中间
	int mid = left + ((right - left) >> 1);

	// 完成左右的归并排序
	_MergeSort(a, left, mid, tmp);
	_MergeSort(a, mid + 1, right, tmp);

	// 完成左右的排序，现在就可以将左右看作两个数组，开始排序
	int begin1 = left, end1 = mid;
	int begin2 = mid + 1, end2 = right;
	// 这里的i是开始的位置要与被排列的数组的left相同，保证拷贝到相同位置
	int i = left;

	// 开始排序，将排序结果先放到开辟的空间中
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
	// 将未放完的数组直接放到tmp中
	while (begin1 <= end1)
	{
		tmp[i++] = a[begin1++];
	}

	while (begin2 <= end2)
	{
		tmp[i++] = a[begin2++];
	}

	// 将tmp的排序结果copy到原数组
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

// 1.修正版
//void MergeSortNonR(int* a, int n)
//{
//	assert(a);
//	assert(n > 0);
//	// 开辟一块空间，存放排好序的数组
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
//			// 当end1就大于等于n时
//			if (end1 >= n)
//			{
//				end1 = n - 1;
//			}
//
//			// 当begin2大于等于n时，第二组可以不用排了，直接让begin2>end2
//			if (begin2 >= n)
//			{
//				begin2 = n;
//				end2 = n - 1;
//			}
//
//			// end2大于等于0，说明第二组可能还有数要排
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
//		// 相当于把层序遍历，把一层遍历完再拷贝回去
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

// 2.模拟递归版
void MergeSortNonR(int* a, int n)
{
	assert(a);
	assert(n > 0);
	// 开辟一块空间，存放排好序的数组
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

			// 当end1大于等于n或者begin2大于等于n时，代表这次不用排序了
			if (end1 >= n || begin2 >= n)
			{
				break;
			}

			// 只有end2越界时，要修正排序
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

			// 排完序直接拷贝,这次要控制复制的边界
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

	// 选出最大值，最小值
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
	
	
	//  这里统计数组中各个数字出现的次数
	for (int i = 0; i < n; i++)
	{
		count[a[i] - min]++;
	}

	int j = 0;

	// 将出现的数字，放回数组
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

// 外部排序，传递的参数是文件路径加文件名
void MergeFile(const char* file)
{
	FILE* fout = fopen(file, "r");
	if (fout == NULL)
	{
		perror("fout");
		exit(-1);
	}

	int n = 100000;// 假设在内存中加载十个，一次排十个
	int* a = (int*)malloc(sizeof(int) * n);
	int i = 0;// 下标
	int num = 0;// 存放读取的数据
	int filei = 1;// 用来给文件起名字
	char fileName[100] = { 0 };// 用来放文件名称

	// 从文件中开始读数据，注意读取的格式
	while (~fscanf(fout, "%d\n", &num))
	{
		if (i < n - 1)
		{
			a[i++] = num;
		}
		else
		{
			// 读到最后一个数据
			a[i] = num;
			QuickSort(a, 0, n - 1);
			// 将数据读取到文件中，这里我们默认保存到本目录下
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

	// 排序那些最后剩余的数据
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

	// 如果有剩余数据，就循环filei+1，否则只需循环file次
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