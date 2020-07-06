#ifndef SORTS_H

void selectionSorts(int* arr, int size);

void linearInsertionSorts(int* arr, int size);

void linearInsertionSorts2(int* arr, int size);

void binaryInsertionSorts(int* arr, int size);

void bubbleSorts(int* arr, int size);

void quickSorts(int* arr, int left, int right);
int findPivot(int* arr, int left, int right);

void quickSorts2(int* arr, int left, int right);

void mergeSort(int* arr, int n);
void mergeSortRec(int* a, int start, int end, int* b);
void merge(int* a, int start, int middle, int end, int* b);

void bucketSort(int* a, int size, int bucketSize);

void radixSort(int* a, int size, int p);

#endif // !SORTS_H

