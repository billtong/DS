#include"ZHeader.h"

/*
不想执行的测试代码块，把define的值改为0
*/
#define ARRAY_LIST_TEST 0
#define LINKED_LIST_TEST 0
#define ARRAY_STACK_TEST 0
#define LINKED_STACK_TEST 0
#define ARRAY_QUEUE_TEST 0
#define LINKED_QUEUE_TEST 0
#define CIRCULAR_QUEUE_TEST 0
#define BINARY_TREE_TEST 0
#define BINARY_SEARCH_TREE_TEST 0
#define AVL_BINARY_TREE_TEST 0
#define LINKED_HASH_TEST 0
#define ARRAY_BINARY_HEAP_TEST 0
#define ARRAY_HASH_TEST 0
#define DIRECTED_GRAPH_TEST 0

int main()
{
#if ARRAY_LIST_TEST
	arraylist* al = initArrayList();
	printf("start append to arraylist\n");
	for (int i = 0; i < 15; i++) {
		append(al, i);
		printf("used: %d, size: %d\n", al->used, al->size);
	}
	printf("end append to arraylist\n\n");
	printf("start remove from arraylist\n");
	for (int i = 0; i < 15; i++) {
		removeValueOf(al, i);
		printf("used: %d, size: %d\n", al->used, al->size);
	}
	printf("end remove from arraylist\n\n");
	freeArrayList(al);
#endif // ARRAY_LIST_TEST

#if LINKED_LIST_TEST
	singlelinkedlist* ll = initSingleLinkedList();
	printLinkedList(ll);
	for (int i = 1; i < 10; i++) {
		singleLinkedAppend(ll, i);
	}
	printLinkedList(ll);
	insertSingleLinkedListIndexOf(ll, ll->size, 111);
	printLinkedList(ll);
	freeLinkedList(ll);
#endif
#if ARRAY_STACK_TEST 
	arraystack* as = initArraystack();
	for (int i = 0; i < 20; i++) {
		push(as, i);
	}
	printArrayStack(as);
	for (int i = 0; i < 20; i++) {
		printf("pop: %d\n", pop(as));
	}
	printArrayStack(as);
	freeArrayStack(as);
#endif
#if LINKED_STACK_TEST
	linkedstack* ls = initLinkedstack();
	for (int i = 0; i < 20; i++) {
		linkedPush(ls, i);
	}
	printLinkedStack(ls);
	for (int i = 0; i < 20; i++) {
		linkedPop(ls);
	}
	printLinkedStack(ls);
	freeLinkedStack(ls);
#endif
#if ARRAY_QUEUE_TEST
	arrayqueue* aq = initArrayQueue();
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
#endif // ARRAY_QUEUE_TEST
#if LINKED_QUEUE_TEST
	linkedqueue* lq = initLinkedQueue();
	for (int i = 0; i < 11; i++) {
		linkedEnqueue(lq, i);
		prinLinkedQueue(lq);
	}
	for (int i = 0; i < 11; i++) {
		linkedDequeue(lq);
		prinLinkedQueue(lq);
	}
	freeLinkedQueue(lq);
#endif // LINKED_QUEUE_TEST

#if CIRCULAR_QUEUE_TEST
	int size = 10;
	circularqueue* cq = initCircularQueue(10);
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
#endif // CIRCULAR_QUEUE_TEST

#if BINARY_TREE_TEST
	binarytree* bt = getBinaryTree(15);
	printf("the height of the tree: %d\n", bt->root);
	preoderPrintBinaryTree(bt->root);
	printf("\n");
	inorderPrintBinaryTree(bt->root);
	printf("\n");
	postorderPrintBinaryTree(bt->root);
	printf("\n");
	printf("\ntree height: %d\n", getBinaryTreeHeight(bt->root));
	binarytreenode* node = findNodeByKey(bt->root, 13);
	printf("find node of key 13:	%d\n", node->key);
	node = findParentNode(bt->root, 13);
	printf("find parent node of key 13: %d\n", node->key);
	breathfirstPrintBinaryTree(bt);
	freeBinaryTree(bt->root);
#endif // BINARY_TREE_TEST

#if BINARY_SEARCH_TREE_TEST
	binarysearchtree* bt = getSampleBinarySearchTree();
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
#endif // BINARY_SEARCH_TREE_TEST

#if AVL_BINARY_TREE_TEST
	avlbinarysearchtree* avl = initAVLBinaryTree();
	avl->root = insertAVLBinaryTree(avl->root, 1, 30);
	avl->root = insertAVLBinaryTree(avl->root, 1, 10);
	avl->root = insertAVLBinaryTree(avl->root, 1, 20);
	avl->root = insertAVLBinaryTree(avl->root, 1, 100);
	avl->root = insertAVLBinaryTree(avl->root, 1, 102);
	avl->root = insertAVLBinaryTree(avl->root, 1, 25);
	avl->root = insertAVLBinaryTree(avl->root, 1, 50);
	avl->root = deleteAVLBinaryTree(avl->root, 30);
	preoderPrintBinaryTree(avl->root);
#endif // AVL_BINARY_TREE_TEST

#if LINKED_HASH_TEST
	int lht_size = 5;
	linkedhashtable* ht = initLinkedHashTable(size);
	for (int i = 0; i < 20; i++) {
		int x = rand() % 5 + 1;
		char* ch = (char*)malloc(sizeof(char) * x);
		for (int j = 0; j < x; j++) {
			ch[j] = rand() % 26 + 97;
		}
		ch[x] = '\0';
		ht = insertLinkedHash(ht, ch);
	}
	printLinkedHash(ht);
	printf("# of Collisions=%d\n", ht->collision);
	printf("Load Factor %%=%.2f\n", calcLoadFactor(ht));
#endif // LINKED_HASH_TEST

#if ARRAY_BINARY_HEAP_TEST
	int abh_size = 15;
	int* arr = (int*)malloc(sizeof(int) * size);
	for (int i = 0; i < size; i++) {
		arr[i] = rand() % 100;
	}
	arraybinaryheap* heap = arrayMinHeapify(arr, size);
	arr = heapSort(heap->a, size);
	for (int i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
#endif // ARRAY_BINARY_HEAP_TEST

#if ARRAY_HASH_TEST
	arrayhashtable* ht = initArrayHashTable(19);
	for (int i = 0; i < 20; i++) {
		int x = rand() % 5 + 1;
		char* ch = (char*)malloc(sizeof(char) * x);
		for (int j = 0; j < x; j++) {
			ch[j] = rand() % 26 + 97;
		}
		ch[x] = '\0';
		insertArrayHashTable(ht, ch);
		if (i == 10) {
			deleteArrayHashTable(ht, ch);
		}
		printf("%s is in %d \n%", ch, findArrayHashTable(ht, ch));
	}
	printArrayHashTable(ht);
	printf("# of Collisions=%d\n", ht->collision);
	printf("# of LoadFactor=%.2f\n", getLoadFactor(ht));
#endif // (ARRAY_HASH_TEST

#if DIRECTED_GRAPH_TEST
	edge edges[] =
	{
		{0, 5},{2, 6}, {3, 1}, {5, 1}, {2, 4},{5, 9}, {9, 2}, {4, 3}, {7, 9}, {8, 7}, {1,8}
	};
	int verticeNum = 10;
	int edgesNum = sizeof(edges) / sizeof(edge);
	graph* myg = createGraph(edges, edgesNum, verticeNum);
	printDirectedGraph(myg);
	BreadthFirstTraversalDirectedGraph(myg, 0);
	DepthFirstTraversalDirectedGraph(myg, 0);
#endif // DIRECTED_GRAPH_TEST

	system("pause");
	return 0;
}
