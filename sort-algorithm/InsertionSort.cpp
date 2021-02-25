#include "InsertionSort.h"
#include "Tools.h"

/*
Linear Insertion Sort (Queen's U)
start from the second element put it in the correct position at the front part of the array
using linear search to find the correct position O(n)
Example
start:10 24 5 32 1 84 19
#1:(10) 24 5 32 1 84 19
#2:(5 10) 24 32 1 84 19
#3:(5 10 24) 32 1 84 19
#4:(1 5 10 24 32) 84 19
#5:(1 5 10 24 32 84) 19
end:(1 5 10 19 24 32 84
*/
void LinearInsertionSort::exec(int *arr, const int size)
{
	for (int i = 1; i < size; i++)
	{
		for (int j = i; j > 0 && arr[j] < arr[j - 1]; j--)
			Tools::swap(arr[j], arr[j - 1]);
	}
}

/*
Linear Insertion Sort(Intro to Algo.)
*/
void LinearInsertionSort2::exec(int *arr, const int size)
{
	for (int i = 1; i < size; i++)
	{
		int key = arr[i];
		int j = i - 1;
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
}

/*
the same method as Linear Insertion,
only using binary search when find the position O(ln(n))
*/
void BinaryInsertionSort::exec(int *arr, const int size)
{
	for (int i = 1; i < size; i++)
	{
		int left = 0;
		int right = i;
		int taget = arr[i];
		while (left < right)
		{
			int mid = (left + right) / 2;
			if (taget >= arr[mid])
				left = mid + 1;
			else
				right = mid;
		}
		for (int j = i; j > right; j--)
			Tools::swap(arr[j], arr[j - 1]);
	}
}
