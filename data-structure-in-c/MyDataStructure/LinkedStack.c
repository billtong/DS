#include"ZHeader.h"

linkedstack* initLinkedstack()
{
	linkedstack* ls = (linkedstack*)malloc(sizeof(linkedstack));
	ls->ll = initSingleLinkedList();
	ls->top = ls->ll->size;
	return ls;
}

void linkedPush(linkedstack* ls, int value)
{
	if (ls == NULL) {
		printf("linkedstack linkedPush error: as is not exist");
	}
	else {
		singleLinkedAppend(ls->ll, value);
		ls->top = ls->ll->size;
	}
}

int linkedPop(linkedstack* ls)
{
	if (ls == NULL) {
		printf("linkedstack linkedPop error: linkedstack not exist\n");
		return -1;
	}
	else {
		int rslt = removeSingleLinkedListIndexOf(ls->ll, ls->top);
		ls->top = ls->ll->size;
		return rslt;
	}
}

int linkedTos(linkedstack* ls)
{
	if (ls == NULL) {
		printf("linkedstack linkedTos error: linkedstack is not exist\n");
		return -1;
	}
	else {
		llnode* n = findIndexOf(ls->ll, ls->top);
		return n->data;
	}
}

void printLinkedStack(linkedstack* ls)
{
	if (ls == NULL) {
		printf("linkedstack print error: linkedstack is not exist\n");
	}
	else {
		printLinkedList(ls->ll);
	}
}

void freeLinkedStack(linkedstack* ls)
{
	if (ls == NULL) {
		printf("linkedstack free error: linkedstack is not exist\n");
	}
	else {
		freeLinkedList(ls->ll);
		free(ls);
	}

}

