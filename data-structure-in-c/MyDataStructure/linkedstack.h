#ifndef LINKEDSTACK_H
#define LINKEDSTACK_H

#include "SingleLinkedList.h"

typedef struct _LinkedStack
{
	singlelinkedlist* ll;
	int top;
} linkedstack;

linkedstack* initLinkedstack();		//��ʼ����ջ

void linkedPush(linkedstack* as, int value);		//����ջѹ��һ���½ڵ�

int linkedPop(linkedstack* ls);		//����ջȡ�������浥���ڵ�

int linkedTos(linkedstack* ls);		//������ջ��topָ��ָ���ֵ

void printLinkedStack(linkedstack* ls);		//��ӡ��ջ�����е�ֵ

void freeLinkedStack(linkedstack* ls);		//�ͷ���ջ������пռ�

#endif // !LINKEDSTACK_H

