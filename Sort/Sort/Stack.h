# define _CRT_SECURE_NO_WARNINGS

#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef int STDataType;
typedef struct Stack
{
	STDataType* a;
	int top;
	int capacity;
}ST;

// ջ��ʼ��
void StackInit(ST* ps);
// ջ����
void StackDestroy(ST* ps);
// ��������
void StackPush(ST* ps, STDataType x);
// ɾ������
void StackPop(ST* ps);
// ȡջ������
STDataType StackTop(ST* ps);
// ջ�����ݸ���
int StackSize(ST* ps);
// �ж�ջ�Ƿ�Ϊ��
bool StackEmpty(ST* ps);