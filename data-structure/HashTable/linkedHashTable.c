#include "linkedHashTable.h"

LinkedHashTable* createLinkedHashTable(int size)
{
	LinkedHashTable* pHash = (LinkedHashTable*)malloc(sizeof(LinkedHashTable));
	if (pHash == NULL)
		return NULL;
	pHash->size = size;
	pHash->collision = 0;
	pHash->hashList = (pSLList*)malloc(sizeof(SingleLinkedList) * size);
	for (int i = 0; i < size; i++)
		pHash->hashList[i] = createSingleLinkedList();
	return pHash;
}

long hashString(char* pString)
{
	long sum = 0;
	int l = strlen(pString);
	for (int i=0; pString[i] != '\0'; i++)
		sum += (pString[i] * (long)pow(31.0, l - i - 1));
	return sum;
}

int divisionHash(LinkedHashTable* pHash, char* pString)
{
	return hashString(pString) % pHash->size;
}

double calcLoadFactor(LinkedHashTable* pHash)
{
	double n = 0;
	for (int i = 0; i < pHash->size; i++) {
		if (pHash->hashList[i]->size > 0)
			n++;
	}
	return (n / pHash->size) * 100;
}

void rehashLinkedHashTable(LinkedHashTable** ht)
{
	if (ht && *ht)
	{
		LinkedHashTable* pOldHash = *ht;
		*ht = createLinkedHashTable(pOldHash->size * 2);
		for (int i = 0; i < pOldHash->size; i++) {
			if (pOldHash->hashList[i] > 0) {
				pSLNode iter = pOldHash->hashList[i]->head;
				while (iter) {
					insertLinkedHashTable(*ht, iter->value);
					iter = iter->next;
				}
			}
		}
	}
}

LinkedHashTable* insertLinkedHashTable(LinkedHashTable* pHash, char* pString)
{
	int key = divisionHash(pHash, pString);
	pSLList temp = pHash->hashList[key];
	if (temp->size > 0)
		pHash->collision++;
	insertSingleLinkedList(temp, pString, 0);
	if (calcLoadFactor(pHash) > 75)
		rehashLinkedHashTable(&pHash);
	return pHash;	//address needs to return back, because it might be changed by rehash function
}

void traverseLinkedHashTable(LinkedHashTable* pHash)
{
	for (int i = 0; i < pHash->size; i++)
	{
		printf("%d:\t", i);
		pSLNode pNode = pHash->hashList[i]->head;
		while (pNode != NULL)
		{
			printf("%s ", (char*)pNode->value);
			pNode = pNode->next;
		}
		printf("\n");
	}
}
