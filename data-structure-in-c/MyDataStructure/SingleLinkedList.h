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

singlelinkedlist* initSingleLinkedList();		//初始化链表 返回一个链表的指针，其中size是0；头指针为空

//int 相关函数
void insertSingleLinkedListIndexOf(singlelinkedlist* ll, int index, int value);		//向某个index插入值

void singleLinkedAppend(singlelinkedlist* ll, int value);		//向链表后添加一个值

int removeSingleLinkedListIndexOf(singlelinkedlist* ll, int index);		//从链表里删除某个值

void printLinkedList(singlelinkedlist* ll);		//打印链表

llnode* findIndexOf(singlelinkedlist* ll, int index);		//找到链表中某位置的值 并返回他

int isSingleLinkedListEmpty(singlelinkedlist* ll);

void freeLinkedList(singlelinkedlist* ll);	//释放链表空间

//char相关函数
llnode* initLinkedCharNode(char* ch);

//方便于实现linkedhash
void addSingleLinkedListFront(singlelinkedlist* ll, char* ch);

int findCharInSingleLinkedList(singlelinkedlist* ll, char* ch);

void printCharSingleLinkedList(singlelinkedlist* ll);

#endif // !LINKEDLIST_H
