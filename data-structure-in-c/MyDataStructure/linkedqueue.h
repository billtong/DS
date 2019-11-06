#ifndef LINKEDQUEUE_H
#define LINKEDQUEUE__H

#include "SingleLinkedList.h"

typedef struct _LinkedQueue
{
	singlelinkedlist* ll;
	int count;
}linkedqueue;

int isLinkedQueueEmpty(linkedqueue* aq);

linkedqueue* initLinkedQueue();

void linkedEnqueue(linkedqueue* aq, int value);

int linkedDequeue(linkedqueue* lq);

void prinLinkedQueue(linkedqueue* aq);

void freeLinkedQueue(linkedqueue* lq);

#endif // !LINKEDQUEUE_H
#pragma once
