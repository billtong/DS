#ifndef LINKEDSTACK_H
#define LINKEDSTACK_H

#include "SingleLinkedList.h"

typedef struct _LinkedStack
{
	singlelinkedlist* ll;
	int top;
} linkedstack;

linkedstack* initLinkedstack();		//初始化链栈

void linkedPush(linkedstack* as, int value);		//向链栈压入一个新节点

int linkedPop(linkedstack* ls);		//从链栈取出最上面单独节点

int linkedTos(linkedstack* ls);		//返回链栈的top指针指向的值

void printLinkedStack(linkedstack* ls);		//打印链栈里所有的值

void freeLinkedStack(linkedstack* ls);		//释放链栈里的所有空间

#endif // !LINKEDSTACK_H

