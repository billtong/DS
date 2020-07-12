#pragma once

#include "../stdafx.h"

typedef struct
{
	int top;
	unsigned int capacity;
	int* arr;
} ArrayStack;

ArrayStack* createArrayStack(unsigned int capacity);
int IsArrayStackFull(ArrayStack*);
int IsArrayStackEmpty(ArrayStack*);
void pushArrayStack(ArrayStack*, int);
int popArrayStack(ArrayStack*);
int peekArrayStack(ArrayStack*);
void destroyArrayStack(ArrayStack*);