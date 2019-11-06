#pragma once
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct _LinkedListNode
{
	int data;
	char* ch;
	struct _LinkedListNode* next;
} llnode;

typedef struct _LinkedList
{
	llnode* head;
	int size;
} singlelinkedlist;

llnode* initLinkedIntNode(int value);

singlelinkedlist* initSingleLinkedList();		//��ʼ������ ����һ�������ָ�룬����size��0��ͷָ��Ϊ��

//int ��غ���
void insertSingleLinkedListIndexOf(singlelinkedlist* ll, int index, int value);		//��ĳ��index����ֵ

void singleLinkedAppend(singlelinkedlist* ll, int value);		//����������һ��ֵ

int removeSingleLinkedListIndexOf(singlelinkedlist* ll, int index);		//��������ɾ��ĳ��ֵ

void printLinkedList(singlelinkedlist* ll);		//��ӡ����

llnode* findIndexOf(singlelinkedlist* ll, int index);		//�ҵ�������ĳλ�õ�ֵ ��������

int isSingleLinkedListEmpty(singlelinkedlist* ll);

void freeLinkedList(singlelinkedlist* ll);	//�ͷ�����ռ�

//char��غ���
llnode* initLinkedCharNode(char* ch);

//������ʵ��linkedhash
void addSingleLinkedListFront(singlelinkedlist* ll, char* ch);

int findCharInSingleLinkedList(singlelinkedlist* ll, char* ch);

void printCharSingleLinkedList(singlelinkedlist* ll);

#endif // !LINKEDLIST_H
