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

// 栈初始化
void StackInit(ST* ps);
// 栈销毁
void StackDestroy(ST* ps);
// 插入数据
void StackPush(ST* ps, STDataType x);
// 删除数据
void StackPop(ST* ps);
// 取栈顶数据
STDataType StackTop(ST* ps);
// 栈中数据个数
int StackSize(ST* ps);
// 判断栈是否为空
bool StackEmpty(ST* ps);