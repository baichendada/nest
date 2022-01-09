# define _CRT_SECURE_NO_WARNINGS

#include "Sort.h"

void test1()
{
	int a[10] = { 0 };

	for (int i = 0; i < 10; i++)
	{
		a[i] = rand();
	}

	ArrayPrint(a, 10);

	InsertSort(a, 10);

	ArrayPrint(a, 10);
}

void test2()
{
	int a[100] = { 0 };

	for (int i = 0; i < 100; i++)
	{
		a[i] = rand();
	}

	ArrayPrint(a, 100);

	ShellSort(a, 100);

	ArrayPrint(a, 100);
}

void test3()
{
	int a[100] = { 0 };

	for (int i = 0; i < 100; i++)
	{
		a[i] = rand();
	}

	ArrayPrint(a, 100);

	SelectSort(a, 100);

	ArrayPrint(a, 100);
}


void test4()
{
	int a[10] = { 0 };

	for (int i = 0; i < 10; i++)
	{
		a[i] = 10 - i;
	}

	ArrayPrint(a, 10);

	HeapSort(a, 10);

	ArrayPrint(a, 10);
}

void test5()
{
	int a[100] = { 0 };

	for (int i = 0; i < 100; i++)
	{
		a[i] = rand();
	}

	ArrayPrint(a, 100);

	BubbleSort(a, 100);

	ArrayPrint(a, 100);
}

void test6()
{
	int a[100] = { 10,9,8,7,6,5,4,3,2,1 };

	for (int i = 0; i < 100; i++)
	{
		a[i] = rand();
	}

	ArrayPrint(a, 100);

	QuickSort(a, 0, 99);

	ArrayPrint(a, 100);
}

void test7()
{
	int a[100] = { 10,9,8,7,6,5,4,3,2,1 };

	for (int i = 0; i < 100; i++)
	{
		a[i] = rand();
	}

	ArrayPrint(a, 100);

	QuickSortNonR(a, 0, 99);

	ArrayPrint(a, 100);
}

void test8()
{
	int a[100] = { 10,9,8,7,6,5,4,3,2,1 };

	for (int i = 0; i < 100; i++)
	{
		a[i] = rand();
	}

	ArrayPrint(a, 100);

	MergeSort(a, 100);

	ArrayPrint(a, 100);
}

void TestOP()
{
	const int N = 10000000;
	int* a1 = (int*)malloc(sizeof(int) * N);
	int* a2 = (int*)malloc(sizeof(int) * N);
	int* a3 = (int*)malloc(sizeof(int) * N);
	int* a4 = (int*)malloc(sizeof(int) * N);
	int* a5 = (int*)malloc(sizeof(int) * N);
	int* a6 = (int*)malloc(sizeof(int) * N);
	int* a7 = (int*)malloc(sizeof(int) * N);

	for (int i = 0; i < N; ++i)
	{
		a1[i] = rand();
		a2[i] = a1[i];
		a3[i] = a1[i];
		a4[i] = a1[i];
		a5[i] = a1[i];
		a6[i] = a1[i];
	}

	int begin1 = clock();
	//InsertSort(a1, N);
	int end1 = clock();

	int begin2 = clock();
	ShellSort(a2, N);
	int end2 = clock();

	int begin3 = clock();
	//SelectSort(a3, N);
	int end3 = clock();

	int begin4 = clock();
	//HeapSort(a4, N);
	int end4 = clock();

	int begin5 = clock();
	QuickSortNonR(a5, 0, N - 1);
	int end5 = clock();

	int begin6 = clock();
	MergeSort(a6, N);
	int end6 = clock();

	printf("InsertSort:%d\n", end1 - begin1);
	printf("ShellSort:%d\n", end2 - begin2);
	printf("SelectSort:%d\n", end3 - begin3);
	printf("HeapSort:%d\n", end4 - begin4);
	printf("QuickSort:%d\n", end5 - begin5);
	printf("MergeSort:%d\n", end6 - begin6);

	free(a1);
	free(a2);
	free(a3);
	free(a4);
	free(a5);
	free(a6);
}



int main()
{
	srand(time(NULL));
	//test1();
	//test2();
	//test3();
	//test4();
	TestOP();

	//test5();
	//test6();
	//test7();
	//test8();

	return 0;
}