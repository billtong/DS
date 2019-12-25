/*
Linked List is a sequence of links which contains items. Each link contains a connection to another link.
Advantages over arrays
1) Dynamic size
2) Ease of insertion/deletion
Drawbacks:
1) Random access is not allowed. We have to access elements sequentially starting from the first node. 
So we cannot do binary search with linked lists efficiently with its default implementation. Read about it here.
2) Extra memory space for a pointer is required with each element of the list.
3) Not cache friendly. Since array elements are contiguous locations, there is locality of reference 
which is not there in case of linked lists.
*/
#pragma once

#include "../stdafx.h"

typedef struct
{
	int size;
	pSLNode head;
} SingleLinkedList, *pSLList;

SingleLinkedList* createSingleLinkedList();

/*
insert an element at the index
*/
void insertSingleLinkedList(SingleLinkedList*, int, int);

/*
delete the element by the index
*/
void removeIndexOfSingleLinkedList(SingleLinkedList*, int);

/*
search the element by the index
*/
pSLNode findIndexOfSingleLinkedList(SingleLinkedList*, int);

/*
search the first element with the value
*/
pSLNode findValueOfSingleLinkedList(SingleLinkedList*, int);

/*
free the memory allocation to the linked list
*/
void destroySingleLinkedList(SingleLinkedList*);