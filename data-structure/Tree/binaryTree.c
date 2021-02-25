#include "BinaryTree.h"

pBTNode createBinaryTreeNode(int val)
{
	pBTNode pNode = (pBTNode)malloc(sizeof(BTNode));
	if (pNode == NULL)
		return NULL;
	pNode->key = val;
	pNode->left = pNode->right = NULL;
	return pNode;
}

int getBinaryTreeNodeHeight(pBTNode pNode)
{
	if (pNode == NULL)
		return -1;
	int nLeftHeight = getBinaryTreeNodeHeight(pNode->left);
	int nRightHeight = getBinaryTreeNodeHeight(pNode->right);
	return (nLeftHeight > nRightHeight ? nLeftHeight : nRightHeight) + 1;
}

void getSampleBinaryTree(pBTNode *ppRoot)
{
	pBTNode pNode1 = createBinaryTreeNode(10);
	pBTNode pNode2 = createBinaryTreeNode(20);
	pBTNode pNode3 = createBinaryTreeNode(30);
	pBTNode pNode5 = createBinaryTreeNode(50);
	pBTNode pNode7 = createBinaryTreeNode(70);
	pNode1->left = pNode2;
	pNode1->right = pNode3;
	pNode2->left = createBinaryTreeNode(40);
	pNode2->right = pNode5;
	pNode3->left = createBinaryTreeNode(60);
	pNode3->right = pNode7;
	pNode5->left = createBinaryTreeNode(80);
	pNode7->left = createBinaryTreeNode(90);
	*ppRoot = pNode1;
}

void preorderBinaryTree(pBTNode pTree)
{
	printf("{");
	if (pTree)
	{
		printf(" %d ", pTree->key);
		preorderBinaryTree(pTree->left);
		preorderBinaryTree(pTree->right);
	}
	printf("}");
}

void inorderBinaryTree(pBTNode pTree)
{
	printf("{");
	if (pTree)
	{
		preorderBinaryTree(pTree->left);
		printf(" %d ", pTree->key);
		preorderBinaryTree(pTree->right);
	}
	printf("}");
}

void postorderBinaryTree(pBTNode pTree)
{
	printf("{");
	if (pTree)
	{
		preorderBinaryTree(pTree->left);
		preorderBinaryTree(pTree->right);
		printf(" %d ", pTree->key);
	}
	printf("}");
}

void breathFirstTraverseBinaryTree(pBTNode pTree)
{
	printf("breath first traverse:\t");
	if (pTree)
	{
		LinkedQueue *pQueue = createLinkedQueue();
		enLinkedQueue(pQueue, pTree);
		while (!isLinkedQueueEmpty(pQueue))
		{
			pBTNode pNode = deLinkedQueue(pQueue);
			printf(" %d ", pNode->key);
			if (pNode->left)
				enLinkedQueue(pQueue, pNode->left);
			if (pNode->right)
				enLinkedQueue(pQueue, pNode->right);
		}
	}
	printf("\n");
}

void destroyBinaryTree(pBTNode pTree)
{
	if (pTree)
	{
		destroyBinaryTree(pTree->left);
		destroyBinaryTree(pTree->right);
		free(pTree);
	}
}
