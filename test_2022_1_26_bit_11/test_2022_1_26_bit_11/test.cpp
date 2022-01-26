# define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

ListNode* reverseBetween(ListNode* head, int m, int n) 
{
    // 反转指针法
    // 三个指针记录位置
    ListNode* cur = head, * next = head->next, * prev = NULL;
    // 记录反转结束和开始的位置以及开始反转的前驱结点
    ListNode* begin, * end, * prevB = NULL;
    int cnt = 1;
    // 当next为空，则此中只有一个结点，直接返回即可
    if (next == NULL)
    {
        return head;
    }

    while (cnt <= n)
    {
        next = cur->next;
        // 记录开始反转的前驱结点
        if (cnt == m - 1)
        {
            prevB = cur;
        }
        // 记录反转开始的结点
        if (cnt == m)
        {
            end = cur;
        }
        // 记录反转结束的结点
        if (cnt == n)
        {
            begin = cur;
        }
        // 开始反转
        if (cnt >= m)
        {
            cur->next = prev;
        }
        prev = cur;
        cur = next;
        cnt++;
    }
    // 开始反转的位置的结点就是反转后m~n中最后一个结点，则这个结点的指针指向第n+1个结点
    end->next = next;
    // 如果m!=1，则有前驱结点，前驱结点指向反转后开始的结点
    if (prevB)
        prevB->next = begin;
    // 如果m == 1,头结点会改变，所以我们返回改变后的头结点
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

    // 找到所要反转的结点的前驱结点
    ListNode* prevBegin = tmp;
    for (int i = 1; i < m; i++)
    {
        prevBegin = prevBegin->next;
    }

    // 开始头插反转
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
    //借助临时头结点，可以统一所有的情况进行处理，尤其是翻转的链表从第一个节点开始
    struct ListNode* new_head = (struct ListNode*)malloc(sizeof(struct ListNode));
    new_head->next = head;
    //pre指向翻转子链表的前驱节点
    struct ListNode* pre = new_head;
    for (int i = 1; i < m; ++i)
        pre = pre->next;
    //head指向翻转子链表的首部
    head = pre->next;
    for (int i = m; i < n; ++i)
    {
        //将p节点摘下进行子链表的头部插入
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
                //释放被删除的节点
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