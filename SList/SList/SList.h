#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SLTypeDate;

typedef struct SListNode
{
	SLTypeDate date;
	struct SListNode* next;
}SListNode;

//链表的打印
void SListPrint(SListNode* phead);

//链表的销毁
void SListDestory(SListNode** pphead);

//头插
void SListPushFront(SListNode** pphead, SLTypeDate x);

//尾插
void SListPushBack(SListNode** pphead, SLTypeDate x);

//尾删
void SListPopBack(SListNode** pphead);

//头删
void SListPopFront(SListNode** pphead);

//查找
SListNode* SListFind(SListNode* phead, SLTypeDate x);

//在查找位置之前插入
void SListInsertPre(SListNode** pphead,SListNode* pos, SLTypeDate x);

//在查找位置之后插入
void SListInsertAfter(SListNode* pos, SLTypeDate x);

//删除查找位置的节点
void SListErase(SListNode** pphead, SListNode* pos);

//删除查找位置之后的节点
void SListEraseAfter(SListNode* pos);