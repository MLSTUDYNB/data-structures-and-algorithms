#define _CRT_SECURE_NO_WARNINGS 1

#include "queue.h"

void QueueInit(Queue* q)
{
	assert(q);
	q->head = q->tail = NULL;
}

bool QueueEmpty(Queue* q)
{
	assert(q);

	return q->head == NULL;
}

void QueuePush(Queue* q, QueueTypeDate x)
{
	assert(q);
	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	newnode->next = NULL;
	newnode->val = x;

	if (QueueEmpty(q))
		q->head = q->tail = newnode;
	else
	{
		q->tail->next = newnode;
		q->tail = newnode;
	}
}
void QueuePop(Queue* q)
{
	assert(q);
	assert(!QueueEmpty(q));
	if (q->head == q->tail)
	{
		free(q->head);
		q->head = q->tail = NULL;
	}
	else
	{
		QNode* next = q->head->next;
		free(q->head);
		q->head = next;
	}
	
}
QueueTypeDate QueueFront(Queue* q)
{
	assert(q);
	assert(!QueueEmpty(q));

	return q->head->val;
}
QueueTypeDate QueueBack(Queue* q)
{
	assert(q);
	assert(!QueueEmpty(q));

	return q->tail->val;
}
int QueueSize(Queue* q)
{
	assert(q);
	QNode* cur = q->head;
	int size = 0;
	while (cur)
	{
		size++;
		cur = cur->next;
	}
	return size;
}
void QueueDestroy(Queue* q)
{
	assert(q);
	while (q->head)
	{
		QueuePop(q);
	}
}
