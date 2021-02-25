#include "main.h"

int main()
{
#if ARRAY_LIST_TEST_ENABLE
	ArrayList *pAL = createArrayList();
	for (int i = 0; i <= 11; i++)
	{
		insertArrayList(pAL, i, 0);
		traverseArrayList(pAL);
	}
	printf("%d\n", findValueOfArrayList(pAL, 10));
	printf("%d\n", findValueOfArrayList(pAL, 100));
	for (int i = 0; i <= 11; i++)
	{
		removeIndexOfArrayList(pAL, 0);
		traverseArrayList(pAL);
	}
	destroyArrayList(pAL);
#endif // ARRAY_LIST_TEST_ENABLE
#if SINGLE_LINKED_LIST_TEST_ENABLE
	SingleLinkedList *pSLL = createSingleLinkedList();
	for (int i = 0; i < 10; i++)
	{
		insertSingleLinkedList(pSLL, i, 0);
		printLinkedNodes(pSLL->head);
	}
	printf("return value of 3 in single linked list %d\n", findValueOfSingleLinkedList(pSLL, 3)->value);
	printf("return value of -1 in singlelinked list %x\n", findValueOfSingleLinkedList(pSLL, -1));
	/*for (int i = 9; i >=0; i--)
	{
		removeIndexOfSingleLinkedList(pSLL, i);
		printSingleLinkedList(pSLL);
	}*/
	destroySingleLinkedList(pSLL);
#endif // SINGLE_LINKED_LIST_TEST_ENABLE
#if ARRAY_STACK_TEST_ENABLE
	ArrayStack *pAS = createArrayStack(20);
	for (int i = 0; i < 10; i++)
	{
		pushArrayStack(pAS, i);
	}
	printf("peek the array stack %d\n", peekArrayStack(pAS));
	destroyArrayStack(pAS);
#endif // ARRAY_STACK_TEST_ENABLE
#if LINKED_STACK_TEST_ENABLE
	LinkedStack *pLS = createLinkedStack();
	for (int i = 0; i < 10; i++)
	{
		pushLinkedStack(pLS, i);
	}
	printf("peek the array stack %d\n", peekLinkedStack(pLS));
	destroyLinkedStack(pLS);
#endif // LINKED_STACK_TEST_ENABLE
#if ARRAY_QUEUE_TEST_ENABLE
	pArrayQueue pAQ = createArrayQueue();
	for (int i = 0; i < 10; i++)
	{
		enArrayQueue(pAQ, i);
		traverseArrayQueue(pAQ);
	}
	for (int i = 0; i < 5; i++)
		printf("%d\n", deArrayQueue(pAQ));
	traverseArrayQueue(pAQ);
	destroyArrayQueue(pAQ);
#endif // ARRAY_QUEUE_TEST_ENABLE
#if LINKED_QUEUE_TEST_ENABLE
	LinkedQueue *pLQ = createLinkedQueue();
	for (int i = 0; i < 10; i++)
	{
		enLinkedQueue(pLQ, i);
		traverseLinkedQueue(pLQ);
	}
	for (int i = 0; i < 5; i++)
		printf("%d\n", deLinkedQueue(pLQ));
	traverseLinkedQueue(pLQ);
	destroyLinkedQueue(pLQ);
#endif // LINKED_QUEUE_TEST_ENABLE
#if CIRCULAR_QUEUE_TEST_ENABLE
	CircularQueue *pCQ = createCircularQueue(10);
	traverseCircularQueue(pCQ);
	for (int i = 0; i < 10; i++)
	{
		enCircularQueue(pCQ, i);
		traverseCircularQueue(pCQ);
	}
	for (int i = 0; i < 10; i++)
	{
		deCircularQueue(pCQ);
		enCircularQueue(pCQ, -1);
		traverseCircularQueue(pCQ);
	}
	destroyCircularQueue(pCQ);
#endif // CIRCULAR_QUEUE_TEST_ENABLE
#if BINARY_TREE_TEST_ENABLE
	pBTNode pBT = NULL;
	getSampleBinaryTree(&pBT);
	printf("sample binary tree height: %d\n", getBinaryTreeNodeHeight(pBT));
	preorderBinaryTree(pBT);
	printf("\n");
	inorderBinaryTree(pBT);
	printf("\n");
	postorderBinaryTree(pBT);
	printf("\n");
	breathFirstTraverseBinaryTree(pBT);
	destroyBinaryTree(pBT);
#endif // BINARY_TREE_TEST_ENABLE
#if BINARY_SEARCH_TREE_TEST_ENABLE
	pBTNode pBSTRoot = createBinaryTreeNode(10);
	for (int i = 0; i < 10; i++)
	{
		pBSTRoot = insertBinarySearchTree(pBSTRoot, 10 - i);
		pBSTRoot = insertBinarySearchTree(pBSTRoot, 10 + i);
	}
	preorderBinaryTree(pBSTRoot);
	printf("\n");
	pBSTRoot = removeValueOfBinarySearchTree(pBSTRoot, 10);
	preorderBinaryTree(pBSTRoot);
	printf("\n");
	destroyBinaryTree(pBSTRoot);
#endif // BINARY_SEARCH_TREE_TEST_ENABLE
#if AVL_BINARY_TREE_TEST_ENABLE
	pAVLNODE pAVLRoot = createAVLTreeNode(10);
	for (int i = 0; i < 6; i++)
	{
		pAVLRoot = insertValueOfAVLTree(pAVLRoot, 10 - i);
		pAVLRoot = insertValueOfAVLTree(pAVLRoot, 10 + i);
	}
	preorderAVLTree(pAVLRoot);
	printf("\n");
	pAVLRoot = removeValueOfAVLTree(pAVLRoot, 10);
	preorderAVLTree(pAVLRoot);
	printf("\n");
	destroyAVLTree(pAVLRoot);
#endif // AVL_BINARY_TREE_TEST_ENABLE
#if BINARY_HEAP_TEST_ENABLE
	int size = 15;
	int *arr = (int *)malloc(sizeof(int) * size);
	for (int i = 0; i < size; i++)
		arr[i] = rand() % 90;
	printArray(arr, size);
	BinaryHeap *pBH = createBinaryHeapFromArray(arr, size);
	arr = heapSort(pBH->arr, size);
	printArray(arr, size);
#endif // BINARY_HEAP_TEST_ENABLE
#if LINKED_HASH_TEST_ENABLE
	int lht_size = 5;
	LinkedHashTable *ht = createLinkedHashTable(lht_size);
	for (int i = 0; i < 20; i++)
	{
		int x = rand() % 5 + 1;
		char *ch = (char *)malloc(sizeof(char) * x);
		for (int j = 0; j < x; j++)
		{
			ch[j] = rand() % 26 + 97;
		}
		ch[x] = '\0';
		ht = insertLinkedHashTable(ht, ch);
	}
	traverseLinkedHashTable(ht);
	printf("# of Collisions=%d\n", ht->collision);
	printf("Load Factor %%=%.2f\n", calcLoadFactor(ht));
#endif // LINKED_HASH_TEST_ENABLE

	return 0;
}