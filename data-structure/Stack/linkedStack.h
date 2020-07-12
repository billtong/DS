#pragma once

#include "../stdafx.h"

typedef struct
{
	pSLNode root;
} LinkedStack;

LinkedStack* createLinkedStack();
int isLinkedStackEmpty(LinkedStack*);
void pushLinkedStack(LinkedStack*, int);
int popLinkedStack(LinkedStack*);
int peekLinkedStack(LinkedStack*);
void destroyLinkedStack(LinkedStack*);

