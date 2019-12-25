#pragma once

//include c std libraries
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <limits.h> 
#include <string.h>

//
typedef struct sSingleLinkedNode
{
	int value;
	struct sSingleLinkedNode* next;
} SLNode, * pSLNode;

/*
first params: value to be saved in the node
return the pointe to the initialized node
*/
pSLNode createSingleLinkedNode(int);

/*
Traverse the array list and print each node's value
*/
void printLinkedNodes(pSLNode);

void printArray(int*, int);

void swapElementsInArray(int* arr, int a, int b);