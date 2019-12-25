#include "arrayList.h"

ArrayList* createArrayList()
{
	ArrayList* plist = (ArrayList*)malloc(sizeof(ArrayList));
	if (plist == NULL)
		goto handle_error;
	plist->arr = (int*)malloc(sizeof(int) * ARRAY_LIST_INITIAL_SIZE);
	if (plist->arr == NULL)
		goto handle_error;
	plist->size = ARRAY_LIST_INITIAL_SIZE;
	plist->used = 0;
	return plist;
handle_error:
	printf("memory allocation failed");
	return NULL;
}

void insertArrayList(ArrayList* plist, int value, int index)
{
	if (index < plist->used)
	{
		for (int i = plist->used; i > index; i--) 
			plist->arr[i] = plist->arr[i - 1];
	}
	plist->arr[index] = value;
	plist->used++;
	if (plist->used == plist->size)
	{
		int* ptr = (int*)realloc(plist->arr, sizeof(int) * (plist->size + ARRAY_LIST_INITIAL_SIZE));
		if (ptr == NULL)
			printf("no more memory space, cannot reallocate the array list");
		plist->arr = ptr;
		plist->size += ARRAY_LIST_INITIAL_SIZE;
	}
}

void removeIndexOfArrayList(ArrayList* plist, int index)
{
	for (int j = index; j < plist->used - 1; j++)
		plist->arr[j] = plist->arr[j + 1];
	plist->used--;
}

int findValueOfArrayList(ArrayList* plist, int value)
{
	for (int i = 0; i < plist->used; i++)
	{
		if (plist->arr[i] == value)
			return i;
	}
	return -1;
}

int findIndexOfArrayList(ArrayList* pList, int index)
{
	return pList->arr[index];
}

void destroyArrayList(ArrayList* pList)
{
	free(pList->arr);
	free(pList);
}

void traverseArrayList(ArrayList* pList)
{
	printArray(pList->arr, pList->used);
}
