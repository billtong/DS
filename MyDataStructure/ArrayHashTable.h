#ifndef ARRAYHASHTABLE_H
#define ARRAYHASHTABLE_H

#include "ArrayList.h"

typedef struct  ArrayHashTable
{
	char **hashtable;
	int tablesize;
	int collision;
} arrayhashtable;

arrayhashtable *initArrayHashTable(int size);



int hash(arrayhashtable *ht, char*data);



void insertArrayHashTable(arrayhashtable *ht, char *data);

int findArrayHashTable(arrayhashtable *ht, char *data);
int deleteArrayHashTable(arrayhashtable *ht, char *data);


double getLoadFactor(arrayhashtable *ht);

void printArrayHashTable(arrayhashtable *ht);



#endif // !ARRAYHASHTABLE_H
#pragma once
