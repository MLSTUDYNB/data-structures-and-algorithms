#define _CRT_SECURE_NO_WARNINGS 1

#include "sort.h"

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
//void insert(int* a, int n)
//{
//	for (int i = 1; i < n; i++)
//	{
//		int temp = a[i];
//		int j = i - 1;
//		for (; j >= 0; j--)
//		{
//			if (temp > a[j])
//			{
//				a[j + 1] = temp;
//				break;
//			}
//			else
//				a[j + 1] = a[j];
//		}
//		if (j == -1)
//			a[0] = temp;
//
//	}
//}
//
//int PartSort3(int* a, int begin, int end)
//{
//	int key = begin;
//	int* cur, *prev;
//	cur = prev = a + begin;
//	while (cur <= a + end)
//	{
//		if (*cur < a[key])
//		{
//			prev++;
//			int temp = *prev;
//			*prev = *cur;
//			*cur = temp;
//		}
//		else
//			cur++;
//	}
//	int temp = *prev;
//	*prev = a[key];
//	a[key] = temp;
//}
void InsertSort(int* a, int n)
{
	int i = 0;
	for (i = 0; i < n-1; i++)
	{
		int end=i;
		int key = a[end + 1];
		while (end>=0)
		{
			if (a[end] <= key)
				break;
			else
				a[end + 1] = a[end];
			end--;
		}
		a[end + 1] = key;
	}
}

void ShellSort(int* a, int n)
{
	int gap = n;
	while (gap>1)
	{
		gap = gap / 2;
		for (int i = 0; i < n-gap; i++)
		{
			int end = i;
			int key = a[end + gap];
			while (end >= 0)
			{
				if (a[end] <= key)
					break;
				else
					a[end + gap] = a[end];
				end -= gap;
			}
			a[end + gap] = key;
		}
	}
	
}

void SelectSort(int* a, int n)
{
	int min, max;
	int begin = 0, end = n - 1;	
	while (begin < end)
	{
		min = max = begin;
		for (int i = begin; i <= end; i++)
		{
			if (a[min] > a[i])
				min = i;
			if (a[max] < a[i])
				max = i;
		}
		swap(&a[min], &a[begin]);
		if (begin == max)
			max = min;
		swap(&a[max], &a[end]);
		begin++;
		end--;
	}
	
}