#pragma once

#include "../LinkedList/singleLinkedList.h"

typedef struct
{
	pSLList* hashList;
	int size;
	int collision;
} LinkedHashTable;

LinkedHashTable* createLinkedHashTable(int);

/*
this function computes a hash code for a given string
used in division hash
*/
long hashString(char*);
int divisionHash(LinkedHashTable*, char*);

/*
(#ocuppied / hash size) * 100%
*/
double calcLoadFactor(LinkedHashTable* pHash);

/*
double the size of hash table to reduce the load factor
*/
void rehashLinkedHashTable(LinkedHashTable** ht);

LinkedHashTable* insertLinkedHashTable(LinkedHashTable*, char*);

void traverseLinkedHashTable(LinkedHashTable*);
