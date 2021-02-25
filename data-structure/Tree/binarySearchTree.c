#include "binarySearchTree.h"

pBTNode insertBinarySearchTree(pBTNode pRoot, int elem)
{
	if (pRoot == NULL)
		return createBinaryTreeNode(elem);
	else if (pRoot->key > elem)
		pRoot->left = insertBinarySearchTree(pRoot->left, elem);
	else if (pRoot->key < elem)
		pRoot->right = insertBinarySearchTree(pRoot->right, elem);
	return pRoot;
}

pBTNode findMinBinarySearchTree(pBTNode pRoot)
{
	if (pRoot && pRoot->left)
		return findMinBinarySearchTree(pRoot->left);
	return pRoot;
}

pBTNode findMaxBinarySearchTree(pBTNode pRoot)
{
	if (pRoot && pRoot->right)
		return findMaxBinarySearchTree(pRoot->right);
	return pRoot;
}

pBTNode findValueOfBinarySearchTree(pBTNode pRoot, int elem)
{
	if (pRoot == NULL)
		return NULL;
	else if (pRoot->key > elem)
		return findValueOfBinarySearchTree(pRoot->left, elem);
	else if (pRoot->key < elem)
		return findValueOfBinarySearchTree(pRoot->right, elem);
	else
		return pRoot;
}

pBTNode removeValueOfBinarySearchTree(pBTNode pRoot, int elem)
{
	if (pRoot == NULL)
		return NULL;
	if (pRoot->key > elem)
		pRoot->left = removeValueOfBinarySearchTree(pRoot->left, elem);
	else if (pRoot->key < elem)
		pRoot->right = removeValueOfBinarySearchTree(pRoot->right, elem);
	else
	{
		if (pRoot->right == NULL)
			pRoot = pRoot->left;
		else if (pRoot->left == NULL)
			pRoot = pRoot->right;
		else if (pRoot->left && pRoot->right)
		{
			pBTNode pLeftMax = findMaxBinarySearchTree(pRoot->left);
			pBTNode pRightMin = findMinBinarySearchTree(pRoot->right);
			int dist = 2 * pRoot->key - pLeftMax->key - pRightMin->key;
			if (dist <= 0) // closer to the left max nodes
			{
				pRoot->key = pLeftMax->key;
				pRoot->left = removeValueOfBinarySearchTree(pRoot->left, pLeftMax->key);
			}
			else
			{
				pRoot->key = pRightMin->key;
				pRoot->right = removeValueOfBinarySearchTree(pRoot->right, pRightMin->key);
			}
		}
	}
	return pRoot;
}
