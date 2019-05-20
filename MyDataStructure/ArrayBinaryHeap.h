/*
*作者Bill Tong
*说明一下，这个arraybinaryheap仅仅只实现了min heap
*因为maxheap大同小异就不浪费时间了
*/
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

/*从下到上调整minheap（用于insert和heapify）
比较index和parent，那个小，那个做parent
递归下去
*/
void minReheapUp(arraybinaryheap *heap, int index);

/*从上到下调整minheap（用于withdraw）
将最后一个值调到头一个后，调整整个heap
判断root，leftchild，rightchild是否存在
先从root，leftchild，rightchild的中找到最小的那个，将他作为swap的目标
如果这个目标在孩子节点中，就交换，然后递归继续循环
*/
void minReheapDown(arraybinaryheap *heap, int index);

/*删除heap的root值
将root和last交换，然后last--
调用reheapdown进行调整
*/
int withdrawMinHeap(arraybinaryheap *heap);

/*
用reheapup函数，从0开始一直调整到last
*/
arraybinaryheap *arrayMinHeapify(int a[], int size);

/*
交换数组里两个index的数值
*/
void swapArray(int *arr, int a, int b);

int *heapSort(int *arr, int size);

/*
打印出heap
*/
void printArrayBinaryHeap(arraybinaryheap *heap);

#endif // !ARRAYBINARYHEAP_H
#pragma once
