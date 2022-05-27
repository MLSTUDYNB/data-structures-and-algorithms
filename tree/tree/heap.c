#define _CRT_SECURE_NO_WARNINGS 1

#include "heap.h"

void HeapInit(Heap* hp)
{
	assert(hp);
	hp->arr = NULL;
	hp->size = hp->capacity = 0;
}

void swap(HPDataType* a, HPDataType* b)
{
	HPDataType c = *a;
	*a = *b;
	*b = c;
}

void adjustup(Heap* hp, int child)
{
	int father = (child - 1) / 2;
	while (child > 0)
	{
		if (hp->arr[child] < hp->arr[father])
		{
			swap(&(hp->arr[child]), &(hp->arr[father]));
			child = father;
			father = (child - 1) / 2;
		}	
		else
			break;
	}
}

void adjustdown(Heap* hp, int father)
{
	int child = 2 * father + 1;
	while (child < hp->size)
	{
		if (child < hp->size-1&&hp->arr[child] > hp->arr[child + 1])
			child++;
		if (hp->arr[child] < hp->arr[father])
		{
			swap(&(hp->arr[child]), &(hp->arr[father]));
			father=child;
			child = 2 * father + 1;
		}
		else
			break;
	}
}

void HeapPush(Heap* hp, HPDataType x)
{
	assert(hp);
	if (hp->size == hp->capacity)
	{
		int newcapcity = hp->capacity == 0 ? 4 : hp->capacity * 2;
		HPDataType* newarr = (HPDataType*)realloc(hp->arr, newcapcity * sizeof(HPDataType));
		if (newarr == NULL)
			exit(-1);
		hp->arr = newarr;
		hp->capacity = newcapcity;
	}
	hp->arr[hp->size] = x;
	hp->size++;

	//���ϵ���
	adjustup(hp,hp->size-1);
}

void HeapPop(Heap* hp)
{
	assert(hp);
	assert(hp->size);
	
	swap(&(hp->arr[0]), &(hp->arr[hp->size-1]));
	hp->size--;
	//���µ���
	adjustdown(hp,0);
}

void HeapDestrop(Heap* hp)
{
	assert(hp);
	free(hp->arr);
	hp->size = hp->capacity = 0;
}

void HeapPrint(Heap* hp)
{
	assert(hp);
	for (int i = 0; i < hp->size; i++)
	{
		printf("%d ", hp->arr[i]);
	}
	printf("\n");
}