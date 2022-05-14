#define _CRT_SECURE_NO_WARNINGS 1

#include "List.h"

void test1()
{
	LNode* head = InitList();

	//ListPushBack(head, 1);
	//ListPushBack(head, 2);
	//ListPushBack(head, 3);
	//ListPushBack(head, 4);
	//PrintList(head);
	//ListPopBack(head);
	//PrintList(head);
	//ListPopBack(head);
	//PrintList(head);
	//ListPopBack(head);
	//PrintList(head);
	//ListPopBack(head);
	//PrintList(head);
	//
	ListPushFront(head, 1);
	ListPushFront(head, 2);
	ListPushFront(head, 3);
	ListPushFront(head, 4);
	PrintList(head);
	//ListPopFront(head);
	//PrintList(head);
	//ListPopFront(head);
	//PrintList(head);
	//ListPopFront(head);
	//PrintList(head);
	//ListPopFront(head);
	//PrintList(head);
	ListDestroy(head);

	
}

int main()
{
	test1();

	return 0;
}