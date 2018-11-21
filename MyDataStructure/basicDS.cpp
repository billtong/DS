#include<stdlib.h>
#include<stdio.h>
#include "arraylist.h"
#include "SingleLinkedList.h"
#include "arraystack.h"
#include "linkedstack.h"
#include "arrayqueue.h"
#include "linkedqueue.h"
#include"circularqueue.h"
#include "binarytree.h"
#include "binarysearchtree.h"
#include "avlbinarysearchtree.h"

int isTestingArrayList = 0;
int isTestingLinkedList = 1;
int isTestArrayStack = 0;
int isTestLinkedStack = 1;
int isTestArrayQueue = 0;
int isTestLinkedQueue = 1;
int isTestCircularQueue = 0;
int isTestingBinaryTree = 0;
int isTestingSearchTree = 0;
int isTestingAVLBinaryTree = 0;

int main()
{
//list---------------------------------------------------------------------------------------------------------------------------------------------------------
	if (isTestingArrayList) {
		arraylist *al = initArrayList();
		for (int i = 0; i < 15; i++) {
			append(al, i);
			printf("used: %d	size: %d\n",al->used,al->size);
		}

		for (int i = 0; i < 15; i++) {
			removeValueOf(al, i);
			printf("used: %d	size: %d\n", al->used, al->size);
		}
		freeArrayList(al);
	}

	if (isTestingLinkedList) {
		singlelinkedlist *ll = initLinkedList();
		printLinkedList(ll);
		for (int i = 1; i < 10; i++) {
			append(ll, i);
		}
		printLinkedList(ll);
		insertIndexOf(ll, ll->size, 111);

		printLinkedList(ll);
		freeLinkedList(ll);
	}

//stack-------------------------------------------------------------------------------------------------------------------------------------------------------
	if (isTestArrayStack) {
		arraystack *as = initArraystack();
		for (int i = 0; i < 20; i++) {
			push(as, i);
		}
		printArrayStack(as);
		for (int i = 0; i < 20; i++) {
			printf("pop: %d\n", pop(as));
		}
		printArrayStack(as);
		freeArrayStack(as);
	}

	if (isTestLinkedStack) {
		linkedstack *ls = initLinkedstack();
		for (int i = 0; i < 20; i++) {
			push(ls, i);
		}
		printLinkedStack(ls);
		for (int i = 0; i < 20; i++) {
			pop(ls);
		}
		printLinkedStack(ls);
		freeLinkedStack(ls);
	}

//queue-------------------------------------------------------------------------------------------------------------------------------------------------------
	if (isTestArrayQueue) {
		arrayqueue *aq = initArrayQueue();
		printArrayQueue(aq);
		for (int i = 0; i < 11; i++) {
			enqueue(aq, i);
			printArrayQueue(aq);
		}
		printArrayQueue(aq);
		for (int i = 0; i < 11; i++) {
			dequeue(aq);
			printArrayQueue(aq);
		}
		printArrayQueue(aq);
		freeArrayQueue(aq);
	}
	
	if (isTestLinkedQueue) {
		linkedqueue *lq = initLinkedQueue();
		for (int i = 0; i < 11; i++) {
			enqueue(lq, i);
			prinLinkedQueue(lq);
		}
		
		for (int i = 0; i < 11; i++) {
			dequeue(lq);
			prinLinkedQueue(lq);
		}
		freeLinkedQueue(lq);
	}

	if (isTestCircularQueue) {
		int size = 10;

		circularqueue *cq = initCircularQueue(10);
		for (int i = 0; i < size; i++) {
			enCircularQueue(cq, i);
			//printCircularQueue(cq);
			//printf("\n");
		}

		for (int i = 0; i < size; i++) {
			deCircularQueue(cq);
			enCircularQueue(cq, i);
			printCircularQueue(cq);
			printf("\n");
		}
	}


//tree---------------------------------------------------------------------------------------------------------------------------------------------------------

	if (isTestingBinaryTree) {
		binarytree *bt = getBinaryTree(15);
		printf("the height of the tree: %d\n", bt->root);
		preoderPrintBinaryTree(bt->root);
		printf("\n");
		inorderPrintBinaryTree(bt->root);
		printf("\n");
		postorderPrintBinaryTree(bt->root);
		printf("\n");
		printf("\ntree height: %d\n", getBinaryTreeHeight(bt->root));
		binarytreenode *node = findNodeByKey(bt->root, 13);
		printf("find node of key 13:	%d\n", node->key);
		node = findParentNode(bt->root, 13);
		printf("find parent node of key 13: %d\n", node->key);
		breathfirstPrintBinaryTree(bt);

		freeBinaryTree(bt->root);
	}

	if (isTestingSearchTree) {

		binarysearchtree *bt = getSampleBinarySearchTree();

		preoderPrintBinaryTree(bt->root);
		printf("\n");
		printf("find the max key in the bt: %d\n", (findMaxBinarySearchTree(bt->root))->key);
		printf("find the min key in the bt: %d\n", (findMinBinarySearchTree(bt->root))->key);
		printf("find the key 13 node value in the bt: %d\n", (findBinarySearchTree(bt->root, 13)->value));


		printf("delete the key 30 node value in the bt: \n");
		bt->root = deleteBinarySearchTree(bt->root, 30);
		preoderPrintBinaryTree(bt->root);
		printf("\n");

		printf("delete the key 13 node value in the bt: \n");
		bt->root = deleteBinarySearchTree(bt->root, 13);
		preoderPrintBinaryTree(bt->root);
		printf("\n");
	}

	if (isTestingAVLBinaryTree) {
		avlbinarysearchtree *avl = initAVLBinaryTree();

		avl->root = insertAVLBinaryTree(avl->root, 1, 30);
		avl->root = insertAVLBinaryTree(avl->root, 1, 10);
		avl->root = insertAVLBinaryTree(avl->root, 1, 20);
		avl->root = insertAVLBinaryTree(avl->root, 1, 100);
		avl->root = insertAVLBinaryTree(avl->root, 1, 102);
		avl->root = insertAVLBinaryTree(avl->root, 1, 25);
		avl->root = insertAVLBinaryTree(avl->root, 1, 50);

		avl->root = deleteAVLBinaryTree(avl->root, 30);



		preoderPrintBinaryTree(avl->root);

	}

	system("pause");
	return 0;
}

