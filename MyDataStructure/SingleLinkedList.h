#pragma once
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include"ZHeader.h"

typedef struct _LinkedListNode 
{
	int data;
	char *ch;
	_LinkedListNode *next;
} llnode;

typedef struct _LinkedList
{
	llnode *head;
	int size;
} singlelinkedlist;


llnode *initLinkedNode(int value);
llnode *initLinkedNode(char *ch);
singlelinkedlist *initSingleLinkedList();		//��ʼ������ ����һ�������ָ�룬����size��0��ͷָ��Ϊ��

void insertIndexOf(singlelinkedlist *ll, int index, int value);		//��ĳ��index����ֵ
void append(singlelinkedlist *ll, int value);		//����������һ��ֵ
int removeIndexOf(singlelinkedlist*ll, int index);		//��������ɾ��ĳ��ֵ
void printLinkedList(singlelinkedlist* ll);		//��ӡ����
void printCharSingleLinkedList(singlelinkedlist *ll);


llnode *findIndexOf(singlelinkedlist* ll, int index);		//�ҵ�������ĳλ�õ�ֵ ��������
bool isSingleLinkedListEmpty(singlelinkedlist *ll);


void freeLinkedList(singlelinkedlist *ll);	//�ͷ�����ռ�


void addSingleLinkedListFront(singlelinkedlist *ll, char *ch);//������ʵ��linkedhash
int findCharInSingleLinkedList(singlelinkedlist *ll, char *ch);

#endif // !LINKEDLIST_H
