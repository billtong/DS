#include "MergeSort.h"
#include <stdlib.h>

/*
Merge Sort
This function uses the "mergeSortRec()"
for simplify purpose, wear a little less parameters
*/
void MergeSort::exec(int *arr, const int size)
{
	int *b = (int *)malloc(sizeof(int) * size);
	merge_sort_rec(arr, 0, size - 1, b);
}

/*
merge recursion
Get middle
Then divide the function into two parts and sort them separately,
Finally integrate them together
*/
void MergeSort::merge_sort_rec(int *a, int start, int end, int *b)
{
	if (start < end)
	{
		int middle = (start + end) / 2;
		merge_sort_rec(a, start, middle, b);
		merge_sort_rec(a, middle + 1, end, b);
		merge(a, start, middle, end, b);
	}
}

/*
The core of sorting during merge
1. Define two variables j and k
2. j starts traversing from start, k starts traversing from middle plus 1
The smaller one is assigned to the b array first, and the smaller index is moved forward by one
Wait for one of j or k to go to the entire interval
3. The remaining elements in Array (middle left section or right section) have not been traversed
All are assigned to b in order
4. Assign sorted b to a
*/
void MergeSort::merge(int *a, int start, int middle, int end, int *b)
{
	int i, j, k;
	for (i = start, j = start, k = middle + 1; j <= middle && k <= end; i++)
		b[i] = a[j] < a[k] ? a[j++] : a[k++];
	while (j <= middle)
		b[i++] = a[j++];
	while (k <= end)
		b[i++] = a[k++];
	for (i = start; i <= end; i++)
		a[i] = b[i];
}
