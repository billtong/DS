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
} linkedlist;


llnode *initLinkedNode(int value);
linkedlist *initLinkedList();		//��ʼ������ ����һ�������ָ�룬����size��0��ͷָ��Ϊ��

void insertIndexOf(linkedlist *ll, int index, int value);		//��ĳ��index����ֵ
void append(linkedlist *ll, int value);		//����������һ��ֵ
int removeIndexOf(linkedlist*ll, int index);		//��������ɾ��ĳ��ֵ
void printLinkedList(linkedlist* ll);		//��ӡ����
llnode *findIndexOf(linkedlist* ll, int index);		//�ҵ�������ĳλ�õ�ֵ ��������

void freeLinkedList(linkedlist *ll);	//�ͷ�����ռ�

#endif // !LINKEDLIST_H
