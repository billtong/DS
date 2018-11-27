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

arraybinaryheap * minArrayBinaryHeapify(int a[], int size)
{
	arraybinaryheap *heap = initArrayBinaryHeap(size);
	heap->last = 0;
	heap->maxSize = size;

	heap->a = a;

	for (int i = 0; i < size; i++) {
		minReheapUp(heap, heap->last);
		heap->last++;
	}
	return heap;

}

void printArrayBinaryHeap(arraybinaryheap * heap)
{
	if (heap == nullptr || heap->a == nullptr) {
		printf("empty heap\n");
	}
	else {
		printf("heap:[ ");
		for (int i = 0; i < heap->last; i++) {
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
