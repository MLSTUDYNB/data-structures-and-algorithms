#define _CRT_SECURE_NO_WARNINGS 1

#include "SequenceList.h"


void test()
{
	SeqList s;
	SeqListInit(&s);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	//SeqListPushFront(&s, 5);
	//SeqListPushFront(&s, 6);
	//SeqListPushFront(&s, 7);
	SeqListPrint(&s);
	SeqListPopFront(&s);
	SeqListPrint(&s);

	SeqListPopFront(&s);
	SeqListPrint(&s);
	SeqListPopFront(&s);
	SeqListPrint(&s);
	SeqListPopFront(&s);
	SeqListPrint(&s);
	SeqListPopFront(&s);
	SeqListPrint(&s);
	SeqListPopFront(&s);
	SeqListPrint(&s);

	SeqListPopFront(&s);
	SeqListPrint(&s);

	SeqListPopFront(&s);
	SeqListPrint(&s);



}


void test1()
{
	SeqList s;
	SeqListInit(&s);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);

	SeqListPopFront(&s);
	SeqListPopFront(&s);
	SeqListPopFront(&s);
	SeqListPopFront(&s);
	SeqListPopFront(&s);

	SeqListPushFront(&s,2);
	SeqListDestroy(&s);
}

void test2()
{
	SeqList s;
	SeqListInit(&s);
	SeqListPushFront(&s, 1);
	SeqListPushFront(&s, 2);
	SeqListPushFront(&s, 3);
	SeqListPushFront(&s, 4);
	SeqListPushFront(&s, 5);
	SeqListPushFront(&s, 6);
	SeqListPushFront(&s, 7);
	SeqListPrint(&s);
	SeqListPopBack(&s);
	SeqListPrint(&s);
	SeqListPopFront(&s);
	SeqListPrint(&s);
	
	int ret=SeqListFind(&s, 5);
	if (ret == -1)
	{
		printf("找不到\n");
	}
	else
	{
		printf("找到了，下标为%d\n", ret);
	}
	//SeqListErase(&s, 0);
	//SeqListPrint(&s);
	//SeqListErase(&s, 5);
	//SeqListPrint(&s);
	//SeqListErase(&s,2);
	
	//SeqListE(&s, 0, 5);
	//SeqListPrint(&s);
	//SeqListInsert(&s, 5, 40);
	//SeqListPrint(&s);
	//SeqListInsert(&s, 2, 100);
	//SeqListPrint(&s);
	//SeqListPushFront(&s,6);
	//SeqListPrint(&s);
	//SeqListPushBack(&s, 8);
	//SeqListPrint(&s);
	SeqListDestroy(&s);
}
int main()
{
	//test();
	//test1();
	test2();
	return 0;
}