#define _CRT_SECURE_NO_WARNINGS 1

#include "SList.h"

void test1()
{
	int i = 0;
	SListNode* a[100];
	for (i = 0; i < 5; i++)
	{
		a[i] = (SListNode*)malloc(sizeof(SListNode));
		assert(a[i]);
		a[i]->date = i;
		
	}
	for (i = 0; i < 4; i++)
	{
		a[i]->next = a[i + 1];
	}
	a[i]->next =NULL;
	SListPrint(*a);
	SListNode* pos= SListFind(*a,0);
	SListInsertPre(a, pos, 40);
	SListPrint(*a);
	//SListPopFront(a);
	//SListPopFront(a);
	//SListPopFront(a);
	//SListPopFront(a);
	//SListPrint(*a);
	//SListPopFront(a);

	//SListPrint(*a);

}

void test2()
{
	SListNode* a = NULL;
	SListPushBack(&a, 5);
	SListPrint(a);
	SListPushFront(&a, 2);
	SListPrint(a);
}
int main()
{

	test1();
	//test2();
	return 0;
}