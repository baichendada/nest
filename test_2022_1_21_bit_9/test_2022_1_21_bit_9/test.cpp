# define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

int main()
{
	int b = 0;
	const int& a = b;

	cout << a << " " << endl;
	cout << b << endl;


	return 0;
}

int* runningSum(int* nums, int numsSize, int* returnSize) {
    int* sum = (int*)malloc(sizeof(int) * numsSize);
    *returnSize = numsSize;

    // auto只能用于数组下面，不能用于指针
    for (int i = 0; i < numsSize; i++)
    {
        if (i == 0)
        {
            sum[i] = nums[i];
            continue;
        }

        sum[i] = sum[i - 1] + nums[i];
    }

    return sum;
}

int searchInsert(int* nums, int numsSize, int target) {
    int left = 0, right = numsSize - 1;

    while (left <= right)
    {
        int avr = (left + right) / 2;

        if (nums[avr] == target)
        {
            return avr;
        }

        if (nums[avr] > target)
        {
            right = avr - 1;
        }
        else
        {
            left = avr + 1;
        }
    }

    return left;

}