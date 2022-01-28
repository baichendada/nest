# define _CRT_SECURE_NO_WARNINGS


// 递归失败版
// 原因：超大的数会溢出
//long long _addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
//{
//    if (l1 == NULL && l2 == NULL)
//        return 0;
//
//    if (l1 == NULL)
//        return _addTwoNumbers(NULL, l2->next) * 10 + l2->val;
//
//    if (l2 == NULL)
//        return _addTwoNumbers(l1->next, NULL) * 10 + l1->val;
//
//    long long sum = l1->val + l2->val;
//    return sum >= 10 ? (sum % 10) + 10 * (_addTwoNumbers(l1->next, l2->next) + 1)
//        : sum + 10 * _addTwoNumbers(l1->next, l2->next);
//}
//
//struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
//    long long sum = _addTwoNumbers(l1, l2);
//    long long a[12] = { 0 };
//    int i = 0;
//
//    if (sum == 0)
//    {
//        struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
//        head->val = 0;
//        head->next = NULL;
//        return head;
//    }
//
//    while (sum)
//    {
//        a[i++] = sum % 10;
//        sum /= 10;
//    }
//
//    struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
//    struct ListNode* cur = head;
//
//    for (int j = 0; j < i; j++)
//    {
//        struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
//        node->val = a[j];
//        cur->next = node;
//        node->next = NULL;
//        cur = node;
//    }
//
//    return head->next;
//}

#include <stdio.h>
struct ListNode {
    int val;
    struct ListNode* next;
    
};

//struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
//    int a[100] = { 0 };
//    int i = 0;
//    int flag = 0;
//    while (l1 && l2)
//    {
//        int sum = l1->val + l2->val;
//        if (flag == 1)
//        {
//            sum++;
//        }
//
//        if (sum < 10)
//        {
//            a[i++] = sum;
//            flag = 0;
//        }
//        else
//        {
//            a[i++] = sum % 10;
//            flag = 1;
//        }
//        l1 = l1->next;
//        l2 = l2->next;
//    }
//
//    while (l1)
//    {
//        if (flag == 1)
//        {
//            int sum = l1->val + 1;
//            if (sum < 10)
//            {
//                a[i++] = sum;
//                flag = 0;
//            }
//            else
//            {
//                a[i++] = sum % 10;
//                flag = 1;
//            }
//        }
//        else
//            a[i++] = l1->val;
//        l1 = l1->next;
//    }
//
//    while (l2)
//    {
//        if (flag == 1)
//        {
//            int sum = l2->val + 1;
//            if (sum < 10)
//            {
//                a[i++] = sum;
//                flag = 0;
//            }
//            else
//            {
//                a[i++] = sum % 10;
//                flag = 1;
//            }
//        }
//        else
//            a[i++] = l2->val;
//        l2 = l2->next;
//    }
//
//    if (!l1 && !l2 && flag == 1)
//    {
//        a[i++] = 1;
//        flag = 0;
//    }
//
//    struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
//    struct ListNode* cur = head;
//
//    for (int j = 0; j < i; j++)
//    {
//        struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
//        node->val = a[j];
//        cur->next = node;
//        node->next = NULL;
//        cur = node;
//    }
//
//    return head->next;
//}


//void _addTwoNumbers(struct ListNode* cur, int* flag, int sum)
//{
//    if (sum < 10)
//    {
//        cur->val = sum;
//        *flag = 0;
//    }
//    else
//    {
//        cur->val = sum % 10;
//        *flag = 1;
//    }
//
//}
//
//struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) 
//{
//    // 开辟一个头节点，方便插入
//    struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
//    // 插入的前驱结点
//    struct ListNode* prev = head;
//    // 进位标志，为 0 不进位，为1进位
//    int flag = 0;
//    // 
//    while (l1 && l2)
//    {
//        // 构建要新插入的结点
//        struct ListNode* cur = (struct ListNode*)malloc(sizeof(struct ListNode));
//        cur->next = NULL;
//        int sum = l1->val + l2->val;
//        if (flag == 1)
//        {
//            sum++;
//        }
//
//        _addTwoNumbers(cur, &flag, sum);
//
//        prev->next = cur;
//        prev = cur;
//        l1 = l1->next;
//        l2 = l2->next;
//    }
//
//    while (l1)
//    {
//        struct ListNode* cur = (struct ListNode*)malloc(sizeof(struct ListNode));
//        cur->next = NULL;
//        if (flag == 1)
//        {
//            int sum = l1->val + 1;
//            _addTwoNumbers(cur, &flag, sum);
//        }
//        else
//            cur->val = l1->val;
//        prev->next = cur;
//        prev = cur;
//        l1 = l1->next;
//    }
//
//    while (l2)
//    {
//        struct ListNode* cur = (struct ListNode*)malloc(sizeof(struct ListNode));
//        cur->next = NULL;
//        if (flag == 1)
//        {
//            int sum = l2->val + 1;
//            _addTwoNumbers(cur, &flag, sum);
//        }
//        else
//            cur->val = l2->val;
//        prev->next = cur;
//        prev = cur;
//        l2 = l2->next;
//    }
//
//
//    if (!l1 && !l2 && flag == 1)
//    {
//        struct ListNode* cur = (struct ListNode*)malloc(sizeof(struct ListNode));
//        cur->val = 1;
//        cur->next = NULL;
//        prev->next = cur;
//        prev = cur;
//    }
//
//    return head->next;
//}

//// 生成对应两个结点两数和的结点，并返回该结点
//struct ListNode* _addTwoNumbers(int* flag, int sum)
//{
//    struct ListNode* cur = (struct ListNode*)malloc(sizeof(struct ListNode));
//    cur->next = NULL;
//    if (sum < 10)
//    {
//        cur->val = sum;
//        *flag = 0;
//    }
//    else
//    {
//        cur->val = sum % 10;
//        *flag = 1;
//    }
//
//    return cur;
//}
//
//struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
//{
//    // 开辟一个头节点，方便插入
//    struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
//    // 插入的前驱结点
//    struct ListNode* prev = head;
//    // 新开辟的结点
//    struct ListNode* cur = NULL;
//    // 进位标志，为 0 不进位，为 1 进位
//    int flag = 0;
//    // 当两个结点都不为空时，进入循环
//    while (l1 && l2)
//    {
//        int sum = l1->val + l2->val;
//        if (flag == 1)
//        {
//            sum++;
//        }
//
//        cur = _addTwoNumbers(&flag, sum);
//        prev->next = cur;
//        prev = cur;
//
//        l1 = l1->next;
//        l2 = l2->next;
//    }
//
//    while (l1)
//    {
//        if (flag == 1)
//        {
//            int sum = l1->val + 1;
//            cur = _addTwoNumbers(&flag, sum);
//        }
//        else
//            cur = _addTwoNumbers(&flag, l1->val);
//        prev->next = cur;
//        prev = cur;
//        l1 = l1->next;
//    }
//
//    while (l2)
//    {
//        if (flag == 1)
//        {
//            int sum = l2->val + 1;
//            cur = _addTwoNumbers(&flag, sum);
//        }
//        else
//            cur = _addTwoNumbers(&flag, l2->val);
//        prev->next = cur;
//        prev = cur;
//        l2 = l2->next;
//    }
//
//
//    if (!l1 && !l2 && flag == 1)
//    {
//        cur = _addTwoNumbers(&flag, 1);
//        prev->next = cur;
//        prev = cur;
//    }
//
//    return head->next;
//}



//int main()
//{
//    struct ListNode* head1 = (struct ListNode*)malloc(sizeof(struct ListNode));
//    struct ListNode* head2 = (struct ListNode*)malloc(sizeof(struct ListNode));
//    head1->val = 1;
//    head2->val = 0;
//    head2->next = NULL;
//    struct ListNode* node1 = (struct ListNode*)malloc(sizeof(struct ListNode));
//    node1->val = 8;
//    node1->next = NULL;
//    head1->next = node1;
//
//    struct ListNode* ret = addTwoNumbers(head1, head2);
//
//
//    return 0;
//}

// 生成对应两个结点两数和的结点，并插入到前驱结点上
void _addTwoNumbers(struct ListNode** prev,int* flag, int sum)
{
    struct ListNode* cur = (struct ListNode*)malloc(sizeof(struct ListNode));
    cur->next = NULL;
    if (sum < 10)
    {
        cur->val = sum;
        *flag = 0;
    }
    else
    {
        cur->val = sum % 10;
        *flag = 1;
    }

    (*prev)->next = cur;
    *prev = cur;

}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    // 开辟一个头节点，方便插入
    struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
    // 插入的前驱结点
    struct ListNode* prev = head;
    // 进位标志，为 0 不进位，为 1 进位
    int flag = 0;
    // 当两个结点都不为空时，进入循环
    while (l1 && l2)
    {
        int sum = l1->val + l2->val;
        if (flag == 1)
        {
            sum++;
        }

        _addTwoNumbers(&prev, &flag, sum);

        l1 = l1->next;
        l2 = l2->next;
    }
    // 当 l1 不为空
    while (l1)
    {
        if (flag == 1)
        {
            int sum = l1->val + 1;
            _addTwoNumbers(&prev,&flag, sum);
        }
        else
            _addTwoNumbers(&prev,&flag, l1->val);
        
        l1 = l1->next;
    }
    // 当 l2 不为空
    while (l2)
    {
        if (flag == 1)
        {
            int sum = l2->val + 1;
            _addTwoNumbers(&prev,&flag, sum);
        }
        else
            _addTwoNumbers(&prev,&flag, l2->val);

        l2 = l2->next;
    }

    // 当 l1 和 l2 都为空，并且flag == 1时，说明这是仍有进位，要再开辟一个结点存放
    if (!l1 && !l2 && flag == 1)
    {
        _addTwoNumbers(&prev,&flag, 1);
    }

    // 返回头节点之后的结点
    struct ListNode* tmp = head;
    head = head->next;
    free(tmp);
    return head;
}


int maxDepth(char* s) {
    int len = strlen(s);
    int max = 0;
    int size = 0;

    for (int i = 0; i < len; i++)
    {
        if (s[i] == '(')
        {
            size++;
            max = max > size ? max : size;
        }

        if (s[i] == ')')
            size--;
    }

    return max;
}