#include"ZHeader.h"

linkedhashtable * initLinkedHashTable(int size)
{
	linkedhashtable *lht = (linkedhashtable *)malloc(sizeof(linkedhashtable));
	lht->collision = 0;
	lht->size = size;
	lht->hashlist = (singlelinkedlist **)malloc(sizeof(singlelinkedlist)*size);
	for (int i = 0; i < size; i++) {
		(lht->hashlist)[i] = initSingleLinkedList();
	}
	return lht;
}

long hashString(char * ch)
{
	long sum = 0;
	int i = 0;
	int l = strlen(ch);
	while (ch[i] != '\0') {
		sum += (ch[i] * (long)pow(31, l - i - 1));
		i++;
	}
	return sum;
}

int divisionHash(linkedhashtable * ht, char * ch)
{
	return hashString(ch) % ht->size;
}

linkedhashtable *insertLinkedHash(linkedhashtable * ht, char * ch)
{

	int key = divisionHash(ht, ch);
	if (isSingleLinkedListEmpty((ht->hashlist)[key]) == false) {
		ht->collision++;
	}
	addSingleLinkedListFront((ht->hashlist)[key], ch);
	if (calcLoadFactor(ht) > 75) {
		rehashLinkedHashTable(&ht);
	}

	return ht;
}

bool findInLinkedHash(linkedhashtable * ht, char * ch)
{
	if (ht == nullptr) {
		printf("string %s is not exist in linked hash\n", ch);
		return false;
	}
	
	int key = divisionHash(ht, ch);
	if (isSingleLinkedListEmpty((ht->hashlist)[key])) {
		printf("string %s is not exist in linked hash\n", ch);
		return false;
	}

	if (findCharInSingleLinkedList((ht->hashlist)[key], ch) != -1) {
		printf("find string %s in key %d\n", ch, key);
		return true;
	}
	printf("string %s is not exist in linked hash\n", ch);
	return false;
}

double calcLoadFactor(linkedhashtable * ht)
{
	double n = 0;
	for (int i = 0; i < ht->size; i++) {
		if (isSingleLinkedListEmpty((ht->hashlist)[i]) == false) {
			n++;
		}
	}

	return (n/ht->size)*100;
}

void rehashLinkedHashTable(linkedhashtable ** ht)
{

	if (*ht == nullptr) {
		return;
	}

	linkedhashtable *oldht = *ht;
	*ht = initLinkedHashTable(oldht->size * 2);
	
	for (int i = 0; i < oldht->size; i++) {
		if (isSingleLinkedListEmpty((oldht->hashlist)[i]) == false) {
			llnode *ptr = (oldht->hashlist)[i]->head;
			while (ptr) {
				*ht = insertLinkedHash(*ht, ptr->ch);
				ptr = ptr->next;
			}
		}
	}
}

void printLinkedHash(linkedhashtable * ht)
{
	for (int i = 0; i < ht->size; i++) {
		printf("%d -->", i);
		printCharSingleLinkedList((ht->hashlist)[i]);
	}
}



