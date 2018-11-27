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

//�����һ��ֵ����ͷһ���󣬵�������heap
//�ж�root��leftchild��rightchild�Ƿ����
//�ȴ�root��leftchild��rightchild�����ҵ���С���Ǹ���������Ϊswap��Ŀ��
//������Ŀ���ں��ӽڵ��У��ͽ�����Ȼ��ݹ����ѭ��
void minReheapDown(arraybinaryheap *heap, int index);


int withdrawMinHeap(arraybinaryheap *heap);


arraybinaryheap *arrayMinHeapify(int a[], int size);

void swapArray(int *arr, int a, int b);

void printArrayBinaryHeap(arraybinaryheap *heap);

#endif // !ARRAYBINARYHEAP_H
#pragma once
