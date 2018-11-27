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


void linearInsertionSorts(int * arr, int size)
{
	
	for (int i = 1; i < size; i++) {
		for (int j = i; j > 0 && arr[j] < arr[j-1]; j--) {
			swap(&arr[j], &arr[j-1]);
		}
	}
	
}

void binaryInsertionSorts(int * arr, int size)
{
	for (int i = 1; i < size; i++) {
	
		int left = 0;
		int right = i;
		int taget = arr[i];

		while (left < right) {
			int mid = (left + right) / 2;
			if (taget >= arr[mid]) {
				left = mid + 1;
			}
			else {
				right = mid;
			}
		}

		for (int j = i; j > right; j--) {
			swap(&arr[j], &arr[j-1]);
		}
	
	}
}



