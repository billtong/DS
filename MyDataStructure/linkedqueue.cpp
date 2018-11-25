#include "linkedqueue.h"
#include <stdlib.h>
#include <stdio.h>
bool isLinkedQueueEmpty(linkedqueue * aq)
{
	if (aq == nullptr || aq->count == 0) {
		return true;
	}
	else {
		return false;
	}
}

linkedqueue * initLinkedQueue()
{
	linkedqueue *lq = (linkedqueue *)malloc(sizeof(linkedqueue));
	lq->ll = initSingleLinkedList();
	lq->count = 0;
	return lq;
}

void enqueue(linkedqueue * lq, int value)
{
	if (lq ==NULL || lq->ll == NULL) {
		printf("linkedqueue enqueue error: queue null\n");
	}
	else
	{
		append(lq->ll, value);
		lq->count = lq->ll->size;
	}
}

int dequeue(linkedqueue *lq)
{
	if (isLinkedQueueEmpty(lq)) {
		printf("linkedqueue dequeue error: queue empty\n");
		return -1;
	}
	else {
		int i = removeIndexOf(lq->ll, 1);
		lq->count = lq->ll->size;
		return i;
	}
}

void prinLinkedQueue(linkedqueue * lq)
{
	if (isLinkedQueueEmpty(lq)) {
		printf("this linked queue is empty\n");
	}
	else {
		printLinkedList(lq->ll);
	}
}

void freeLinkedQueue(linkedqueue * lq)
{
	if (isLinkedQueueEmpty) {
		printf("linkedqueue free error: queue null\n");
	}
	else {
		freeLinkedList(lq->ll);
		free(lq);
		printf("cleaned all\n");
	}

}
