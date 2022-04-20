#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int SLDataType;

typedef struct seqlist
{
	SLDataType* arr;
	int size;
	int capacity;
}SeqList;

//��ʼ��
void SeqListInit(SeqList* psql);

//����Ƿ���������
void CheckCapacity(SeqList* psql);

//β��
void SeqListPushBack(SeqList* psql, SLDataType x);

//ͷ��
void SeqListPopBack(SeqList* psql, SLDataType x);

//��ӡ
void SeqListPrint(SeqList* psql);