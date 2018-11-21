#include<stdlib.h>
#include<stdio.h>
#include "arraylist.h"
#include "linkedlist.h"
#include "arraystack.h"
#include "linkedstack.h"
#include "arrayqueue.h"
#include "linkedqueue.h"

int isTestingArrayList = 1;
int isTestingLinkedList = 1;
int isTestArrayStack = 1;
int isTestLinkedStack = 1;
int isTestArrayQueue = 1;
int isTestLinkedQueue = 1;

/*
int main()
{
//list testing	
	if (isTestingArrayList) {
		arraylist *al = initArrayList();
		for (int i = 0; i < 15; i++) {
			append(al, i);
			printf("used: %d	size: %d\n",al->used,al->size);
		}

		for (int i = 0; i < 15; i++) {
			removeValueOf(al, i);
			printf("used: %d	size: %d\n", al->used, al->size);
		}
		freeArrayList(al);
	}

	if (isTestingLinkedList) {
		linkedlist *ll = initLinkedList();
		printLinkedList(ll);
		for (int i = 1; i < 10; i++) {
			append(ll, i);
		}
		printLinkedList(ll);
		insertIndexOf(ll, ll->size, 111);

		printLinkedList(ll);
		freeLinkedList(ll);
	}

	//stack testing
	if (isTestArrayStack) {
		arraystack *as = initArraystack();
		for (int i = 0; i < 20; i++) {
			push(as, i);
		}
		printArrayStack(as);
		for (int i = 0; i < 20; i++) {
			printf("pop: %d\n", pop(as));
		}
		printArrayStack(as);
		freeArrayStack(as);
	}

	if (isTestLinkedStack) {
		linkedstack *ls = initLinkedstack();
		for (int i = 0; i < 20; i++) {
			push(ls, i);
		}
		printLinkedStack(ls);
		for (int i = 0; i < 20; i++) {
			pop(ls);
		}
		printLinkedStack(ls);
		freeLinkedStack(ls);
	}

	//queue testing
	if (isTestArrayQueue) {
		arrayqueue *aq = initArrayQueue();
		printArrayQueue(aq);
		for (int i = 0; i < 11; i++) {
			enqueue(aq, i);
			printArrayQueue(aq);
		}
		printArrayQueue(aq);
		for (int i = 0; i < 11; i++) {
			dequeue(aq);
			printArrayQueue(aq);
		}
		printArrayQueue(aq);
		freeArrayQueue(aq);
	}
	
	if (isTestLinkedQueue) {
		linkedqueue *lq = initLinkedQueue();
		for (int i = 0; i < 11; i++) {
			enqueue(lq, i);
			prinLinkedQueue(lq);
		}
		
		for (int i = 0; i < 11; i++) {
			dequeue(lq);
			prinLinkedQueue(lq);
		}
		freeLinkedQueue(lq);
	}

	system("pause");
	return 0;
}
*/
