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

//初始化
void SeqListInit(SeqList* psql);

//检查是否容量已满
void CheckCapacity(SeqList* psql);

//尾插
void SeqListPushBack(SeqList* psql, SLDataType x);

//头插
void SeqListPopBack(SeqList* psql, SLDataType x);

//打印
void SeqListPrint(SeqList* psql);