#ifndef ARRAYQUEUE_H
#define ARRAYQUEUE_H
#include "ArrayList.h"

typedef struct _ArrayQueue
{
	arraylist *al;
	int count;
} arrayqueue;


bool isArrayQueueEmpty(arrayqueue *aq);
arrayqueue *initArrayQueue();
void enqueue(arrayqueue *aq, int value);
int dequeue(arrayqueue *aq);
void printArrayQueue(arrayqueue *aq);

void freeArrayQueue(arrayqueue *aq);

#endif // !ARRAYQUEUE_H
#pragma once
