#include"ZHeader.h"

binarysearchtree * initBinarySearchTree()
{
	binarysearchtree *bt = (binarysearchtree *)malloc(sizeof(binarysearchtree));
	bt->root = nullptr;
	return bt;
}

binarytreenode * findMinBinarySearchTree(binarytreenode * root)
{
	if (root && root->left) {
		return findMinBinarySearchTree(root->left);
	}
	return root;
}

binarytreenode * findMaxBinarySearchTree(binarytreenode * root)
{
	if (root && root->right) {
		return findMaxBinarySearchTree(root->right);
	}
	return root;
}

binarytreenode * findBinarySearchTree(binarytreenode * root, int key)
{

	if (root == nullptr)
		return nullptr;

	if (root->key > key) 
		return findBinarySearchTree(root->left, key);
	
	else if (root->key < key) 
		return findBinarySearchTree(root->right, key);
	else 
		return root;
	
}


binarytreenode * insertBinarySearchTree(binarytreenode * root, int value, int key)
{
	if (root == nullptr) {
		return initBinaryTreeNode(value, key);
	}

	if (root->key > key) {
		root->left = insertBinarySearchTree(root->left, value, key);
	}	else if ( root->key < key) 
	{
		root->right = insertBinarySearchTree(root->right, value, key);
	}
	return root;
}

binarysearchtree *getSampleBinarySearchTree()
{
	int arr[] = { 30, 32, 20, 103, 34, 31, 23, 4, 13, 33, };
	binarysearchtree *bt = initBinarySearchTree();
	//bt->root = initBinaryTreeNode(1, 30);
	for (int i = 0; i < 10; i++) {
		//insertBinarySearchTree(bt->root, i, arr[i]);
		bt->root = insertBinarySearchTree(bt->root, i, arr[i]);
	}
	return bt;
}

binarytreenode * deleteBinarySearchTree(binarytreenode *root, int key)
{
	if (root == nullptr) {
		return nullptr;
	}
	else if (root->key > key) {
		root->left = deleteBinarySearchTree(root->left, key);
	}
	else if (root->key < key) {
		root->right = deleteBinarySearchTree(root->right, key);
	}
	else if (root->key == key) {
		if (root->left == nullptr)
			root = root->right;
		else if (root->right == nullptr)
			root = root->left;
		else if (root->left && root->right) {
			binarytreenode *leftMax = findMaxBinarySearchTree(root->left);
			binarytreenode *rightMin = findMinBinarySearchTree(root->right);
			if ((root->key - leftMax->key) <= (rightMin->key - root->key)) {
				root->key = leftMax->key;
				root->left = deleteBinarySearchTree(root->left, leftMax->key);
			}
			else if((root->key - leftMax->key) > (rightMin->key - root->key)) {
				root->key = rightMin->key;
				root->right = deleteBinarySearchTree(root->right, rightMin->key);
			}

		}
	}

	return root;

}

