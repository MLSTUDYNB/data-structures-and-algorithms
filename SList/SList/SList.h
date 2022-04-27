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

//����Ĵ�ӡ
void SListPrint(SListNode* phead);

//���������
void SListDestory(SListNode** pphead);

//ͷ��
void SListPushFront(SListNode** pphead, SLTypeDate x);

//β��
void SListPushBack(SListNode** pphead, SLTypeDate x);

//βɾ
void SListPopBack(SListNode** pphead);

//ͷɾ
void SListPopFront(SListNode** pphead);

//����
SListNode* SListFind(SListNode* phead, SLTypeDate x);

//�ڲ���λ��֮ǰ����
void SListInsertPre(SListNode** pphead,SListNode* pos, SLTypeDate x);

//�ڲ���λ��֮�����
void SListInsertAfter(SListNode* pos, SLTypeDate x);

//ɾ������λ�õĽڵ�
void SListErase(SListNode** pphead, SListNode* pos);

//ɾ������λ��֮��Ľڵ�
void SListEraseAfter(SListNode* pos);