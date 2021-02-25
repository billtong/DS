#pragma once

#include "../ArrayList/arrayList.h"

typedef ArrayList *pArrayQueue;

pArrayQueue createArrayQueue();

int isArrayQueueEmpty(pArrayQueue);

void enArrayQueue(pArrayQueue, int);

int deArrayQueue(pArrayQueue pQueue);

void traverseArrayQueue(pArrayQueue);

void destroyArrayQueue(pArrayQueue);
