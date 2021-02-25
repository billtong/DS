#include "avlTree.h"

pAVLNODE createAVLTreeNode(int key)
{
	pAVLNODE pNode = (pAVLNODE)malloc(sizeof(AVLNode));
	if (pNode == NULL)
		return NULL;
	pNode->height = 0;
	pNode->key = key;
	pNode->left = pNode->right = NULL;
	return pNode;
}

int preorderAVLTree(pAVLNODE pTree)
{
	printf("{");
	if (pTree)
	{
		printf(" %d,%d ", pTree->key, pTree->height);
		preorderAVLTree(pTree->left);
		preorderAVLTree(pTree->right);
	}
	printf("}");
}

int getAVLTreeNodeHeight(pAVLNODE pRoot)
{
	if (pRoot == NULL)
		return -1;
	int nLeftHeight = getAVLTreeNodeHeight(pRoot->left);
	int nRightHeight = getAVLTreeNodeHeight(pRoot->right);
	return (nLeftHeight > nRightHeight ? nLeftHeight : nRightHeight) + 1;
}

int getMinValueOfAVLTree(pAVLNODE pRoot)
{
	if (pRoot && pRoot->left)
		return getMinValueOfAVLTree(pRoot->left);
	return pRoot;
}

int getMaxValueOfAVLTree(pAVLNODE pRoot)
{
	if (pRoot && pRoot->right)
		return getMaxValueOfAVLTree(pRoot->right);
	return pRoot;
}

int getBalanceFactor(pAVLNODE pRoot)
{
	if (pRoot == NULL)
		return 0;
	int lh = pRoot->left ? pRoot->left->height + 1 : 0;
	int rh = pRoot->right ? pRoot->right->height + 1 : 0;
	return lh - rh;
}

pAVLNODE rotateLeft(pAVLNODE pRoot)
{
	if (pRoot)
	{
		pAVLNODE rc = pRoot->right;
		pRoot->right = rc->left;
		rc->left = pRoot;
		rc->height = getAVLTreeNodeHeight(rc);
		pRoot->height = getAVLTreeNodeHeight(pRoot);
		return rc;
	}
	return NULL;
}

pAVLNODE rotateRight(pAVLNODE pRoot)
{
	if (pRoot)
	{
		pAVLNODE rc = pRoot->left;
		pRoot->left = rc->right;
		rc->right = pRoot;
		rc->height = getAVLTreeNodeHeight(rc);
		pRoot->height = getAVLTreeNodeHeight(pRoot);
		return rc;
	}
	return NULL;
}

pAVLNODE rebalance(pAVLNODE root, int key)
{
	int balanceFactor = getBalanceFactor(root);
	if (balanceFactor > 1)
	{
		pAVLNODE rc = root->left;
		if (rc->key > key) //Left of Left
			return rotateRight(root);
		else if (rc->key < key)
		{ //left of right
			root->left = rotateLeft(root->left);
			return rotateRight(root);
		}
	}
	else if (balanceFactor < -1)
	{
		pAVLNODE rc = root->right;
		if (rc->key > key)
		{ //right of left
			root->right = rotateRight(root->right);
			return rotateLeft(root);
		}
		if (rc->key < key) // right of right
			return rotateLeft(root);
	}
	return root;
}

pAVLNODE insertValueOfAVLTree(pAVLNODE root, int key)
{
	if (root == NULL)
		return createAVLTreeNode(key);
	if (root->key > key)
		root->left = insertValueOfAVLTree(root->left, key);
	else if (root->key < key)
		root->right = insertValueOfAVLTree(root->right, key);
	root->height = getAVLTreeNodeHeight(root);
	return rebalance(root, key);
}

pAVLNODE removeValueOfAVLTree(pAVLNODE pRoot, int key)
{
	if (pRoot == NULL)
		return NULL;
	if (pRoot->key > key)
		pRoot->left = removeValueOfAVLTree(pRoot->left, key);
	else if (pRoot->key < key)
		pRoot->right = removeValueOfAVLTree(pRoot->right, key);
	else if (pRoot->key == key)
	{
		if (pRoot->left == NULL)
			pRoot = pRoot->right;
		else if (pRoot->right == NULL)
			pRoot = pRoot->left;
		else if (pRoot->left && pRoot->right)
		{
			pAVLNODE pLeftMax = getMaxValueOfAVLTree(pRoot->left);
			pAVLNODE pRightMin = getMinValueOfAVLTree(pRoot->right);
			int dist = 2 * pRoot->key - pLeftMax->key - pRightMin->key;
			if (dist <= 0)
			{
				pRoot->key = pLeftMax->key;
				pRoot->left = removeValueOfAVLTree(pRoot->left, pLeftMax->key);
			}
			else
			{
				pRoot->key = pRightMin->key;
				pRoot->right = removeValueOfAVLTree(pRoot->right, pRightMin->key);
			}
		}
	}
	return rebalance(pRoot, key);
}

void destroyAVLTree(pAVLNODE pTree)
{
	if (pTree)
	{
		destroyAVLTree(pTree->left);
		destroyAVLTree(pTree->right);
		free(pTree);
	}
}