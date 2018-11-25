#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H
#include"ZHeader.h"

typedef struct _ArrayStack
{
	arraylist *al;
	int top;
} arraystack;

arraystack *initArraystack();		//初始化线性栈
void push(arraystack *as, int value);		//向线性栈中压入值
int pop(arraystack *as);		//从线性栈中拿出值
int tos(arraystack *as);		//返回top值
void printArrayStack(arraystack *as);		//打印线性栈
void freeArrayStack(arraystack *as);		//释放线性栈

#endif // !ARRAYSTACK_H
#pragma once
