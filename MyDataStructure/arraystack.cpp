#include"ZHeader.h"


arraystack * initArraystack()
{
	arraystack *as = (arraystack *)malloc(sizeof(arraystack));
	as->al = initArrayList();
	as->top = as->al->used;
	return as;
}

void push(arraystack * as, int value)
{
	if (as == NULL) {
		printf("arraystack push error: arraystack pointer null\n");
	}
	else {
		append(as->al, value);
		as->top = as->al->used;
	}
}

int pop(arraystack * as)
{
	if (as == NULL) {
		printf("arraystack pop error: arraystack pointer null\n");
		return -1;
	}
	else {
		int temp = removeIndexOf(as->al, as->top);
		as->top = as->al->used;
		return temp;
	}
}

int tos(arraystack * as)
{
	if (as == NULL) {
		printf("arraystack tos error: arraystack pointer null\n");
		return -1;
	}
	else {
		return (as->al->arr)[as->top - 1];
	}
}

void printArrayStack(arraystack * as)
{
	if (as == NULL) 
		printf("arraystack print error: arraystack pointer null\n");
	 else 
		printArrayList(as->al);
}

void freeArrayStack(arraystack * as)
{
	if (as == NULL) 
		printf("arraystack freestack error: arraystack pointer null\n");
	else {
		freeArrayList(as->al);
		free(as);
		printf("cleaned all the array stack\n");
	}
}
