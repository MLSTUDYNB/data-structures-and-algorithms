#define _CRT_SECURE_NO_WARNINGS 1

#include "List.h"

LNode* BuyNewNode(ListTypeDate x)
{
	LNode* newnode = (LNode*)malloc(sizeof(LNode));
	if (newnode == NULL)
	{
		printf("开辟节点失败\n");
		exit(-1);
	}	
	newnode->val = x;
	
	return newnode;
}

LNode* InitList()
{
	LNode* head = BuyNewNode(-1);
	head->prev = head;
	head->next = head;
	return head;
}

void PrintList(LNode* head)
{
	assert(head);
	LNode* cur = head->next;
	while (cur != head)
	{
		printf("%d ", cur->val);
		cur = cur->next;
	}
	printf("\n");
}

void ListPushFront(LNode* head, ListTypeDate x)
{
	//assert(head);
	//LNode* newnode = BuyNewNode(x);
	//LNode* cur = head->next;

	//head->next = newnode;
	//newnode->prev = head;
	//newnode->next = cur;
	//cur->prev = newnode;
	ListInsert(head,head->next, x);
}

void ListPushBack(LNode* head, ListTypeDate x)
{
	//LNode* newnode = BuyNewNode(x);
	//LNode* tail = head->prev;

	//head->prev = newnode;
	//newnode->next = head;
	//tail->next = newnode;
	//newnode->prev = tail;
	ListInsert(head,head, x);
}

void ListPopFront(LNode* head)
{
	//assert(head);
	////链表没有节点的时候不能进行删除
	//assert(head->next != head);

	//LNode* cur = head->next;
	//LNode* curnext = cur->next;

	//head->next = curnext;
	//curnext->prev = head;

	//free(cur);
	ListErase(head,head->next);
}

void ListPopBack(LNode* head)
{
	//assert(head);
	////链表没有节点的时候不能进行删除
	//assert(head->next != head);

	//LNode* tail = head->prev;
	//LNode* tailprev = tail->prev;

	//head->prev = tailprev;
	//tailprev->next = head;

	//free(tail);
	ListErase(head,head->prev);
}

void ListInsert(LNode* head, LNode* pos, ListTypeDate x)
{
	assert(head);
	LNode* newnode = BuyNewNode(x);
	LNode* posprev = pos->prev;
	posprev->next = newnode;
	newnode->prev = posprev;
	newnode->next = pos;
	pos->prev = newnode;
}

void ListErase(LNode* head, LNode* pos)
{
	assert(head);
	assert(head->next != head);
	LNode* posnext = pos->next;
	LNode* posprev = pos->prev;

	posprev->next = posnext;
	posnext->prev = posprev;
	free(pos);
}

void ListDestroy(LNode* head)
{
	while (head!=head->next)
	{
		ListPopBack(head);
		//PrintList(head);
	}
	free(head);
}