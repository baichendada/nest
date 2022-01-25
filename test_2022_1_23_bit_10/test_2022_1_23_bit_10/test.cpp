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

        // ���ɲ��ö��ֲ��ҵ�˼��
        if (nums[mid] == target)
        {
            return mid;
        }
        // �� ����ߵ��� С�ڵ��� �м����ʱ������ �������벿�� �������
        // ������ С�ڵ��� ��ԭ���������������eg.[3,1] target = 1
        else if (nums[left] <= nums[mid])
        {
            // ����벿�����򣬲���Ŀ����[left,mid)֮��ʱ
            if (nums[left] <= target && target < nums[mid])
            {
                // �ҽ�����
                right = mid - 1;
            }
            // ����벿�����򣬲���Ŀ�겻��[left,mid)֮��ʱ
            else
            {
                // �������
                left = mid + 1;
            }
        }
        // �� ���ұߵ��� ���� �м����ʱ������ �������벿�� �������
        else
        {
            // ͬ���Ұ벿�����򣬲���Ŀ����(mid,right]֮��ʱ
            if (nums[right] >= target && target > nums[mid])
            {
                left = mid + 1;
            }
            // ���Ұ벿�����򣬲���Ŀ�겻��(mid,right]֮��ʱ
            else
            {
                right = mid - 1;
            }
        }
    }
    // ��left > right��Ϊ�Ҳ���
    return -1;
}