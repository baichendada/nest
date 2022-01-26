# define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

ListNode* reverseBetween(ListNode* head, int m, int n) 
{
    // ��תָ�뷨
    // ����ָ���¼λ��
    ListNode* cur = head, * next = head->next, * prev = NULL;
    // ��¼��ת�����Ϳ�ʼ��λ���Լ���ʼ��ת��ǰ�����
    ListNode* begin, * end, * prevB = NULL;
    int cnt = 1;
    // ��nextΪ�գ������ֻ��һ����㣬ֱ�ӷ��ؼ���
    if (next == NULL)
    {
        return head;
    }

    while (cnt <= n)
    {
        next = cur->next;
        // ��¼��ʼ��ת��ǰ�����
        if (cnt == m - 1)
        {
            prevB = cur;
        }
        // ��¼��ת��ʼ�Ľ��
        if (cnt == m)
        {
            end = cur;
        }
        // ��¼��ת�����Ľ��
        if (cnt == n)
        {
            begin = cur;
        }
        // ��ʼ��ת
        if (cnt >= m)
        {
            cur->next = prev;
        }
        prev = cur;
        cur = next;
        cnt++;
    }
    // ��ʼ��ת��λ�õĽ����Ƿ�ת��m~n�����һ����㣬���������ָ��ָ���n+1�����
    end->next = next;
    // ���m!=1������ǰ����㣬ǰ�����ָ��ת��ʼ�Ľ��
    if (prevB)
        prevB->next = begin;
    // ���m == 1,ͷ����ı䣬�������Ƿ��ظı���ͷ���
    if (m == 1)
    {
        return begin;
    }
    return head;
}
};


ListNode* reverseBetween(ListNode* head, int m, int n) {
    if (head == NULL || head->next == NULL || m == n)
        return head;
    ListNode* tmp = (ListNode*)malloc(sizeof(ListNode));
    tmp->next = head;

    // �ҵ���Ҫ��ת�Ľ���ǰ�����
    ListNode* prevBegin = tmp;
    for (int i = 1; i < m; i++)
    {
        prevBegin = prevBegin->next;
    }

    // ��ʼͷ�巴ת
    ListNode* cur = prevBegin->next;
    for (int i = m; i < n; i++)
    {
        ListNode* next = cur->next;
        cur->next = next->next;
        next->next = prevBegin->next;
        cur = cur->next;
    }
    ListNode* newHead = tmp->next;
    free(tmp);
    return newHead;
}

ListNode* reverseBetween(ListNode* head, int m, int n) {
    if (head == NULL || head->next == NULL || m == n)
        return head;
    //������ʱͷ��㣬����ͳһ���е�������д��������Ƿ�ת������ӵ�һ���ڵ㿪ʼ
    struct ListNode* new_head = (struct ListNode*)malloc(sizeof(struct ListNode));
    new_head->next = head;
    //preָ��ת�������ǰ���ڵ�
    struct ListNode* pre = new_head;
    for (int i = 1; i < m; ++i)
        pre = pre->next;
    //headָ��ת��������ײ�
    head = pre->next;
    for (int i = m; i < n; ++i)
    {
        //��p�ڵ�ժ�½����������ͷ������
        struct ListNode* p = head->next;
        head->next = p->next;
        p->next = pre->next;
        pre->next = p;
    }
    head = new_head->next;
    free(new_head);
    return head;
}

struct ListNode* removeZeroSumSublists(struct ListNode* head)
{
    struct ListNode* pre = (struct ListNode*)malloc(sizeof(struct ListNode));
    pre->next = head;
    struct ListNode* p = pre;
    while (p)
    {
        int sum = 0;
        struct ListNode* q = p->next;
        while (q)
        {
            sum += q->val;
            if (sum == 0)
            {
                p->next = q->next;
                //�ͷű�ɾ���Ľڵ�
                struct ListNode* del = p->next;
                while (del != q->next)
                {
                    struct ListNode* tmp = del;
                    del = del->next;
                    free(tmp);
                }
            } q
                = q->next;
        } p
            = p->next;
    } h
        ead = pre->next;
    free(pre);
    return head;
}