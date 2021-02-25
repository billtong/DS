#pragma once

#include "../stdafx.h"

typedef struct
{
	int *arr;
	int front; //index starts from 0
	int rear;	 //index starts from 0
	int size;
	unsigned int capacity;
} CircularQueue;

CircularQueue *createCircularQueue(int);
int isCircularQueueEmpty(CircularQueue *);
int isCircularQueueFull(CircularQueue *);

void enCircularQueue(CircularQueue *, int);
int deCircularQueue(CircularQueue *);

void traverseCircularQueue(CircularQueue *);
void destroyCircularQueue(CircularQueue *);
