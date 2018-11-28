#include "Sorts.h"
#include <stdio.h>
#include <stdlib.h>

void printArray(int *arr, int size)
{
	for (int i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void initArray(int* a) {
	a[0] = 10;
	a[1] = 24;
	a[2] = 5;
	a[3] = 32;
	a[4] = 1;
	a[5] = 84;
	a[6] = 19;
}

int main() {
	
	int a[] = { 10, 24, 5, 32, 1, 84, 19 };
	int n = 7;
	long	swaps = 0;

	printf("Before   Sorting:\t");
	printArray(a, n);
	printf("*****\n");

	initArray(a);
	printf("selection sort result:\n");
	selectionSorts(a, n);
	printArray(a,n);

	initArray(a);
	printf("linear insertion sort result:\n");
	linearInsertionSorts(a, n);
	printArray(a, n);

	initArray(a);
	printf("binary insertion sort result:\n");
	binaryInsertionSorts(a, n);
	printArray(a,n);

	initArray(a);
	printf("bubble sort result:\n");
	bubbleSorts(a, n);
	printArray(a, n);

	int test[] = {200, 50, 212, 23, 43, 7, 1200, 50, 60, 2, 5, 3, 1};//s13
	printf("quick sort result:\n");
	quickSorts(test, 0, 12);
	printArray(test, 13);

	int test2[] = { 200, 50, 212, 23, 43, 7, 1200, 50, 60, 2, 5, 3, 1 };//s13
	printf("merge sort result:\n");
	mergeSort(test2, 13);
	printArray(test2, 13);


	int test3[] = { 3, 1, 2, 2, 5, 9, 2, 4, 4, 1, 6, 9, 0, 1, 2 };
	printf("bucket sort result:\n");
	//bucketSort(test3, 15, 10);
	printArray(test3, 15);

	int test4[] = {629, 202, 40, 593, 2, 131, 34, 23,13, 1, 12, 23, 43, 53, 90 };
	radixSort(test4, 15, 3);
	printf("radix sort result:\n");
	printArray(test4, 15);

	system("pause");
	return 0;
}

