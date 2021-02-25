/*
here only min heap has been implemented,
the max heap has similar algorithms, which
is a waste of time to code
*/
#pragma once
#include "../stdafx.h"

#define LeftChild(i) ((2 * i) + 1)
#define RightChild(i) ((2 * i) + 2)
#define Parent(i) ((i - 1) / 2)

typedef struct
{
	int *arr;
	int last; //this in the last index of the array, starts from 0
	int capacity;
} BinaryHeap;

BinaryHeap *createBinaryHeap(int);
BinaryHeap *createBinaryHeapFromArray(int *a, int size);

void minReheapUp(BinaryHeap *heap, int index);

void minReheapDown(BinaryHeap *heap, int index);

/*
withdraw the root element of the heap structure
*/
int withdrawMinHeap(BinaryHeap *heap);

int *heapSort(int *arr, int size);

void printArrayBinaryHeap(BinaryHeap *heap);
