#pragma one

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef int QueueTypeDate;

typedef struct QListNode
{
	struct QListNode* next;
	QueueTypeDate val;
}QNode;

typedef struct Queue
{
	QNode* head;
	QNode* tail;
}Queue;

void QueueInit(Queue* q);
void QueuePush(Queue* q, QueueTypeDate x);
void QueuePop(Queue* q);
QueueTypeDate QueueFront(Queue* q);
QueueTypeDate QueueBack(Queue* q);
int QueueSize(Queue* q);
void QueueDestroy(Queue* q);
bool QueueEmpty(Queue* q);