#define _CRT_SECURE_NO_WARNINGS 1
#include "SequenceList.h"

void SeqListInit(SeqList* psql)
{
	assert(psql);
	psql->arr = NULL;
	psql->size = 0;
	psql->capacity = 0;
}

void SeqListDestroy(SeqList* psql)
{
	assert(psql);
	free(psql->arr);
	psql->arr = NULL;
	psql->capacity = psql->size = 0;
}

void CheckCapacity(SeqList* psql)
{
	if (psql->size == psql->capacity)
	{
		psql->capacity += 10;
		SLDataType* temp = (SLDataType*)realloc(psql->arr, psql->capacity * sizeof(SLDataType));
		if (temp == NULL)
		{
			printf("À©ÈÝ%s\n", strerror(errno));
			exit(-1);
		}
		psql->arr = temp;
	}
}

void SeqListPushBack(SeqList* psql, SLDataType x)
{
	assert(psql);
	CheckCapacity(psql);
	//psql->arr[psql->size] = x;
	//psql->size++;
	SeqListInsert(psql, psql->size, x);
}

void SeqListPopBack(SeqList* psql)
{
	assert(psql);
	assert(psql->size);
	//psql->size--;
	SeqListErase(psql, psql->size - 1);
}

void SeqListPopFront(SeqList* psql)
{
	assert(psql);
	assert(psql->size);
	//int i = 0;
	//while (i < psql->size-1)
	//{
	//	psql->arr[i] = psql->arr[i + 1];
	//	i++;
	//}
	//psql->size--;
	SeqListErase(psql, 0);
}

void SeqListPushFront(SeqList* psql, SLDataType x)
{
	assert(psql);
	CheckCapacity(psql);
	int i = 0;
	for (i = psql->size; i > 0; i--)
	{
		psql->arr[i] = psql->arr[i - 1];
	}
	psql->arr[i] = x;
	psql->size++;
}

void SeqListPrint(SeqList* psql)
{
	assert(psql);
	int i = 0;
	for (i = 0; i < psql->size; i++)
	{
		printf("%d ", psql->arr[i]);
	}
	printf("\n");
}

void SeqListInsert(SeqList* psql, int Pos, SLDataType x)
{
	assert(psql);
	assert(Pos >= 0 && Pos <= psql->size);
	CheckCapacity(psql);
	int i = psql->size-1;
	while (i>=Pos)
	{
		psql->arr[i + 1] = psql->arr[i];
		i--;
	}
	psql->arr[Pos] = x;
	psql->size++;
}

void SeqListErase(SeqList* psql, int Pos)
{
	assert(psql);
	assert(Pos >= 0 && Pos < psql->size);
	int i = Pos;
	while (i<psql->size-1)
	{
		psql->arr[i] = psql->arr[i + 1];
		i++;
	}
	psql->size--;
}

int SeqListFind(SeqList* psql, SLDataType x)
{
	assert(psql);
	int pos = 0;
	while (pos < psql->size)
	{
		if (psql->arr[pos] == x)
			return pos;
		pos++;
	}
	return -1;
}