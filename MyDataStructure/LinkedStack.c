#include"ZHeader.h"

linkedstack * initLinkedstack()
{
	linkedstack *ls = (linkedstack *)malloc(sizeof(linkedstack));
	ls->ll = initSingleLinkedList();
	ls->top = ls->ll->size;
	return ls;
}

void push(linkedstack * ls, int value)
{
	if (ls == NULL) {
		printf("linkedstack push error: as is not exist");
	}
	else {
		append(ls->ll, value);
		ls->top = ls->ll->size;
	}
}

int pop(linkedstack * ls)
{
	if (ls == NULL) {
		printf("linkedstack pop error: linkedstack not exist\n");
		return -1;
	}
	else {
		int rslt = removeIndexOf(ls->ll, ls->top);
		ls->top = ls->ll->size;
		return rslt;
	}
}

int tos(linkedstack * ls)
{
	if (ls == NULL) {
		printf("linkedstack tos error: linkedstack is not exist\n");
		return -1;
	}
	else {
		llnode *n = findIndexOf(ls->ll, ls->top);
		return n->data;
	}
}

void printLinkedStack(linkedstack * ls)
{
	if (ls == NULL) {
		printf("linkedstack print error: linkedstack is not exist\n");
	}
	else {
		printLinkedList(ls->ll);
	}
}

void freeLinkedStack(linkedstack * ls)
{
	if (ls == NULL) {
		printf("linkedstack free error: linkedstack is not exist\n");
	}
	else {
		freeLinkedList(ls->ll);
		free(ls);
	}

}

