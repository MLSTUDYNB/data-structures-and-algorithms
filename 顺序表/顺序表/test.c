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
	SeqListPopBack(&s, 5);
	SeqListPrint(&s);
}
int main()
{
	test();
	return 0;
}