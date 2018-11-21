#include "arrayqueue.h"
#include <stdio.h>
#include <stdlib.h>

bool isArrayQueueEmpty(arrayqueue * aq)
{

	if (aq==nullptr || aq->count==0) return true;
	else return false;
}

arrayqueue * initArrayQueue()
{
	arrayqueue *aq = (arrayqueue *)malloc(sizeof(arrayqueue));
	aq->al = initArrayList();
	aq->count = 0;
	return aq;
}

void enqueue(arrayqueue * aq, int value)
{
	if (aq == NULL) {
		printf("arrayqueue enqueue error: the arraylist is not exist\n");
	}
	else {
		append(aq->al, value);
		aq->count = aq->al->used;
	}
}

int dequeue(arrayqueue * aq)
{
	if (isArrayQueueEmpty(aq)) {
		printf("arrayqueue dequeue error: the arrayqueue is empty, cannot dequeue.\n");
		return -1;
	}
	else {
		int i = removeIndexOf(aq->al, 1);
		aq->count = aq->al->used;
		return i;
	}
}

void printArrayQueue(arrayqueue * aq)
{
	if (isArrayQueueEmpty(aq)) {
		printf("this queue is empty\n");
	}
	else {
		printArrayList(aq->al);
	}
}

void freeArrayQueue(arrayqueue * aq)
{
	if(!isArrayQueueEmpty(aq)) freeArrayList(aq->al);
	free(aq);
	printf("cleaned arrayqueue\n");
}

