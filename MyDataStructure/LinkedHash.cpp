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

void insertLinkedHash(linkedhashtable * ht, char * ch)
{

	int key = divisionHash(ht, ch);
	if (isSingleLinkedListEmpty((ht->hashlist)[key]) == false) {
		ht->collision++;
	}
	addSingleLinkedListFront((ht->hashlist)[key], ch);
}

void findInLinkedHash(linkedhashtable * ht, char * ch)
{

}

void printLinkedHash(linkedhashtable * ht)
{
	for (int i = 0; i < ht->size; i++) {
		printf("%d -->", i);
		printCharSingleLinkedList((ht->hashlist)[i]);
	}
	printf("# of Collisions=%d\n", ht->collision);
}



