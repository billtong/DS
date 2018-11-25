#ifndef LINKEDQUEUE_H
#define LINKEDQUEUE__H
#include"ZHeader.h"

typedef struct _LinkedQueue
{
	singlelinkedlist *ll;
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
