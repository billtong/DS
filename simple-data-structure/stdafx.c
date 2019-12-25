#include "stdafx.h"

pSLNode createSingleLinkedNode(int value)
{
	pSLNode pNode = (pSLNode)malloc(sizeof(struct sSingleLinkedNode));
	if (pNode == NULL)
		return NULL;
	pNode->next = NULL;
	pNode->value = value;
	return pNode;
}

void printLinkedNodes(pSLNode pNode)
{
	printf("linked list:\t");
	while (pNode != NULL)
	{
		printf("%d\t", pNode->value);
		pNode = pNode->next;
	}
	printf("\n");
}


void printArray(int* arr, int size)
{
	printf("array list:\t");
	for (int i = 0; i < size; i++)
		printf("%d\t", arr[i]);
	printf("\n");
}

void swapElementsInArray(int* arr, int a, int b)
{
	int t = arr[a];
	arr[a] = arr[b];
	arr[b] = t;
}