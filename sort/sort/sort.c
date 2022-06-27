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
void AdjustDwon(int* a, int n, int root)
{
	int father = root;
	int child = 2 * father + 1;
	while (child <n)
	{
		if (child<n - 1 && a[child]<a[child + 1])
			child++;
		if (a[father] < a[child])
		{
			swap(&a[father], &a[child]);
			father = child;
			child = 2 * father + 1;
		}
		else
			return;
	}
}
void HeapSort(int* a, int n)
{
	int i = 0;
	for (i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDwon(a, n, i);
	}

	for (i = n - 1; i > 0; i--)
	{
		swap(&a[0], &a[i]);
		AdjustDwon(a, i-1, 0);
	}
}
void BubbleSort(int* a, int n)
{
	int begin = 0;
	int end = n - 1;
	for (int i = begin; i < n-1; i++)
	{
		for (int j = begin; j < end; j++)
		{
			if (a[j+1] < a[j])
				swap(&a[j], &a[j+1]);
		}
		end--;
	}
	//for (int i = 0; i < n - 1; i++)
	//{
	//	for (int j = 0; j < n - i - 1; j++)
	//	{
	//		if (a[j + 1] < a[j])
	//			swap(&a[j + 1], &a[j]);
	//	}
	//}
}
// 快速排序递归实现
// 快速排序hoare版本
int PartSort1(int* a, int left, int right)
{
	int keyi = left;
	while (left < right)
	{
		while (left < right && a[keyi] <= a[right])
			right--;
		while (left < right && a[left] <= a[keyi])
			left++;
		swap(&a[left], &a[right]);
	}
	swap(&a[keyi], &a[right]);
	keyi = left;
	return keyi;
}
// 快速排序挖坑法
int PartSort2(int* a, int left, int right)
{
	int keyi= left;
	int temp = a[left];
	while (left < right)
	{
		while (left<right&&a[right] >= temp)
		{
			right--;
		}
		a[keyi] = a[right];
		keyi = right;
		while (left < right && a[left] <= temp)
		{
			left++;
		}
		a[keyi] = a[left];
		keyi = left;
	}
	a[keyi] = temp;
	return keyi;
}
// 快速排序前后指针法
int PartSort3(int* a, int left, int right);
void QuickSort(int* a, int left, int right)
{
	if (left >= right)
		return;
	int keyi = left;
	//keyi = PartSort1(a, left, right);
	keyi = PartSort2(a, left, right);
	QuickSort(a, left, keyi - 1);
	QuickSort(a, keyi + 1, right);
}

// 快速排序 非递归实现
void QuickSortNonR(int* a, int left, int right);
