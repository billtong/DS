#include"ZHeader.h"

#define INITIAL_ARRAY_SIZE 10

arraylist* initArrayList()
{
	arraylist *al = (arraylist *)malloc(sizeof(arraylist));
	al->arr = (int *)malloc(sizeof(int)*INITIAL_ARRAY_SIZE);
	al->size = INITIAL_ARRAY_SIZE;
	al->used = 0;
	return al;
}

void append(arraylist * al, int value)
{
	insertIndexOf(al, al->used+1, value);
}

void insertIndexOf(arraylist * al, int index, int value)
{
	if (al == NULL || al->arr == NULL || al->size == 0) {
		printf("arraylist insertIndexof error: arraylist is null!\n");
	}
	else if (index<1 || index > al->used+1) {
		printf("arraylist insertIndexof error: index out of bound!\n");
	}
	else {
		if (al->used == 0) {
		(al->arr)[0] = value;
		al->used++;
		}
		else {
			if (al->size == al->used) {
				al->arr = (int *)realloc(al->arr, sizeof(int)*(al->size) * 2);
				al->size *= 2;
			}
			int i;
			for (i = al->used - 1; i >= index - 1; i--) {
				(al->arr)[i + 1] = (al->arr)[i];
			}
			(al->arr)[index - 1] = value;
			al->used++;
		}
	}
}

int removeIndexOf(arraylist * al, int index)
{
	if (al == NULL || al->arr == NULL || al->size == 0) {
		printf("arraylist removeIndexOf error: arraylist is null!\n");
		return -1;
	}
	else if (index < 0 || index > al->used) {
		printf("arraylist removeIndexOf error: arraylist is out of bound\n");
		return -1;
	}
	else {
		int j, temp = (al->arr) [index-1];
		for (j = index - 1; j<=al->used - 1; j++) {
			(al->arr)[j] = (al->arr)[j + 1];
		}
		al->used--;
		if (al->used == 0) {
			printf("warning : the arraylist is empty now\n");
		}
		return temp;
	}
}

int removeValueOf(arraylist *al, int value)
{
	if (al == NULL || al->arr == NULL || al->size == 0) {
		printf("arraylist removeValueof error: the array list is empty\n");
	}
	else {
		int i;
		for (i = 0; i < al->used; i++) {
			if ((al->arr)[i] == value) {
				removeIndexOf(al, i + 1);
				return i + 1;
			} 
		}
		printf("the value %d is not found in the arraylist\n", value);
		return -1;
	}
}

void printArrayList(arraylist * al)
{
	if (al == NULL || al->arr == NULL || al->size == 0) {
		printf("this arraylist is empty.\n");
	}
	else
	{
		printf("arraylist: [");
		int i;
		for (i = 0; i < al->used; i++) {
			printf(" %d ", (al->arr)[i]);
		}
		printf(" ]\n");
	}
}

void freeArrayList(arraylist * al)
{
	free(al->arr);
	free(al);
	printf("all the arraylist cleaned!\n");
}



