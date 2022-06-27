#define _CRT_SECURE_NO_WARNINGS 1

#include "sort.h"

void print(int* a, int n)
{
	int i = 0;
	for (i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

int main()
{
	int arr[10] = { 9,1,2,5,7,4,8,6,3,5};
	//InsertSort(arr, 10);
	//ShellSort(arr, 10);
	//SelectSort(arr, 10);
	//BubbleSort(arr, 10);
	//HeapSort(arr, 10);
	QuickSort(arr, 0, 9);
	print(arr, 10);
	return 0;
}