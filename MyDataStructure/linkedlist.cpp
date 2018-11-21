#include "linkedlist.h"
#include <stdlib.h>
#include <stdio.h>

llnode * initLinkedNode(int value)
{
	llnode *node = (llnode *)malloc(sizeof(llnode));
	node->data = value;
	node->next = NULL;
	return node;
}

linkedlist * initLinkedList()
{
	linkedlist *ll = (linkedlist *)malloc(sizeof(linkedlist));
	ll->head = NULL;
	ll->size = 0;
	return ll;
}

void insertIndexOf(linkedlist * ll, int index, int value)
{

	llnode *addNode = initLinkedNode(value) ,*temp;

	if (ll == NULL) {
		printf("linkedlist insertIndexOf error: linkedlist null error\n");
	}
	else if (index ==1) {
		temp = ll->head;
		ll->head = addNode;
		addNode->next = temp;
		ll->size++;
	}
	else if (index<1 || index>ll->size+1)
	{
		printf("linkedlist insertIndexOf error: index out of bound\n");
	}
	else {
		
		llnode *lln = findIndexOf(ll, index-1);
		temp = lln->next;
		lln->next = addNode;
		addNode->next = temp;
		ll->size++;
		
	}
}

void append(linkedlist * ll, int value)
{
	llnode *addNode = (llnode *)malloc(sizeof(llnode)), *temp = NULL;
	addNode->data = value;
	addNode->next = NULL;
	if (ll == NULL) {
		printf("linkedlist append error: linkedlist null error\n");
	}
	else {
		insertIndexOf(ll, ll->size+1, value);
	}
}

llnode * findIndexOf(linkedlist * ll, int index)
{
	llnode *node = ll->head;
	if (ll == NULL) {
		printf("linkedlist find error: linkedlist null error\n");
		return NULL;
	}
	else if (index<1 || index>ll->size)
	{
		printf("linkedlist find error: index out of bound\n");
	}
	else if (index == 1) {
		return node;
	}
	else
	{
		for (int i = 1; i < index; i++) {
			node = node->next;
		}
		return node;
	}
}

void freeLinkedList(linkedlist *ll)
{
	if (ll == NULL) {

	}
	else
	{
		llnode* ln = ll->head, *temp;
		while (ln) {
			temp = ln;
			ln = ln->next;
			free(temp);
		}
		free(ll);
	}
	printf("cleaned the whole linkedlist.\n");
}

int removeIndexOf(linkedlist * ll, int index)
{
	int rslt = 0;
	llnode *temp = NULL;
	if (ll == NULL || ll->head == NULL) {
		printf("linkedlist removeIndexOf error: linkedlist null\n");
	}
	else if (index<1 || index >ll->size) {
		printf("linkedlist removeIndexOf error: out of bound\n");
	}
	else if (index == 1) {
		rslt = ll->head->data;
		ll->head = ll->head->next;
		ll->size--;
		return rslt;
	}
	else {
		temp = findIndexOf(ll, index - 1);
		rslt = temp->data;
		temp->next = temp->next->next;
		ll->size--;
		return rslt;
	}
	return -1;
}

void printLinkedList(linkedlist * ll)
{
	if (ll == NULL ) {
		printf("linkedlist printLinkedList error: linkedlist null error\n");
	}
	else if(ll->head == NULL || ll->size==0)
	{
		printf("the linkedlist is empty\n");
	}
	else
	{
		printf("array: [ ");
		llnode *node = ll->head;
		while (node) {
			printf("%d ", node->data);
			node = node->next;
		}
		printf("]\n");
	}
	
}
