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
linkedlist *initLinkedList();		//初始化链表 返回一个链表的指针，其中size是0；头指针为空

void insertIndexOf(linkedlist *ll, int index, int value);		//向某个index插入值
void append(linkedlist *ll, int value);		//向链表后添加一个值
int removeIndexOf(linkedlist*ll, int index);		//从链表里删除某个值
void printLinkedList(linkedlist* ll);		//打印链表
llnode *findIndexOf(linkedlist* ll, int index);		//找到链表中某位置的值 并返回他

void freeLinkedList(linkedlist *ll);	//释放链表空间

#endif // !LINKEDLIST_H
