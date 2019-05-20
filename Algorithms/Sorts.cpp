#include "Sorts.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
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

void quickSorts(int * arr, int left, int right)
{

	if (right - left >=2) {
	
		swap(&arr[findPivot(arr, left, right)], &arr[right]);
		int pivot = arr[right];
		int i = left;
		int j = right-1;
		while (i < j) {
			while (arr[i] < pivot) i++;
			while (arr[j] > pivot) j--;
			
			//这里很妙
			//这里的等号用来处理当被交换的项相同时，依然让i++
			//这样能够将right和靠右一些的一项交换，保证哪一项依然比right要大

			if (i <= j)
				swap(&arr[i++], &arr[j--]);
		}
		
		swap(&arr[i], &arr[right]);
		
		quickSorts(arr, left, i - 1);
		quickSorts(arr, i + 1, right);
	}
}

int findPivot(int *arr,int left, int right) {
	int a = arr[left];
	int b = arr[(left+right)/2];
	int c = arr[right];
	
	if ((a >= b && a <= c) || (a >= c && a <= b)) {
		return left;
	}

	if ((b >= a && b <= c) || (b<=a && b>=c)) {
		return (left+right)/2;
	}

	if ((c >= a && c <= b) || (c<=a && c>=b)) {
		return right;
	}
	
}


void mergeSort(int * arr, int n)
{
	int *b = (int *)malloc(sizeof(int)*n);
	mergeSortRec(arr, 0, n-1, b);
}

void mergeSortRec(int *a, int start, int end, int* b) 
{
	if (start >= end) {
		return;
	}
	int middle = (start + end) / 2;
	mergeSortRec(a, start, middle, b);
	mergeSortRec(a,middle+1, end, b);
	merge(a, start, middle, end, b);
}


void merge(int *a, int start, int middle, int end, int *b) 
{
	int i, j, k;
	for(i = start, j = start, k = middle + 1; j <= middle && k <= end; i++) {
		if (a[j] < a[k]) {
			b[i] = a[j++];
		}
		else {
			b[i] = a[k++];
		}
	}

	while (j <= middle) {
		b[i++] = a[j++];
	}

	while (k <= end) {
		b[i++] = a[k++];
	}

	for (i = start; i <= end; i++) {
		a[i] = b[i];
	}

}

void bucketSort(int * a, int size, int bucketSize)
{
	int *buckets = (int *)malloc(sizeof(int) * bucketSize);

	for (int i = 0; i < bucketSize; i++) {
		buckets[i] = 0;
		
	}

	for (int i = 0; i < size; i++) {
		buckets[a[i]]++;
	}
	
	for (int i = 0, j = 0; j < size; j++) {
		int k = buckets[j];
		while (k > 0) {
			a[i++] = j;
			k--;
		}
	}


}

void radixSort(int * a, int size, int p)
{
	//base 10 is used
	for (int k = 0; k < p; k++) {
	
		int count[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
		int *tmp = (int *)malloc(sizeof(int) * size);
		int *offset = (int *)malloc(sizeof(int) * 10);
		for (int i = 0; i < size; i++) {
			count[(a[i] / (int)pow(10, k)) % 10]++;
		}

		
		offset[0] = 0;
		for (int i = 1; i < 10; i++) 
		{
			offset[i] = 0;
			for (int j = 0; j < i; j++) 
			{
				offset[i] += count[j];
			}
		}


		for (int i = 0; i < size; i++) 
		{
			tmp[offset[(a[i] / (int)pow(10, k)) % 10]++] = a[i];
		}
		

		for (int i = 0; i < size; i++) 
		{
			a[i] = tmp[i];
		}
	}


}
