# define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int search(int* nums, int numsSize, int target) {
    for (int i = 0; i < numsSize; i++)
    {
        if (target == nums[i])
        {
            return i;;
        }
    }
    return -1;
}

int getDecimalValue(struct ListNode* head) 
{
    int sum = 0;
    while (head)
    {
        sum = (sum << 1) + head->val;
        head = head->next;
    }
    return sum;
}


int search(int* nums, int numsSize, int target) {
    int left = 0;
    int right = numsSize - 1;

    while (left <= right)
    {
        int mid = ((left - right) >> 1) + right;

        // 依旧采用二分查找的思想
        if (nums[mid] == target)
        {
            return mid;
        }
        // 当 最左边的数 小于等于 中间的数时，代表 数组的左半部分 是有序的
        // 这里是 小于等于 的原因是有特殊情况，eg.[3,1] target = 1
        else if (nums[left] <= nums[mid])
        {
            // 当左半部分有序，并且目标在[left,mid)之间时
            if (nums[left] <= target && target < nums[mid])
            {
                // 右界限缩
                right = mid - 1;
            }
            // 当左半部分有序，并且目标不在[left,mid)之间时
            else
            {
                // 左界限缩
                left = mid + 1;
            }
        }
        // 当 最右边的数 大于 中间的数时，代表 数组的左半部分 是有序的
        else
        {
            // 同理当右半部分有序，并且目标在(mid,right]之间时
            if (nums[right] >= target && target > nums[mid])
            {
                left = mid + 1;
            }
            // 当右半部分有序，并且目标不在(mid,right]之间时
            else
            {
                right = mid - 1;
            }
        }
    }
    // 当left > right则为找不到
    return -1;
}