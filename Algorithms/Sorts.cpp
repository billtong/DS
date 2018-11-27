#include "Sorts.h"
#include <stdio.h>

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}




void selectionSorts(int * arr, int size)
{
	
	for (int i = 0; i < size - 1; i++) {
		int selectIndex = i;		
		
		for (int j = i + 1; j < size; j++) {
			if (arr[selectIndex] > arr[j]) {
				selectIndex = j;
			}
		}
		swap(&arr[i], &arr[selectIndex]);
	}
}


void insertionSorts(int * arr, int size)
{
	
	for (int i = 1; i < size; i++) {
		for (int j = i; j > 0 && arr[j] < arr[j-1]; j--) {
			swap(&arr[j], &arr[j-1]);
		}
	}
	
}



