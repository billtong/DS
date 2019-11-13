#include"ZHeader.h"

llnode* initLinkedIntNode(int value)
{
	llnode* node = (llnode*)malloc(sizeof(llnode));
	node->data = value;
	node->next = NULL;
	return node;
}

llnode* initLinkedCharNode(char* ch)
{
	llnode* node = (llnode*)malloc(sizeof(llnode));
	node->ch = ch;
	node->next = NULL;
	return node;
	return node;
}

singlelinkedlist* initSingleLinkedList()
{
	singlelinkedlist* ll = (singlelinkedlist*)malloc(sizeof(singlelinkedlist));
	ll->head = NULL;
	ll->size = 0;
	return ll;
}

void insertSingleLinkedListIndexOf(singlelinkedlist* ll, int index, int value)
{

	llnode* addNode = initLinkedIntNode(value), * temp;

	if (ll == NULL) {
		printf("singlelinkedlist insertSingleLinkedListIndexOf error: singlelinkedlist null error\n");
	}
	else if (index == 1) {
		temp = ll->head;
		ll->head = addNode;
		addNode->next = temp;
		ll->size++;
	}
	else if (index<1 || index>ll->size + 1)
	{
		printf("singlelinkedlist insertSingleLinkedListIndexOf error: index out of bound\n");
	}
	else {

		llnode* lln = findIndexOf(ll, index - 1);
		temp = lln->next;
		lln->next = addNode;
		addNode->next = temp;
		ll->size++;

	}
}

void singleLinkedAppend(singlelinkedlist* ll, int value)
{
	llnode* addNode = (llnode*)malloc(sizeof(llnode)), * temp = NULL;
	addNode->data = value;
	addNode->next = NULL;
	if (ll == NULL) {
		printf("singlelinkedlist singleLinkedAppend error: singlelinkedlist null error\n");
	}
	else {
		insertSingleLinkedListIndexOf(ll, ll->size + 1, value);
	}
}

void addSingleLinkedListFront(singlelinkedlist* ll, char* ch)
{
	llnode* node = ll->head;
	ll->head = initLinkedCharNode(ch);
	ll->head->next = node;
	ll->size++;
}

int findCharInSingleLinkedList(singlelinkedlist* ll, char* ch)
{
	if (isSingleLinkedListEmpty(ll) || ll->size == 0)
	{
		printf("the singlelinkedlist is empty\n");
		return -1;
	}
	else {
		int i = 0;
		llnode* ptr = ll->head;
		while (ptr) {
			if (strcmp(ch, ptr->ch) == 0) {

				return i;
			}
			ptr = ptr->next;
			i++;
		}
		return -1;
	}

}

llnode* findIndexOf(singlelinkedlist* ll, int index)
{
	llnode* node = ll->head;
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

int isSingleLinkedListEmpty(singlelinkedlist* ll)
{
	return (ll != NULL) && (ll->head != NULL) ? 0 : 1;
}

int isEmpty(singlelinkedlist* ll)
{
	return (ll != NULL) && (ll->head != NULL) ? 0 : 1;
}

void freeLinkedList(singlelinkedlist* ll)
{
	if (ll == NULL) {

	}
	else
	{
		llnode* ln = ll->head, * temp;
		while (ln) {
			temp = ln;
			ln = ln->next;
			free(temp);
		}
		free(ll);
	}
	printf("cleaned the whole singlelinkedlist.\n");
}

int removeSingleLinkedListIndexOf(singlelinkedlist* ll, int index)
{
	int rslt = 0;
	llnode* temp = NULL;
	if (ll == NULL || ll->head == NULL) {
		printf("singlelinkedlist removeSingleLinkedListIndexOf error: singlelinkedlist null\n");
	}
	else if (index<1 || index >ll->size) {
		printf("singlelinkedlist removeSingleLinkedListIndexOf error: out of bound\n");
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

void printLinkedList(singlelinkedlist* ll)
{

	if (isSingleLinkedListEmpty(ll) || ll->size == 0)
	{
		printf("[]\n");
	}
	else
	{
		printf("array: [ ");
		llnode* node = ll->head;
		while (node) {
			printf("%d ", node->data);
			node = node->next;
		}
		printf("]\n");
	}

}

void printCharSingleLinkedList(singlelinkedlist* ll)
{
	if (isSingleLinkedListEmpty(ll) || ll->size == 0)
	{
		printf("[]\n");
	}
	else
	{
		printf("[ ");
		llnode* node = ll->head;
		while (node) {
			printf("%s --", node->ch);
			node = node->next;
		}
		printf("]\n");
	}


}