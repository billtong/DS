#ifndef LINKEDHASH_H
#define LINKEDHASH_H

#include"ZHeader.h"

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



void insertLinkedHash(linkedhashtable *ht, char *ch);
void findInLinkedHash(linkedhashtable *ht, char *ch);
void printLinkedHash(linkedhashtable *ht);




#endif // !LINKEDHASH_H
#pragma once
