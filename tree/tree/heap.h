#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int HPDataType;

typedef struct heap
{
	HPDataType* arr;
	int size;
	int capacity;
}Heap;

void HeapInit(Heap* hp);

void HeapPush(Heap* hp, HPDataType x);

void HeapPop(Heap* hp);

void HeapDestrop(Heap* hp);

void HeapPrint(Heap* hp);