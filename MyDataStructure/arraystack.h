#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H
#include"ZHeader.h"

typedef struct _ArrayStack
{
	arraylist *al;
	int top;
} arraystack;

arraystack *initArraystack();		//��ʼ������ջ
void push(arraystack *as, int value);		//������ջ��ѹ��ֵ
int pop(arraystack *as);		//������ջ���ó�ֵ
int tos(arraystack *as);		//����topֵ
void printArrayStack(arraystack *as);		//��ӡ����ջ
void freeArrayStack(arraystack *as);		//�ͷ�����ջ

#endif // !ARRAYSTACK_H
#pragma once
