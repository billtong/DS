/*
Array is a collection of items stored at contiguous memory locations. The idea is to store
multiple items of the same type together, making it easier to calculate the position of each
element by simply adding an offset to a base value.
pros:
fast access to elements by index
fast iteration by index
cons:
only one type per array list
insertion and deletion of elements can be costly
*/
#pragma once

#include "../stdafx.h"

#define ARRAY_LIST_INITIAL_SIZE 10

typedef struct
{
	int* arr;
	int size;
	int used;
} ArrayList;

/*
no param
return value: an 10 sized empty(0) filled arraylist structure instance pointer
*/
ArrayList* createArrayList();

/*
first param: a pointer to the arraylist
second param: value to be inserted into the array list
third param: the index at which the value will be inserted, start from 0
return value: 0 is error, others are success.
*/
void insertArrayList(ArrayList*, int, int);

/*
first param: a pointer to the array list sturcture instance
second param: the index at the array to be removed, start from 0
*/
void removeIndexOfArrayList(ArrayList*, int);

/*
first param: a pointer to the array list structure instance
second param: the value to find within the array list
*/
int findValueOfArrayList(ArrayList*, int);

/*
first param: a pointer to the array list structure instance
second param: the index to find within the array list
*/
int findIndexOfArrayList(ArrayList*, int);

/*
first param: pointer to an structure instance to be free
*/
void destroyArrayList(ArrayList*);

void traverseArrayList(ArrayList*);
