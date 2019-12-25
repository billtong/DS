#pragma once

#include "../stdafx.h"

typedef struct
{
	int size;
	pSLNode front;
	pSLNode rear;
} LinkedQueue;

LinkedQueue* createLinkedQueue();

int isLinkedQueueEmpty(LinkedQueue*);

void enLinkedQueue(LinkedQueue*, int);
int deLinkedQueue(LinkedQueue*);

void traverseLinkedQueue(LinkedQueue*);
void destroyLinkedQueue(LinkedQueue*);