#ifndef LINKEDQUEUE_H
#define LINKEDQUEUE__H
#include "linkedlist.h"

typedef struct _LinkedQueue
{
	linkedlist *ll;
	int count;
}linkedqueue;


bool isLinkedQueueEmpty(linkedqueue *aq);
linkedqueue *initLinkedQueue();
void enqueue(linkedqueue *aq, int value);
int dequeue(linkedqueue *lq);
void prinLinkedQueue(linkedqueue *aq);

void freeLinkedQueue(linkedqueue *lq);

#endif // !LINKEDQUEUE_H
#pragma once
