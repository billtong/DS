#include"ZHeader.h"

circularqueue * initCircularQueue(int size)
{
	circularqueue *cq = (circularqueue *)malloc(sizeof(circularqueue));
	cq->arr = new int[size];
	cq->front = cq->rear = -1;
	cq->count = 0;
	cq->size = size;
	return cq;
}

bool isFull(circularqueue * cq)
{
	return (cq->count == cq->size);
}

bool isEmpty(circularqueue * cq)
{
	return cq->count == 0;
}

void enCircularQueue(circularqueue * cq, int value)
{
	if (isFull(cq)) {
		printf("the queue is full, cannot enqueue anymore.\n");

	}
	else {
		cq->rear = (cq->rear + 1) % cq->size;
		(cq->arr)[cq->rear] = value;
		cq->count++;
		if (cq->front == -1) {
			cq->front = cq->rear;
		}
	}
}

int deCircularQueue(circularqueue * cq)
{
	if (isEmpty(cq)) {
		printf("the queue is empty, cannot dequeue anymore.\n");
		return 0;
	}
	int data = (cq->arr)[cq->front];
	cq->front = (cq->front + 1) % cq->size;
	cq->count--;
	if (isEmpty(cq)) {
		cq->front = cq->rear = -1;
	}
	return data;
}

void printCircularQueue(circularqueue * cq)
{
	if (isEmpty(cq)) {
		printf("the circular queue is empty\n");
	}
	else {
		if (cq->rear >= cq->front) {
			for (int i = cq->front; i <= cq->rear; i++) {
				printf("%d ", (cq->arr)[i]);
			}
		}
		else if (cq->rear < cq->front) {
			for (int i = cq->front; i < cq->size; i++) {
				printf("%d ", (cq->arr)[i]);
			}

			for (int i = 0; i <= cq->rear; i++) {
				printf("%d ", (cq->arr)[i]);
			}
		}
	}
}

