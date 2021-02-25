#include "singleLinkedList.h"

SingleLinkedList *createSingleLinkedList()
{
	SingleLinkedList *pList = (SingleLinkedList *)malloc(sizeof(SingleLinkedList));
	if (pList == NULL)
		return NULL;
	pList->head = NULL;
	pList->size = 0;
	return pList;
}

void insertSingleLinkedList(SingleLinkedList *pList, int value, int index)
{
	pSLNode pNode = createSingleLinkedNode(value);
	pSLNode temp;
	if (index == 0)
	{
		temp = pList->head;
		pList->head = pNode;
	}
	else
	{
		pSLNode pFrontNode = findIndexOfSingleLinkedList(pList, index - 1);
		temp = pFrontNode->next;
		pFrontNode->next = pNode;
	}
	pNode->next = temp;
	pList->size++;
}

void removeIndexOfSingleLinkedList(SingleLinkedList *pList, int index)
{
	if (index == 0)
		pList->head = pList->head->next;
	else
	{
		pSLNode pFrontNode = findIndexOfSingleLinkedList(pList, index - 1);
		pFrontNode->next = pFrontNode->next->next;
	}
	pList->size--;
}

pSLNode findIndexOfSingleLinkedList(SingleLinkedList *pList, int index)
{
	pSLNode iter = pList->head;
	for (int i = 0; i < index; i++)
		iter = iter->next;
	return iter;
}

pSLNode findValueOfSingleLinkedList(SingleLinkedList *pList, int value)
{
	pSLNode iter = pList->head;
	while (iter != NULL)
	{
		if (iter->value == value)
			return iter;
		iter = iter->next;
	}
	return NULL;
}

void destroySingleLinkedList(SingleLinkedList *pList)
{
	pSLNode iter = pList->head, temp;
	while (iter != NULL)
	{
		temp = iter;
		iter = iter->next;
		free(temp);
	}
}
