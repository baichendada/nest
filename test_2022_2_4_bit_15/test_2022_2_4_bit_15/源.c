# define _CRT_SECURE_NO_WARNINGS

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

typedef struct BinaryTreeNode* QDataType;

// 链式结构：表示队列 
typedef struct QListNode
{
	struct QListNode* next;
	QDataType data;
}QNode;

// 队列的结构 
typedef struct Queue
{
	QNode* front;
	QNode* rear;
}Queue;

// 初始化队列 
void QueueInit(Queue* q);
// 队尾入队列 
void QueuePush(Queue* q, QDataType data);
// 队头出队列 
void QueuePop(Queue* q);
// 获取队列头部元素 
QDataType QueueFront(Queue* q);
// 获取队列队尾元素 
QDataType QueueBack(Queue* q);
// 获取队列中有效元素个数 
int QueueSize(Queue* q);
// 检测队列是否为空，如果为空返回非零结果，如果非空返回0 
bool QueueEmpty(Queue* q);
// 销毁队列 
void QueueDestroy(Queue* q);

void QueueInit(Queue* q)
{
	assert(q);

	q->front = NULL;
	q->rear = NULL;
}

void QueueDestroy(Queue* q)
{
	assert(q);
	QNode* cur = q->front;

	while (cur)
	{
		QNode* next = cur->next;
		free(cur);
		cur = next;
	}

	q->front = NULL;
	q->rear = NULL;
}

bool QueueEmpty(Queue* q)
{
	assert(q);

	return q->front == NULL;
}

void QueuePush(Queue* q, QDataType data)
{
	assert(q);

	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	if (newnode == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}

	newnode->next = NULL;
	newnode->data = data;

	if (q->front == NULL)
	{
		q->front = q->rear = newnode;
	}
	else
	{
		q->rear->next = newnode;
		q->rear = newnode;
	}
}

void QueuePop(Queue* q)
{
	assert(q);
	assert(!QueueEmpty(q));

	QNode* next = q->front->next;

	free(q->front);
	q->front = next;

	if (q->front == NULL)
	{
		q->rear = NULL;
	}
}

QDataType QueueFront(Queue* q)
{
	assert(q);
	assert(!QueueEmpty(q));

	return q->front->data;
}

QDataType QueueBack(Queue* q)
{
	assert(q);
	assert(!QueueEmpty(q));

	return q->rear->data;
}

int QueueSize(Queue* q)
{
	assert(q);

	int sz = 0;
	QNode* cur = q->front;

	while (cur)
	{
		sz++;
		cur = cur->next;
	}

	return sz++;
}

bool isEvenOddTree(struct TreeNode* root) {
	Queue q;
	QueueInit(&q);
	QueuePush(&q, root);
	struct TreeNode* begin = root;
	int i = 0;
	int layer = -1;
	int n = 0;
	int before = 0;
	int j = 0;

	while (!QueueEmpty(&q))
	{

		struct TreeNode* tmp = QueueFront(&q);
		if (tmp == begin)
		{
			i = 0;
			j = 0;
			layer++;
		}
		QueuePop(&q);

		if (j == 0)
		{
			if (layer % 2 == 1)
				before = INT_MAX;
			if (layer % 2 == 0)
				before = INT_MIN;
			j = 1;
		}

		if (layer % 2 == 0)
		{
			if (tmp->val % 2 != 1 || before >= tmp->val)
			{
				return false;
			}

		}
		else
		{
			if (tmp->val % 2 != 0 || before <= tmp->val)
			{
				return false;
			}
		}

		before = tmp->val;

		if (tmp->left)
		{
			QueuePush(&q, tmp->left);
			i++;
		}
		if (i == 1)
		{
			begin = tmp->left;
			i++;
		}
		if (tmp->right)
		{
			QueuePush(&q, tmp->right);
			i++;
		}
		if (i == 1)
		{
			begin = tmp->right;
			i++;
		}
	}
	QueueDestroy(&q);

	return true;
}


#define N 100002
bool isEvenOddTree(struct TreeNode* root)
{
	//申请队列空间，使用数组模拟队列
	struct TreeNode* queue[N];
	int front = 0;
	int rear = 0;
	int odd = 0; //odd用于判断奇偶层[0:偶数层，1:奇数层]
	int pre; //表示当前行判断节点的前驱节点
	queue[rear++] = root;
	while (front != rear)
	{
		int cnt = rear - front;
		if (odd == 1)
			pre = INT_MAX;
		if (odd == 0)
			pre = INT_MIN;
		for (int i = 0; i < cnt; i++)
		{
			root = queue[front++];
			//偶数行判断
			if ((odd == 1) && (root->val % 2 != 0 || pre <= root->val))
				return false;
			//奇数行判断
			if ((odd == 0) && (root->val % 2 != 1 || pre >= root->val))
				return false;
			pre = root->val;
			if (root->left)
				queue[rear++] = root->left;
			if (root->right)
				queue[rear++] = root->right;
		}
		//控制奇偶行标记
		odd = (odd + 1) % 2;
	}
	return true;
}


int* relativeSortArray(int* arr1, int arr1Size, int* arr2, int arr2Size, int* returnSize) {
	int* a = (int*)calloc(1001, sizeof(int));
	*returnSize = arr1Size;

	for (int i = 0; i < arr1Size; i++)
	{
		a[arr1[i]]++;
	}

	int j = 0;

	for (int i = 0; i < arr2Size; i++)
	{
		while (a[arr2[i]])
		{
			arr1[j++] = arr2[i];
			a[arr2[i]]--;
		}
	}

	for (int i = 0; i < 1001; i++)
	{
		while (a[i]--)
		{
			arr1[j++] = i;
		}
	}

	return arr1;
}