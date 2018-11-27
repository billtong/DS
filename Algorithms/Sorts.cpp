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

void bubbleSorts(int * arr, int size)
{
	for (int i = size-1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (arr[j] > arr[j + 1]) {
				swap(&arr[j], &arr[j + 1]);
			}
		}
	}

}

void print(int *arr, int n) {
	for (int i = 0; i < n; i++) {
		//if (i >= left && i <= right) {
			printf("%d ", arr[i]);
		//}
		//else {
		//	printf("  ");
		//}
	}
	printf("\n");
}

void quickSorts(int * arr, int left, int right)
{

	if (right - left >=2) {
	
		int pivot = arr[right];
		int i = left;
		int j = right-1;
		while (i < j) {
			while (arr[i] < pivot) i++;
			while (arr[j] > pivot) j--;
			//这里的等号用来处理当被交换的项相同时，将把他插在后面
			if (i <= j)
				swap(&arr[i++], &arr[j--]);


		}
		
		swap(&arr[i], &arr[right]);
		
		quickSorts(arr, left, i - 1);
		quickSorts(arr, i + 1, right);
	}
}



