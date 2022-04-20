#define _CRT_SECURE_NO_WARNINGS 1
#include "SequenceList.h"

void SeqListInit(SeqList* psql)
{
	psql->arr = NULL;
	psql->size = 0;
	psql->capacity = 0;
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
	CheckCapacity(psql);
	psql->arr[psql->size] = x;
	psql->size++;
}

void SeqListPopBack(SeqList* psql, SLDataType x)
{
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
	int i = 0;
	for (i = 0; i < psql->size; i++)
	{
		printf("%d ", psql->arr[i]);
	}
	printf("\n");
}