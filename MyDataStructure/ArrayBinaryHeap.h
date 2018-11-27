#ifndef ARRAYBINARYHEAP_H
#define ARRAYBINARYHEAP_H


#define LeftChild(i) ((2 * i) + 1)
#define RightChild(i) ((2*i) + 2)
#define Parent(i) ((i-1)/2)


typedef struct _ArrayBinaryHeap
{
	int *a;
	int last;		//this in the last index of the array, starts from 0
	int maxSize;
} arraybinaryheap;

arraybinaryheap *initArrayBinaryHeap(int maxSize);

void minReheapUp(arraybinaryheap *heap, int index);

//将最后一个值调到头一个后，调整整个heap
//判断root，leftchild，rightchild是否存在
//先从root，leftchild，rightchild的中找到最小的那个，将他作为swap的目标
//如果这个目标在孩子节点中，就交换，然后递归继续循环
void minReheapDown(arraybinaryheap *heap, int index);


int withdrawMinHeap(arraybinaryheap *heap);


arraybinaryheap *arrayMinHeapify(int a[], int size);

void swapArray(int *arr, int a, int b);

void printArrayBinaryHeap(arraybinaryheap *heap);

#endif // !ARRAYBINARYHEAP_H
#pragma once
