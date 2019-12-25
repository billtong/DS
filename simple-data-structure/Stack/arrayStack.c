#include "arrayStack.h"

ArrayStack* createArrayStack(unsigned int capacity)
{
	ArrayStack* pStack = (ArrayStack*)malloc(sizeof(ArrayStack));
	if (pStack == NULL)
		return NULL;
	pStack->top = -1;
	pStack->capacity = capacity;
	pStack->arr = (int*)malloc(sizeof(int) * capacity);
	return pStack;
}

int IsArrayStackFull(ArrayStack* pStack)
{
	return pStack->top == pStack->capacity - 1;
}

int IsArrayStackEmpty(ArrayStack* pStack)
{
	return pStack->top == -1;
}

void pushArrayStack(ArrayStack* pStack, int value)
{
	if (!IsArrayStackFull(pStack))
		pStack->arr[++pStack->top] = value;
}

int popArrayStack(ArrayStack* pStack)
{
	if (IsArrayStackEmpty(pStack))
		return INT_MIN;
	return pStack->arr[pStack->top--];
}

int peekArrayStack(ArrayStack* pStack)
{
	if (IsArrayStackEmpty(pStack))
		return INT_MIN;
	return pStack->arr[pStack->top];
}

void destroyArrayStack(ArrayStack* pStack)
{
	free(pStack->arr);
	free(pStack);
	pStack = NULL;
}
