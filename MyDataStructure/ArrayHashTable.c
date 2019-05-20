#include "ZHeader.h"

arrayhashtable * initArrayHashTable(int size)
{
	arrayhashtable *ht = (arrayhashtable *)malloc(sizeof(arrayhashtable));
	ht->hashtable = (char **)malloc(sizeof(char *)*size);
	for (int i = 0; i < size; i++) {
		ht->hashtable[i]  = NULL;
	}
	ht->tablesize = size;
	ht->collision = 0;
	return ht;
}

int hash(arrayhashtable * ht, char * data)
{
	if (ht == NULL) {
		printf("error null hashtable");
		return -1;
	}
	return hashString(data) % ht->tablesize;
}

void insertArrayHashTable(arrayhashtable * ht, char * data)
{
	int keyOri = hash(ht, data), key = keyOri;
	do
	{
		if (ht->hashtable[key] == NULL) {
			ht->hashtable[key] = data;
			return;
		}
		key = (key + 1) % ht->tablesize;
		ht->collision++;
	} while (key != keyOri);

	printf("error: the hashtable is full cannot input value %s\n", data);
}

int findArrayHashTable(arrayhashtable * ht, char * data)
{
	int indexOri = hash(ht, data), index = indexOri;

	do
	{
		if (ht->hashtable[index] && strcmp(ht->hashtable[index], data) == 0) {
			return index;
		}

		index = (index + 1) % ht->tablesize;
	} while (index != indexOri);
	
	return -1;
}

int deleteArrayHashTable(arrayhashtable * ht, char * data)
{
	int key = findArrayHashTable(ht, data);
	if (key >=0 && key<ht->tablesize) {
		ht->hashtable[key] = NULL;
	}
	return key;
}

double getLoadFactor(arrayhashtable * ht)
{
	 double n = 0;
	for (int i = 0; i < ht->tablesize; i++) {
		if (ht->hashtable[i]) {
			n++;
		}
	}
	return (n/ht->tablesize) *100;
}

void printArrayHashTable(arrayhashtable * ht)
{
	if (ht == NULL) {
		printf("this array hash table is empty\n");
	}
	else {
		printf("print the array hash table below:\n");
		for (int i = 0; i < ht->tablesize; i++) {
			if (ht->hashtable[i] == NULL) {
				printf("%d->\n", i);
			}
			else
			{
				printf("%d->%s\n", i, ht->hashtable[i]);
			}	
		}
	}
}
