/*
*����Bill Tong
*˵��һ�£����arraybinaryheap����ֻʵ����min heap
*��Ϊmaxheap��ͬС��Ͳ��˷�ʱ����
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

/*���µ��ϵ���minheap������insert��heapify��
�Ƚ�index��parent���Ǹ�С���Ǹ���parent
�ݹ���ȥ
*/
void minReheapUp(arraybinaryheap *heap, int index);

/*���ϵ��µ���minheap������withdraw��
�����һ��ֵ����ͷһ���󣬵�������heap
�ж�root��leftchild��rightchild�Ƿ����
�ȴ�root��leftchild��rightchild�����ҵ���С���Ǹ���������Ϊswap��Ŀ��
������Ŀ���ں��ӽڵ��У��ͽ�����Ȼ��ݹ����ѭ��
*/
void minReheapDown(arraybinaryheap *heap, int index);

/*ɾ��heap��rootֵ
��root��last������Ȼ��last--
����reheapdown���е���
*/
int withdrawMinHeap(arraybinaryheap *heap);

/*
��reheapup��������0��ʼһֱ������last
*/
arraybinaryheap *arrayMinHeapify(int a[], int size);

/*
��������������index����ֵ
*/
void swapArray(int *arr, int a, int b);

int *heapSort(int *arr, int size);

/*
��ӡ��heap
*/
void printArrayBinaryHeap(arraybinaryheap *heap);

#endif // !ARRAYBINARYHEAP_H
#pragma once
