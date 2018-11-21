#include "SingleLinkedList.h"
#include <stdlib.h>
#include <stdio.h>

llnode * initLinkedNode(int value)
{
	llnode *node = (llnode *)malloc(sizeof(llnode));
	node->data = value;
	node->next = NULL;
	return node;
}

singlelinkedlist * initLinkedList()
{
	singlelinkedlist *ll = (singlelinkedlist *)malloc(sizeof(singlelinkedlist));
	ll->head = NULL;
	ll->size = 0;
	return ll;
}

void insertIndexOf(singlelinkedlist * ll, int index, int value)
{

	llnode *addNode = initLinkedNode(value) ,*temp;

	if (ll == NULL) {
		printf("singlelinkedlist insertIndexOf error: singlelinkedlist null error\n");
	}
	else if (index ==1) {
		temp = ll->head;
		ll->head = addNode;
		addNode->next = temp;
		ll->size++;
	}
	else if (index<1 || index>ll->size+1)
	{
		printf("singlelinkedlist insertIndexOf error: index out of bound\n");
	}
	else {
		
		llnode *lln = findIndexOf(ll, index-1);
		temp = lln->next;
		lln->next = addNode;
		addNode->next = temp;
		ll->size++;
		
	}
}

void append(singlelinkedlist * ll, int value)
{
	llnode *addNode = (llnode *)malloc(sizeof(llnode)), *temp = NULL;
	addNode->data = value;
	addNode->next = NULL;
	if (ll == NULL) {
		printf("singlelinkedlist append error: singlelinkedlist null error\n");
	}
	else {
		insertIndexOf(ll, ll->size+1, value);
	}
}

llnode * findIndexOf(singlelinkedlist * ll, int index)
{
	llnode *node = ll->head;
	if (ll == NULL) {
		printf("singlelinkedlist find error: singlelinkedlist null error\n");
		return NULL;
	}
	else if (index<1 || index>ll->size)
	{
		printf("singlelinkedlist find error: index out of bound\n");
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

void freeLinkedList(singlelinkedlist *ll)
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
	printf("cleaned the whole singlelinkedlist.\n");
}

int removeIndexOf(singlelinkedlist * ll, int index)
{
	int rslt = 0;
	llnode *temp = NULL;
	if (ll == NULL || ll->head == NULL) {
		printf("singlelinkedlist removeIndexOf error: singlelinkedlist null\n");
	}
	else if (index<1 || index >ll->size) {
		printf("singlelinkedlist removeIndexOf error: out of bound\n");
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

void printLinkedList(singlelinkedlist * ll)
{
	if (ll == NULL ) {
		printf("singlelinkedlist printLinkedList error: singlelinkedlist null error\n");
	}
	else if(ll->head == NULL || ll->size==0)
	{
		printf("the singlelinkedlist is empty\n");
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
