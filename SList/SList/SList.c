#define _CRT_SECURE_NO_WARNINGS 1

#include "SList.h"

SListNode* BuySListNode(SLTypeDate x)
{
	SListNode* NewNode = (SListNode*)malloc(sizeof(SListNode));
	if (NewNode == NULL)
		exit(-1);
	NewNode->date = x;
	NewNode->next = NULL;
	return NewNode;
}

void SListPrint(SListNode* phead)
{
	while (phead)
	{
		printf("%d->", phead->date);
		phead = phead->next;
	}
	printf("NULL\n");
}

void SListPushFront(SListNode** pphead, SLTypeDate x)
{
	assert(pphead);
	SListNode* NewNode=BuySListNode(x);
	//SListNode* NewNode = (SListNode*)malloc(sizeof(SListNode));
	//if (NewNode == NULL)
	//	exit(-1);
	//NewNode->date = x;
	NewNode->next = *pphead;
	*pphead = NewNode;
}

void SListPushBack(SListNode** pphead, SLTypeDate x)
{
	assert(pphead);
	SListNode* NewNode = BuySListNode(x);
	if (*pphead == NULL)
	{
		*pphead = NewNode;
	}
	else
	{
		SListNode* tail = *pphead;
		while (tail->next)
		{
			tail = tail->next;
		}
		tail->next = NewNode;

	}
	
}

void SListPopBack(SListNode** pphead)
{
	assert(*pphead);

	if ((*pphead)->next==NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	else
	{
		SListNode* tail = *pphead;
		while (tail->next->next != NULL)
		{
			tail = tail->next;
		}
		free(tail->next);
		tail->next = NULL;
	}
}

void SListPopFront(SListNode** pphead)
{
	assert(*pphead);
	SListNode* cur = (*pphead)->next;
	free(*pphead);
	*pphead = cur;
}

SListNode* SListFind(SListNode* phead, SLTypeDate x)
{
	assert(phead);
	while (phead->date!=x)
	{
		phead = phead->next;
		if (phead == NULL)
			return NULL;
	}
	return phead;
}

void SListDestory(SListNode** pphead)
{
	assert(pphead);
	SListNode* cur =*pphead;
	while (cur)
	{
		cur = (*pphead)->next;
		free(*pphead);
		*pphead = cur;
	}
}

void SListInsertPre(SListNode** pphead, SListNode* pos, SLTypeDate x)
{
	assert(pphead);
	assert(pos);
	SListNode* NewNode = BuySListNode(x);
	
	if (pos==*pphead)
	{
		//NewNode->next = *pphead;
		//*pphead = NewNode;
		SListPushFront(pphead,x);
	}
	else
	{
		SListNode* cur = *pphead;
		while (cur->next != pos)
		{
			cur = cur->next;
		}
		NewNode->next = pos;
		cur->next = NewNode;
	}
	
}