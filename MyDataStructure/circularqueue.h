#pragma once
#ifndef CIRCULARQUEUE_H
#define CIRCULARQUEUE_H

typedef struct _CircularQueue
{
	int *arr;
	int rear;
	int front;
	int count;
	int size;
} circularqueue;

circularqueue *initCircularQueue(int size);

int isFull(circularqueue *cq);

int isCircularQueueEmpty(circularqueue *cq);

void enCircularQueue(circularqueue *cq, int value);

int deCircularQueue(circularqueue *cq);

void printCircularQueue(circularqueue *cq);

#endif // !CIRCULARQUEUE_H
