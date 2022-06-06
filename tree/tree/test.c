#define _CRT_SECURE_NO_WARNINGS 1

#include "heap.h"
#include <time.h>
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
//降序
void HeapSort(int* a, int n)
{
	//建小堆
	//向上建堆
	int i = 0;
	//for (i = (n - 1 - 1) / 2; i >= 0; i--)
	//{
	//	adjustdown(a,n, i);
	//}
	//向下建堆
	for (i = 1; i <n; i++)
	{
		adjustup(a, i);
	}
	//排序
	for (i = 0; i < n; i++)
	{
		swap(&a[0], &a[n - 1 - i]);
		adjustdown(a, n-i-1, 0);
	}
}

void test2()
{
	int a[] = { 1,6,7,9,6,4,8,3,1,6,5 };
	HeapSort(a,sizeof(a)/sizeof(a[0]));
}

void TopK(int* a, int n, int k)
{
	//建堆
	int* TopKHeap = (int*)malloc(sizeof(int) * k);
	assert(TopKHeap);
	for (int i = 0; i < k; i++)
	{
		TopKHeap[i] = a[i];
		
	}
	for (int i =(k-1-1)/2; i >= 0; i--)
	{
		adjustdown(TopKHeap, k, i);
	}
	//获得前k个
	for (int i = k; i < n; i++)
	{
		if (TopKHeap[0] < a[i])
		{
			TopKHeap[0] = a[i];
			adjustdown(TopKHeap, k, 0);
		}
	}

	for (int i = 0; i < k; i++)
	{
		printf("%d ", TopKHeap[i]);
	}
	printf("\n");
}

void test3()
{
	int n = 10000;
	int* a = (int*)malloc(sizeof(int) * n);
	srand(time(0));
	for (size_t i = 0; i < n; ++i)
	{
		a[i] = rand() % 1000000;
	}
	a[5] = 1000000 + 1;
	a[1231] = 1000000 + 2;
	a[531] = 1000000 + 3;
	a[5121] = 1000000 + 4;
	a[115] = 1000000 + 5;
	a[2335] = 1000000 + 6;
	a[9999] = 1000000 + 7;
	a[76] = 1000000 + 8;
	a[423] = 1000000 + 9;
	a[3144] = 1000000 + 10;
	TopK(a, n, 10);
}

int main()
{
	//test1();
	//test2();
	test3();
	return 0;
}