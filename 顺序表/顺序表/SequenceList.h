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

//初始化
void SeqListInit(SeqList* psql);

//销毁
void SeqListDestroy(SeqList* psql);

//检查是否容量已满
void CheckCapacity(SeqList* psql);

//尾插
void SeqListPushBack(SeqList* psql, SLDataType x);

//尾删
void SeqListPopBack(SeqList* psql);
//头删
void SeqListPopFront(SeqList* psql);

//头插
void SeqListPushFront(SeqList* psql, SLDataType x);

//打印
void SeqListPrint(SeqList* psql);

//任意位置插入
void SeqListInsert(SeqList* psql, int Pos, SLDataType x);

//任意位置删除
void SeqListErase(SeqList* psql, int Pos);

//查找
int SeqListFind(SeqList* psql, SLDataType x);