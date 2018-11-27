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

	printf("Before   Sorting:\t\t");
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


	system("pause");
	return 0;
}

