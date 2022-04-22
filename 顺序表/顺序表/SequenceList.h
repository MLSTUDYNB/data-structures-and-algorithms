#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef int SLDataType;

typedef struct seqlist
{
	SLDataType* arr;
	int size;
	int capacity;
}SeqList;

//��ʼ��
void SeqListInit(SeqList* psql);

//����
void SeqListDestroy(SeqList* psql);

//����Ƿ���������
void CheckCapacity(SeqList* psql);

//β��
void SeqListPushBack(SeqList* psql, SLDataType x);

//βɾ
void SeqListPopBack(SeqList* psql);
//ͷɾ
void SeqListPopFront(SeqList* psql);

//ͷ��
void SeqListPushFront(SeqList* psql, SLDataType x);

//��ӡ
void SeqListPrint(SeqList* psql);

//����λ�ò���
void SeqListInsert(SeqList* psql, int Pos, SLDataType x);

//����λ��ɾ��
void SeqListErase(SeqList* psql, int Pos);

//����
int SeqListFind(SeqList* psql, SLDataType x);