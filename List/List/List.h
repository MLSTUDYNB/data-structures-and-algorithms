#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int ListTypeDate;

typedef struct ListNode
{
	struct ListNode* prev;
	struct ListNode* next;
	ListTypeDate val;
}LNode;

LNode* InitList();

//¥Ú”°
void PrintList(LNode* head);

void ListPushFront(LNode* head,ListTypeDate x);

void ListPushBack(LNode* head, ListTypeDate x);

void ListPopFront(LNode* head);

void ListPopBack(LNode* head);

void ListInsert(LNode* head, LNode* pos, ListTypeDate x);

void ListErase(LNode* head, LNode* pos);

void ListDestroy(LNode* head);