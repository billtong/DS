#ifndef LINKEDHASH_H
#define LINKEDHASH_H

#include "SingleLinkedList.h"

typedef struct _LinkedHash
{
	singlelinkedlist **hashlist;
	int size;
	int collision;
}linkedhashtable;

linkedhashtable *initLinkedHashTable(int size);

/*
this function computes a hash code for a given string
used in division hash
*/
long hashString(char *ch);

int divisionHash(linkedhashtable *ht, char *ch);

linkedhashtable *insertLinkedHash(linkedhashtable *ht, char *ch);

int findInLinkedHash(linkedhashtable *ht, char *ch);

double calcLoadFactor(linkedhashtable *ht);

/*
size *2
rehash every item
*/
void rehashLinkedHashTable(linkedhashtable ** ht);

void printLinkedHash(linkedhashtable *ht);

#endif // !LINKEDHASH_H
#pragma once
