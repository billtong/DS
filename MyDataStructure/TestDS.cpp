#include"ZHeader.h"


int isTestingArrayList = 0;
int isTestingLinkedList = 0;
int isTestArrayStack = 0;
int isTestLinkedStack = 0;
int isTestArrayQueue = 0;
int isTestLinkedQueue = 0;
int isTestCircularQueue = 0;
int isTestingBinaryTree = 0;
int isTestingSearchTree = 0;
int isTestingAVLBinaryTree = 0;
int isTestingLinkedHash = 0;
int isTestingArrayBinaryHeap = 1;



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
		singlelinkedlist *ll = initSingleLinkedList();
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

//hash---------------------------------------------------------------------------------------------------------------------------------------------------------
	if (isTestingLinkedHash) {
		int size = 5;
		linkedhashtable *ht = initLinkedHashTable(size);
		
		for (int i = 0; i < 20; i++) {
			int x = rand() % 5 + 1;
			char *ch = (char *)malloc(sizeof(char) * x);
			for (int j = 0; j < x; j++) {
				ch[j] = rand() % 26 + 97;
			}
			ch[x] = '\0';
			ht = insertLinkedHash(ht, ch);
		}

		int a[] = { 9,11,20,15,40,9,16,27 };
		

		printLinkedHash(ht);
		printf("# of Collisions=%d\n", ht->collision);
		printf("Load Factor %%=%.2f\n", calcLoadFactor(ht));

	}


	if (isTestingArrayBinaryHeap) {
		int size = 15;
		int *arr = (int *)malloc(sizeof(int) * size);
		for (int i = 0; i < size; i++) {
			arr[i] = rand() % 100;
		}
		arraybinaryheap *heap = arrayMinHeapify(arr, size);
		arr = heapSort(heap->a, size);
		for (int i = 0; i < size; i++) {
			printf("%d ", arr[i]);
		}

	}



	system("pause");
	return 0;
}

