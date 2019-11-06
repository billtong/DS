#include"ZHeader.h"

avlbinarysearchtree* initAVLBinaryTree()
{
	avlbinarysearchtree* bt = (avlbinarysearchtree*)malloc(sizeof(avlbinarysearchtree));
	bt->root = NULL;
	return bt;
}

void calculateHeight(binarytreenode* root)
{
	if (root) {
		root->height = getBinaryTreeHeight(root);
		if (root->left) {
			calculateHeight(root->left);
		}
		if (root->right) {
			calculateHeight(root->right);
		}
	}
}


int getBalanceFactor(binarytreenode* root)
{
	int lh, rh;
	if (root == NULL) {
		return 0;
	}

	lh = root->left ? root->left->height + 1 : 0;
	rh = root->right ? root->right->height + 1 : 0;

	return lh - rh;
}

binarytreenode* rotateLeft(binarytreenode* root)
{
	if (root) {
		binarytreenode* rc = root->right;
		root->right = rc->left;
		rc->left = root;

		rc->height = getBinaryTreeHeight(rc);
		root->height = getBinaryTreeHeight(root);
		return rc;
	}
	else {
		return NULL;
	}

}

binarytreenode* rotateRight(binarytreenode* root)
{
	if (root) {
		binarytreenode* rc = root->left;

		root->left = rc->right;
		rc->right = root;

		rc->height = getBinaryTreeHeight(rc);
		root->height = getBinaryTreeHeight(root);
		return rc;
	}
	else {
		return NULL;
	}
}

binarytreenode* rebalance(binarytreenode* root, int key)
{
	int balanceFactor = getBalanceFactor(root);

	if (balanceFactor > 1) {
		binarytreenode* rc = root->left;

		//Left of Left
		if (rc->key > key) {
			return rotateRight(root);
		}
		//left of right
		else if (rc->key < key) {
			root->left = rotateLeft(root->left);
			return rotateRight(root);
		}
	}
	else if (balanceFactor < -1)
	{
		binarytreenode* rc = root->right;
		//right of left
		if (rc->key > key) {
			root->right = rotateRight(root->right);
			return rotateLeft(root);
		}
		// right of right
		if (rc->key < key) {
			return rotateLeft(root);
		}

		/*
		if (getBalanceFactor(rc->left) == getBalanceFactor(rc->right) && getBalanceFactor(rc->left)==0) {
			if (rc->left && rc->right == nullptr) {
				root->right = rotateRight(root->right);
				return rotateLeft(root);
			}

			if (rc->left == nullptr && rc->right) {
				return rotateLeft(root);
			}
		}
		*/

	}

	return root;

}


binarytreenode* insertAVLBinaryTree(binarytreenode* root, int value, int key)
{
	if (root == NULL) {
		return initBinaryTreeNode(value, key);
	}

	if (root->key > key) {
		root->left = insertAVLBinaryTree(root->left, value, key);
	}
	else if (root->key < key)
	{
		root->right = insertAVLBinaryTree(root->right, value, key);
	}
	root->height = getBinaryTreeHeight(root);
	return  rebalance(root, key);
}

binarytreenode* deleteAVLBinaryTree(binarytreenode* root, int key)
{
	if (root == NULL) {
		return NULL;
	}
	else if (root->key > key) {
		root->left = deleteBinarySearchTree(root->left, key);
	}
	else if (root->key < key) {
		root->right = deleteBinarySearchTree(root->right, key);
	}
	else if (root->key == key) {
		if (root->left == NULL)
			root = root->right;
		else if (root->right == NULL)
			root = root->left;
		else if (root->left && root->right) {
			binarytreenode* leftMax = findMaxBinarySearchTree(root->left);
			binarytreenode* rightMin = findMinBinarySearchTree(root->right);
			if ((root->key - leftMax->key) <= (rightMin->key - root->key)) {
				root->key = leftMax->key;
				root->left = deleteBinarySearchTree(root->left, leftMax->key);
			}
			else if ((root->key - leftMax->key) > (rightMin->key - root->key)) {
				root->key = rightMin->key;
				root->right = deleteBinarySearchTree(root->right, rightMin->key);
			}

		}
	}


	return rebalance(root, key);


}
