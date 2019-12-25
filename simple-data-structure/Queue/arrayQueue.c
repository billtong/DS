#include "arrayQueue.h"

pArrayQueue createArrayQueue()
{
	pArrayQueue pQueue = createArrayList();
	return pQueue;
}

int isArrayQueueEmpty(pArrayQueue pQueue)
{
	return pQueue->used == 0;
}

void enArrayQueue(pArrayQueue pQueue, int elem)
{
	insertArrayList(pQueue, elem, pQueue->used);
}

int deArrayQueue(pArrayQueue pQueue)
{
	if (!isArrayQueueEmpty(pQueue))
	{
		int data = pQueue->arr[0];
		removeIndexOfArrayList(pQueue, 0);
		return data;
	}
	return INT_MIN;
}

void destroyArrayQueue(pArrayQueue pQueue)
{
	destroyArrayList(pQueue);
}

void traverseArrayQueue(pArrayQueue pQueue)
{
	traverseArrayList(pQueue);
}