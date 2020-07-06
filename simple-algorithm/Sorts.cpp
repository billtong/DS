#include "Sorts.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void print(int* arr, int n)
{
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

/*
Selection Sort
find the smallest element and put it at the 1st place
find the second smallest element and put it at the 2nd place
continue the procedure until the second last one
Example, element inside the brace is the "smallest element" each turn
start：10 24 5 32 1 84 19
#1：(1) 24 5 32 10 84 19
#2：1 (5) 24 32 10 84 19
#3：1 5 (10) 32 24 84 19
#4：1 5 10 (19) 24 84 32
#5：1 5 10 19 (24) 84 32
end：1 5 10 19 24 (32) 84
*/
void selectionSorts(int* arr, int size)
{

	for (int i = 0; i < size - 1; i++)
	{
		int selectIndex = i;
		for (int j = i + 1; j < size; j++)
		{
			if (arr[selectIndex] > arr[j])
				selectIndex = j;
		}
		swap(&arr[i], &arr[selectIndex]);
	}
}

/*
Linear Insertion Sort (Queen's U)
start from the second element put it in the correct position at the front part of the array
using linear search to find the correct position O(n)
Example
start：10 24 5 32 1 84 19
#1：(10) 24 5 32 1 84 19
#2：(5 10) 24 32 1 84 19
#3：(5 10 24) 32 1 84 19
#4：(1 5 10 24 32) 84 19
#5：(1 5 10 24 32 84) 19
end：(1 5 10 19 24 32 84
*/
void linearInsertionSorts(int* arr, int size)
{

	for (int i = 1; i < size; i++)
	{
		for (int j = i; j > 0 && arr[j] < arr[j - 1]; j--)
			swap(&arr[j], &arr[j - 1]);
	}

}

/*
Linear Insertion Sort(Intro to Algo.)
*/
void linearInsertionSorts2(int* arr, int size)
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
void binaryInsertionSorts(int* arr, int size)
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
			swap(&arr[j], &arr[j - 1]);

	}
}

/*
Bubble Sort
begin From the first element, compare it with the next element
make sure the larger one moves toward the back
until we find the largest one and put it at the last position
we loop this procedure n-1 times.
*/
void bubbleSorts(int* arr, int size)
{
	for (int i = size - 1; i > 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (arr[j] > arr[j + 1])
				swap(&arr[j], &arr[j + 1]);
		}
	}

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
void quickSorts(int* arr, int left, int right)
{
	if (left < right)
	{
		swap(&arr[findPivot(arr, left, right)], &arr[right]);
		int pivot = arr[right];
		int i = left;
		int j = right - 1;
		while (i < j)
		{
			/* works as well
			while (arr[i] <= pivot) i++;
			while (arr[j] >= pivot) j--;
			if (i < j)
				swap(&arr[i++], &arr[j--]);
			*/
			while (arr[i] < pivot) i++;
			while (arr[j] > pivot) j--;
			if (i <= j)
				swap(&arr[i++], &arr[j--]);
		}
		swap(&arr[i], &arr[right]);
		quickSorts(arr, left, i - 1);
		quickSorts(arr, i + 1, right);
	}
}

/*
get the most middle element in the left. right and middle element.
*/
int findPivot(int* arr, int left, int right) {
	int a = arr[left];
	int b = arr[(left + right) / 2];
	int c = arr[right];
	if ((a >= b && a <= c) || (a >= c && a <= b))
		return left;
	if ((b >= a && b <= c) || (b <= a && b >= c))
		return (left + right) / 2;
	if ((c >= a && c <= b) || (c <= a && c >= b))
		return right;
	return NULL;	/* should never be reached */
}

/*
Quick Sort 2 from XingHua's data structure(JAVA)
No Pivot Finding version, choose left as default pivot
*/
void quickSorts2(int* arr, int left, int right)
{
	if (left < right)
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
		quickSorts2(arr, left, j - 1);
		quickSorts2(arr, j + 1, right);
	}
}

/*
Merge Sort
This function uses the "mergeSortRec()"
for simplify purpose, wear a little less parameters
*/
void mergeSort(int* arr, int n)
{
	int* b = (int*)malloc(sizeof(int) * n);
	mergeSortRec(arr, 0, n - 1, b);
}

/*
merge recursion
Get middle
Then divide the function into two parts and sort them separately,
Finally integrate them together
*/
void mergeSortRec(int* a, int start, int end, int* b)
{
	if (start < end)
	{
		int middle = (start + end) / 2;
		mergeSortRec(a, start, middle, b);
		mergeSortRec(a, middle + 1, end, b);
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
void merge(int* a, int start, int middle, int end, int* b)
{
	int i, j, k;
	for (i = start, j = start, k = middle + 1; j <= middle && k <= end; i++)
		b[i] = a[j] < a[k] ? a[j++] : a[k++];
	while (j <= middle) b[i++] = a[j++];
	while (k <= end) b[i++] = a[k++];
	for (i = start; i <= end; i++)
		a[i] = b[i];
}

/*
bucketSize needs to be the maximum value of the array
In order from small to large, count the number of each element,
Then take them all out and sort them
*/
void bucketSort(int* a, int size, int bucketSize)
{
	int* buckets = (int*)malloc(sizeof(int) * bucketSize);
	for (int i = 0; i < bucketSize; i++)
		buckets[i] = 0;
	for (int i = 0; i < size; i++)
		buckets[a[i]]++;
	for (int i = 0, j = 0; j < bucketSize; j++) 
	{
		int k = buckets[j];
		while (k > 0) 
		{
			a[i++] = j;
			k--;
		}
	}
}

/*
Radix sorting is an improved version of bucketsort
bucketsize (0, 10^p)
sort Once place, then Tence place, and then Hundreds place...
In each cycle
1. After each number hashes (to get a quotient), use bucket sort; (count value assignment)
2. Calculate the sequence of each place value position according to the value of count of previous place (offset value assignment)
3. take out the value according to the situation of offset (temp value assignment)
4. arr=temp
*/
void radixSort(int* a, int size, int p)
{
	for (int k = 0; k < p; k++)	//base 10 is used
	{
		int count[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
		int* tmp = (int*)malloc(sizeof(int) * size);
		int* offset = (int*)malloc(sizeof(int) * 10);
		for (int i = 0; i < size; i++)
			count[(a[i] / (int)pow(10, k)) % 10]++;
		offset[0] = 0;
		for (int i = 1; i < 10; i++)
		{
			offset[i] = 0;
			for (int j = 0; j < i; j++)
				offset[i] += count[j];
		}
		for (int i = 0; i < size; i++)
			tmp[offset[(a[i] / (int)pow(10, k)) % 10]++] = a[i];	//look! here add one after place a value in the tmp array
		for (int i = 0; i < size; i++)
			a[i] = tmp[i];
	}
}
