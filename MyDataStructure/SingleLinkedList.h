#pragma once
#ifndef LINKEDLIST_H
#define LINKEDLIST_H


typedef struct _LinkedListNode 
{
	int data;
	_LinkedListNode *next;
} llnode;

typedef struct _LinkedList
{
	llnode *head;
	int size;
} singlelinkedlist;


llnode *initLinkedNode(int value);
singlelinkedlist *initLinkedList();		//��ʼ������ ����һ�������ָ�룬����size��0��ͷָ��Ϊ��

void insertIndexOf(singlelinkedlist *ll, int index, int value);		//��ĳ��index����ֵ
void append(singlelinkedlist *ll, int value);		//����������һ��ֵ
int removeIndexOf(singlelinkedlist*ll, int index);		//��������ɾ��ĳ��ֵ
void printLinkedList(singlelinkedlist* ll);		//��ӡ����
llnode *findIndexOf(singlelinkedlist* ll, int index);		//�ҵ�������ĳλ�õ�ֵ ��������

void freeLinkedList(singlelinkedlist *ll);	//�ͷ�����ռ�

#endif // !LINKEDLIST_H
