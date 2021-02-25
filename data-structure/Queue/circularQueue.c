#include "circularQueue.h"

CircularQueue *createCircularQueue(int cap)
{
	CircularQueue *pQueue = (CircularQueue *)malloc(sizeof(CircularQueue));
	if (pQueue == NULL)
		return NULL;
	pQueue->arr = (int *)malloc(sizeof(int) * cap);
	pQueue->front = pQueue->rear = -1;
	pQueue->size = 0;
	pQueue->capacity = cap;
}

int isCircularQueueEmpty(CircularQueue *pQueue)
{
	return pQueue->size == 0;
}

int isCircularQueueFull(CircularQueue *pQueue)
{
	return pQueue->capacity == pQueue->size;
}

void enCircularQueue(CircularQueue *pQueue, int elem)
{
	if (!isCircularQueueFull(pQueue))
	{
		pQueue->rear = (pQueue->rear + 1) % pQueue->capacity;
		pQueue->arr[pQueue->rear] = elem;
		pQueue->size++;
		if (pQueue->front == -1)
			pQueue->front = pQueue->rear;
	}
}

int deCircularQueue(CircularQueue *pQueue)
{
	if (!isCircularQueueEmpty(pQueue))
	{
		int data = pQueue->arr[pQueue->front];
		pQueue->front = (pQueue->front + 1) % pQueue->capacity;
		pQueue->size--;
		if (isCircularQueueEmpty(pQueue))
			pQueue->front = pQueue->rear = -1;
		return data;
	}
}

void traverseCircularQueue(CircularQueue *pQueue)
{
	printf("circular queue:\t");
	if (isCircularQueueEmpty(pQueue))
		printf("empty\n");
	else if (pQueue->size == 1)
		printf("%d\n", pQueue->arr[pQueue->front]);
	else
	{
		int iter = pQueue->front;
		while (iter != pQueue->rear)
		{
			printf("%d\t", pQueue->arr[iter]);
			iter = (iter + 1) % pQueue->capacity;
		}
		printf("%d\n", pQueue->arr[pQueue->rear]);
	}
}

void destroyCircularQueue(CircularQueue *pQueue)
{
	free(pQueue->arr);
	free(pQueue);
}
