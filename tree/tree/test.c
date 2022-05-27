#define _CRT_SECURE_NO_WARNINGS 1

#include "heap.h"

void test1()
{
	Heap hp;
	HeapInit(&hp);
	
	HeapPush(&hp, 2);
	HeapPush(&hp, 3);
	HeapPush(&hp, 7);
	HeapPush(&hp, 5);
	HeapPush(&hp, 1);
	HeapPush(&hp, 4);
	HeapPush(&hp, 6);
	HeapPush(&hp, 0);
	HeapPush(&hp, 8);
	HeapPrint(&hp);
	HeapPop(&hp);
	HeapPrint(&hp);
	HeapPop(&hp);
	HeapPrint(&hp);
	HeapPop(&hp);
	HeapPrint(&hp);
	HeapPop(&hp);
	HeapPrint(&hp);
	HeapDestrop(&hp);
	HeapPrint(&hp);
}

int main()
{
	test1();
	
	return 0;
}