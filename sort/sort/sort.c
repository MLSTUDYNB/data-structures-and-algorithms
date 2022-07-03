#define _CRT_SECURE_NO_WARNINGS 1

#include "sort.h"
#include "stack.h"
#include "queue.h"

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
// ��������ݹ�ʵ��
// ��������hoare�汾
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
// ���������ڿӷ�
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
// ��������ǰ��ָ�뷨
int PartSort3(int* a, int left, int right)
{
	int keyi = left;
	int front = keyi + 1;
	int back = keyi;
	while (front <= right)
	{
		if (a[front] <= a[keyi])
		{
			back++;
			swap(&a[front], &a[back]);
		}
		front++;
	}
	swap(&a[back], &a[keyi]);
	keyi = back;
	return keyi;
}

int ThreeIn(int* a, int left, int right)
{
	int middle = left + (right - left) / 2;
	if (a[middle] < a[left])
	{
		if (a[left] < a[right])
			return left;
		else if (a[middle] < a[right])
			return right;
		else
			return middle;
	}
	else
	{
		if (a[middle] < a[right])
			return middle;
		else if (a[left] < a[right])
			return right;
		else
			return left;
	}
}
void QuickSort(int* a, int left, int right)
{
	if (left >= right)
		return;
	int keyi = left;
	int x = ThreeIn(a, left, right);
	swap(&a[keyi], &a[x]);
	//keyi = PartSort1(a, left, right);
	//keyi = PartSort2(a, left, right);
	keyi = PartSort3(a, left, right);
	QuickSort(a, left, keyi - 1);
	QuickSort(a, keyi + 1, right);
}

// �������� �ǵݹ�ʵ��
void QuickSortNonR1(int* a, int left, int right)
{

	Stack p;
	InitStack(&p);
	StackPush(&p, left);
	StackPush(&p, right);
	while (!StackEmpty(&p))
	{
		right = StackTop(&p);
		StackPop(&p);
		left = StackTop(&p);
		StackPop(&p);
		int keyi = PartSort3(a, left, right);
		if (keyi + 1 < right)
		{
			StackPush(&p, keyi+1);
			StackPush(&p, right);
		}
		if (keyi - 1 > left)
		{
			StackPush(&p, left);
			StackPush(&p, keyi-1);
		}
	}
	StackDestroy(&p);
}

void QuickSortNonR2(int* a, int left, int right)
{
	Queue p;
	QueueInit(&p);
	QueuePush(&p, right);
	QueuePush(&p, left);
	while (!QueueEmpty(&p))
	{
		right = QueueFront(&p);
		QueuePop(&p);
		left= QueueFront(&p);
		QueuePop(&p);
		int keyi = PartSort3(a, left, right);
		
		if (keyi - 1 > left)
		{
			
			QueuePush(&p, keyi - 1);
			QueuePush(&p, left);
		}
		if (keyi + 1 < right)
		{
			
			QueuePush(&p, right);
			QueuePush(&p, keyi + 1);
		}
	}
	QueueDestroy(&p);

}

void merge_sort(int* a, int* temp, int left,int right)
{
	//���Ʒ��ص�����
	if (left >= right)
		return;
	int mid = left + (right - left) / 2;
	//���Ϸָ�����left,mid],[mid+1,right]

	merge_sort(a, temp, left, mid);
	merge_sort(a, temp, mid+1, right);

	int L1 = left, R1 = mid;
	int L2 = mid+1, R2 = right;
	int i = L1;
	while (L1 <= R1 && L2 <= R2)
	{
		if (a[L1] <= a[L2])
			temp[i++] = a[L1++];
		else
			temp[i++] = a[L2++];
	}
	while (L1 <= R1)
		temp[i++] = a[L1++];
	while (L2 <= R2)
		temp[i++] = a[L2++];
	memcpy(a+left, temp+left, sizeof(int) * (right - left+1));
}

void MergeSort(int* a, int n)
{
	int* temp = (int*)malloc(sizeof(int) * n);

	merge_sort(a, temp, 0,n-1);


	free(temp);
}

void MergeSortNonR(int* a, int n)
{
	int* temp = (int*)malloc(sizeof(int) * n);
	if (temp == NULL)
		exit(-1);
	int gap = 1;

	while (gap < n)
	{
		int left1 = 0;
		while (left1<n)
		{
			int right2 = left1 + 2*gap-1;
			int mid = (left1 + right2) / 2;
			int right1 = mid, left2 = mid + 1;
			int i = left1; int x = left1;
			if (right1 >= n)
			{
				right1 = n - 1;
				left2 = n;
				right2 = n-1;
			}
			else if (left2 >= n)
			{
				left2 = n;
				right2 = n-1;
			}
			else if (right2 >= n)
			{
				right2 = n - 1;
			}
			while (left1 <= right1 && left2 <= right2)
			{
				if (a[left1] <= a[left2])
					temp[i++] = a[left1++];
				else
					temp[i++] = a[left2++];
			}
			while (left1 <= right1)
				temp[i++] = a[left1++];
			while (left2 <= right2)
				temp[i++] = a[left2++];

			memcpy(a + x, temp + x, sizeof(int) * (right2 - x + 1));
			left1 = right2 + 1;
		}
		gap *= 2;
	}
	free(temp);
}

void CountSort(int* a, int n)
{
	int min = a[0], max = a[0];
	for (int i = 0; i < n; i++)
	{
		if (min > a[i])
			min = a[i];
		if (max < a[i])
			max = a[i];
	}
	int range = max - min+1;
	int* temp = calloc(range, sizeof(int));
	for (int i = 0; i < n; i++)
	{
		temp[a[i] - min]++;
	}
	for (int i = 0,j=0; i < range; i++)
	{
		while (temp[i]--)
			a[j++] = i + min;
	}
}