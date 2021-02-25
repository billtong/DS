#include "binaryHeap.h"

BinaryHeap *createBinaryHeap(int capacity)
{
	BinaryHeap *pHeap = (BinaryHeap *)malloc(sizeof(BinaryHeap));
	if (pHeap == NULL)
		return NULL;
	pHeap->arr = (int *)malloc(sizeof(int) * capacity);
	pHeap->last = -1;
	pHeap->capacity = capacity;
	return pHeap;
}

BinaryHeap *createBinaryHeapFromArray(int *a, int size)
{
	BinaryHeap *heap = createBinaryHeap(size);
	heap->last = 0;
	heap->capacity = size;
	heap->arr = a;
	for (heap->last = 0; heap->last < size; heap->last++)
		minReheapUp(heap, heap->last);
	heap->last--;
	return heap;
}

void minReheapUp(BinaryHeap *heap, int index)
{
	int parentIndex = Parent(index);
	if (heap->arr[index] < heap->arr[parentIndex])
	{
		swapElementsInArray(heap->arr, parentIndex, index);
		minReheapUp(heap, parentIndex);
	}
}

void minReheapDown(BinaryHeap *heap, int index)
{
	int leftChildIndex = LeftChild(index);
	if (index >= heap->last || leftChildIndex > heap->last)
		return;
	int rightChildIndex = RightChild(index);
	int item = heap->arr[index];
	int lchild = heap->arr[leftChildIndex];
	int rchild = heap->arr[rightChildIndex];
	if (item < lchild && item < rchild)
		return;
	int targetIndex = lchild <= rchild ? leftChildIndex : rightChildIndex;
	swapElementsInArray(heap->arr, index, targetIndex);
	minReheapDown(heap, targetIndex);
}

int withdrawMinHeap(BinaryHeap *heap)
{
	int min = heap->arr[0];
	heap->arr[0] = heap->arr[heap->last];
	heap->last--;
	minReheapDown(heap, 0);
	return min;
}

void printArrayBinaryHeap(BinaryHeap *heap)
{
	printf("heap:[ ");
	if (heap == NULL || heap->arr == NULL)
		printf("empty");
	else
	{
		for (int i = 0; i <= heap->last; i++)
			printf("%d ", heap->arr[i]);
	}
	printf("]\n");
}

int *heapSort(int *arr, int size)
{
	BinaryHeap *heap = createBinaryHeapFromArray(arr, size);
	int *b = (int *)malloc(sizeof(int) * size);
	for (int i = 0; i < size; i++)
		b[i] = withdrawMinHeap(heap);
	return b;
}
