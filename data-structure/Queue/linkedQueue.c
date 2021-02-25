#include "linkedQueue.h"

LinkedQueue *createLinkedQueue()
{
	LinkedQueue *pQueue = malloc(sizeof(LinkedQueue));
	if (pQueue == NULL)
		return NULL;
	pQueue->size = 0;
	pQueue->front = NULL;
	pQueue->rear = NULL;
	return pQueue;
}

int isLinkedQueueEmpty(LinkedQueue *pQueue)
{
	return pQueue->size == 0;
}

void enLinkedQueue(LinkedQueue *pQueue, int elem)
{
	pSLNode pNode = createSingleLinkedNode(elem);
	if (pQueue->size == 0)
	{
		pQueue->front = pNode;
		pQueue->rear = pNode;
	}
	else
	{
		pQueue->rear->next = pNode;
		pQueue->rear = pNode;
	}
	pQueue->size++;
}

int deLinkedQueue(LinkedQueue *pQueue)
{
	if (!isLinkedQueueEmpty(pQueue))
	{
		pSLNode temp = pQueue->front;
		int data = temp->value;
		pQueue->front = pQueue->front->next;
		pQueue->size--;
		free(temp); //prevent memory leak
		return data;
	}
	return INT_MIN;
}

void traverseLinkedQueue(LinkedQueue *pQueue)
{
	printLinkedNodes(pQueue->front);
}

void destroyLinkedQueue(LinkedQueue *pQueue)
{
	while (!isLinkedQueueEmpty(pQueue))
		deLinkedQueue(pQueue);
	free(pQueue);
}
