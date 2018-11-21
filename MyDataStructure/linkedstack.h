#ifndef LINKEDSTACK_H
#define LINKEDSTACK_H
#include "linkedlist.h"

typedef struct _LinkedStack
{
	linkedlist *ll;
	int top;
} linkedstack;

linkedstack *initLinkedstack();		//��ʼ����ջ
void push(linkedstack *as, int value);		//����ջѹ��һ���½ڵ�
int pop(linkedstack *ls);		//����ջȡ�������浥���ڵ�
int tos(linkedstack *ls);		//������ջ��topָ��ָ���ֵ
void printLinkedStack(linkedstack *ls);		//��ӡ��ջ�����е�ֵ
void freeLinkedStack(linkedstack *ls);		//�ͷ���ջ������пռ�




#endif // !LINKEDSTACK_H

