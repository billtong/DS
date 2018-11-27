#ifndef ARRAYBINARYHEAP_H
#define ARRAYBINARYHEAP_H


#define LeftChild(i) ((2 * i) + 1)
#define RightChild(i) ((2*i) + 1)
#define Parent(i) ((i-1)/2)


typedef struct _ArrayBinaryHeap
{
	int *a;
	int last;
	int maxSize;
} arraybinaryheap;

arraybinaryheap *initArrayBinaryHeap(int maxSize);

void minReheapUp(arraybinaryheap *heap, int index);
void minReheapDown(arraybinaryheap *heap, int index);

arraybinaryheap *minArrayBinaryHeapify(int a[], int size);

void swapArray(int *arr, int a, int b);

void printArrayBinaryHeap(arraybinaryheap *heap);

#endif // !ARRAYBINARYHEAP_H
#pragma once
