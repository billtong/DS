#include "ZHeader.h"


arrayhashtable * initArrayHashTable(int size)
{
	arrayhashtable *ht = (arrayhashtable *)malloc(sizeof(arrayhashtable));
	ht->hashtable = (char **)malloc(sizeof(char *)*size);
	for (int i = 0; i < size; i++) {
		ht->hashtable[i]  = nullptr;
	}
	ht->tablesize = size;
	ht->collision = 0;
	return ht;
}

int hash(arrayhashtable * ht, char * data)
{
	if (ht == nullptr) {
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
		if (ht->hashtable[key] == nullptr) {
			ht->hashtable[key] = data;
			return;
		}
		key = (key + 1) % ht->tablesize;
	} while (key != keyOri);

	printf("error: the hashtable is full cannot input value %s\n", data);
}





void printArrayHashTable(arrayhashtable * ht)
{
	if (ht == nullptr) {
		printf("this array hash table is empty\n");
	}
	else {
		printf("print the array hash table below:\n");
		for (int i = 0; i < ht->tablesize; i++) {
			if (ht->hashtable[i] == nullptr) {
				printf("%d->\n", i);
			}
			else
			{
				printf("%d->%s\n", i, ht->hashtable[i]);
			}
			
		}
	}
}
