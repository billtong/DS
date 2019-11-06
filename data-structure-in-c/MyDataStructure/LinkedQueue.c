#include"ZHeader.h"


int isLinkedQueueEmpty(linkedqueue* aq)
{
	if (aq == NULL || aq->count == 0) {
		return 1;
	}
	else {
		return 0;
	}
}

linkedqueue* initLinkedQueue()
{
	linkedqueue* lq = (linkedqueue*)malloc(sizeof(linkedqueue));
	lq->ll = initSingleLinkedList();
	lq->count = 0;
	return lq;
}

void linkedEnqueue(linkedqueue* lq, int value)
{
	if (lq == NULL || lq->ll == NULL) {
		printf("linkedqueue linkedEnqueue error: queue null\n");
	}
	else
	{
		singleLinkedAppend(lq->ll, value);
		lq->count = lq->ll->size;
	}
}

int linkedDequeue(linkedqueue* lq)
{
	if (isLinkedQueueEmpty(lq)) {
		printf("linkedqueue linkedDequeue error: queue empty\n");
		return -1;
	}
	else {
		int i = removeSingleLinkedListIndexOf(lq->ll, 1);
		lq->count = lq->ll->size;
		return i;
	}
}

void prinLinkedQueue(linkedqueue* lq)
{
	if (isLinkedQueueEmpty(lq)) {
		printf("this linked queue is empty\n");
	}
	else {
		printLinkedList(lq->ll);
	}
}

void freeLinkedQueue(linkedqueue* lq)
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
