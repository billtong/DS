#include "binarytree.h"
#include "binarysearchtree.h"
#include "avlbinarysearchtree.h"
#include <stdio.h>
#include <stdlib.h>

int isTestingBinaryTree = 1;
int isTestingSearchTree = 1;
int isTestingAVLBinaryTree = 1;

int main() 
{

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