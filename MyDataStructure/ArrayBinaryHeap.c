#include"ZHeader.h"

arraybinaryheap * initArrayBinaryHeap(int maxSize)
{
	arraybinaryheap *bh = (arraybinaryheap *)malloc(sizeof(arraybinaryheap));
	bh->a = (int *)malloc(sizeof(int) * maxSize);
	bh->last = -1;
	bh->maxSize = maxSize;
	return bh;
}

void minReheapUp(arraybinaryheap * heap, int index)
{
	if (index <= 0)
		return;
	else {
		int parentIndex = Parent(index);
		if (heap->a[index] < heap->a[parentIndex]) {
			swapArray(heap->a, parentIndex, index);
		}
		else {
			return;
		}
		minReheapUp(heap, parentIndex);
	}
}

void minReheapDown(arraybinaryheap * heap, int index)
{
	int leftChildIndex = LeftChild(index);
	int rightChildIndex = RightChild(index);
	if (index >= heap->last || leftChildIndex > heap->last) {
		return;
	}
	int item = heap->a[index], lchild = heap->a[leftChildIndex], rchild = heap->a[rightChildIndex];
	int targetIndex = index;
	if (item < lchild && item < rchild) {
		return;
	}
	if (lchild < rchild) {
		swapArray(heap->a, index, leftChildIndex);
		targetIndex = leftChildIndex;
	}
	else if (lchild > rchild) {
		swapArray(heap->a, index, rightChildIndex);
		targetIndex = rightChildIndex;
	}
	if (targetIndex != index) {
		minReheapDown(heap, targetIndex);
	}
}



int withdrawMinHeap(arraybinaryheap *heap)
{
	if (heap == NULL || heap->a == NULL) {
		printf("the min heap is empty\n");
		return 0;
	}
	int min = heap->a[0];
	heap->a[0] = heap->a[heap->last];
	heap->last--;
	minReheapDown(heap, 0);
	return min;
}



arraybinaryheap * arrayMinHeapify(int a[], int size)
{
	arraybinaryheap *heap = initArrayBinaryHeap(size);
	heap->last = 0;
	heap->maxSize = size;
	heap->a = a;
	for (int i = 0; i < size; i++) {
		minReheapUp(heap, heap->last);
		heap->last++;
	}
	heap->last--;
	return heap;
}

void printArrayBinaryHeap(arraybinaryheap * heap)
{
	if (heap == NULL || heap->a ==NULL) {
		printf("empty heap\n");
	}
	else {
		printf("heap:[ ");
		for (int i = 0; i <= heap->last; i++) {
			printf("%d ", heap->a[i]);
		}
		printf("]\n");
	}
}



void swapArray(int *arr, int a, int b)
{
	int t = arr[a];
	arr[a] = arr[b];
	arr[b] = t;
}

int *heapSort(int * arr, int size)
{
	arraybinaryheap *heap = arrayMinHeapify(arr, size);
	int *b = (int *)malloc(sizeof(int)*size);
	for (int i = 0; i < size; i++) {
		b[i] = withdrawMinHeap(heap);
	}
	return b;
}
