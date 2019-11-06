#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include"ZHeader.h"

typedef struct _ArrayList
{
	int* arr;
	int size;		//the total size of the whole arraylist
	int used;		//the used size of the arraylist
} arraylist;

/*
给arraylist结构体分配内存空间，
给数组初始化，长度为10，值为0，
size为10，used为0
*/
arraylist* initArrayList();

void append(arraylist* al, int value);

void insertIndexOf(arraylist* al, int index, int value);

int removeIndexOf(arraylist* al, int index);

int removeValueOf(arraylist* al, int value);

void printArrayList(arraylist* al);

void freeArrayList(arraylist* al);

#endif // !ARRAYLIST_H
#pragma once
