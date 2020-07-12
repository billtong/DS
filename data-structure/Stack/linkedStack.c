#include "linkedStack.h"

LinkedStack* createLinkedStack()
{
	LinkedStack* pStack = (LinkedStack*)malloc(sizeof(LinkedStack));
	if (pStack == NULL)
		return NULL;
	pStack->root = NULL;
	return pStack;
}

int isLinkedStackEmpty(LinkedStack* pStack)
{
	return !pStack->root;
}

void pushLinkedStack(LinkedStack* pStack, int value)
{
	pSLNode pNode = createSingleLinkedNode(value);
	pNode->next = pStack->root;
	pStack->root = pNode;
}

int popLinkedStack(LinkedStack* pStack)
{
	if (isLinkedStackEmpty(pStack))
		return INT_MIN;
	pSLNode temp = pStack->root;
	pStack->root = pStack->root->next;
	int value = temp->value;
	free(temp);
	return value;
}

int peekLinkedStack(LinkedStack* pStack)
{
	if (isLinkedStackEmpty(pStack))
		return INT_MIN;
	return pStack->root->value;
}

void destroyLinkedStack(LinkedStack* pStack)
{
	while (!isLinkedStackEmpty(pStack))
		popLinkedStack(pStack);
	free(pStack);
}
