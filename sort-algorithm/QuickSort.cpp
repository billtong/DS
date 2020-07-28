#include "QuickSort.h"
#include "Tools.h"

void QuickSort::exec(int* arr, const int size)
{
	this->quick_sort_rec(arr, 0, size - 1);
}

/*
Quick Sorts
It's an improved version of Bubble Sort.
find the middlest element by two pointer search from the start and the end.
Example
200, 50, 212, 23, 43, 7, 1200, 50, 60, 2, 5, 3, 1
[0]200<->[12]1
1 50 212 23 43 7 1200 50 60 2 5 3 200
[10]1200<->[12]200
1 50 3 23 43 7 5 50 60 2 200 212 1200
[1]50<->[9]2
1 2 3 23 43 7 5 50 60 50 200 212 1200
[8]60<->[9]50
1 2 3 23 43 7 5 50 50 60 200 212 1200
[7]50<->[7]50
1 2 3 23 43 7 5 50 50 60 200 212 1200
[3]23<->[6]5
1 2 3 5 43 7 23 50 50 60 200 212 1200
[5]43<->[6]23
1 2 3 5 7 23 43 50 50 60 200 212 1200
1 2 3 5 7 23 43 50 50 60 200 212 1200
*/
void QuickSort::quick_sort_rec(int* arr, int left, int right)
{
	if (left < right)
	{
		Tools::swap(arr[find_pivot(arr, left, right)], arr[right]);
		int pivot = arr[right];
		int i = left;
		int j = right - 1;
		while (i < j)
		{
			/* works as well
			while (arr[i] <= pivot) i++;
			while (arr[j] >= pivot) j--;
			if (i < j)
				Tools::swap(arr[i++], arr[j--]);
			*/
			while (arr[i] < pivot) i++;
			while (arr[j] > pivot) j--;
			if (i <= j)
				Tools::swap(arr[i++], arr[j--]);
		}
		Tools::swap(arr[i], arr[right]);
		quick_sort_rec(arr, left, i - 1);
		quick_sort_rec(arr, i + 1, right);
	}
}

/*
get the most middle element in the left. right and middle element.
*/
int QuickSort::find_pivot(int* arr, int left, int right)
{
	int a = arr[left];
	int b = arr[(left + right) / 2];
	int c = arr[right];
	if ((a >= b && a <= c) || (a >= c && a <= b))
		return left;
	if ((b >= a && b <= c) || (b <= a && b >= c))
		return (left + right) / 2;
	if ((c >= a && c <= b) || (c <= a && c >= b))
		return right;
}

void QuickSort2::exec(int* arr, const int size)
{
	this->quick_sort_rec(arr, 0, size - 1);
}

/*
Quick Sort 2 from XingHua's data structure(JAVA)
No Pivot Finding version, choose left as default pivot
*/
void QuickSort2::quick_sort_rec(int* arr, int left, int right)
{
	if (left < right) // get out of infinity loop when finished
	{
		int i = left;
		int j = right;
		int pivot = arr[left];
		while (i < j)
		{
			while (arr[j] >= pivot && j > i)
				j--;
			if (i < j)
				arr[i++] = arr[j];
			while (arr[i] <= pivot && j > i)
				i++;
			if (i < j)
				arr[j--] = arr[i];
		}
		arr[i] = pivot;
		quick_sort_rec(arr, left, j - 1);
		quick_sort_rec(arr, j + 1, right);
	}
}
