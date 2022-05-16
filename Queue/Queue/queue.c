#define _CRT_SECURE_NO_WARNINGS 1

#include "queue.h"

void QueueInit(Queue* q)
{
	assert(q);
	q->head = q->tail = NULL;
}
void QueuePush(Queue* q, QueueTypeDate x);
void QueuePop(Queue* q);
QueueTypeDate QueueFront(Queue* q);
QueueTypeDate QueueBack(Queue* q);
int QueueSize(Queue* q);
void QueueDestroy(Queue* q);
bool QueueEmpty(Queue* q);