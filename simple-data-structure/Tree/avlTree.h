#pragma once

#include "../stdafx.h"

typedef struct sAVLTreeNode
{
	int key;
	struct sAVLTreeNode* left;
	struct sAVLTreeNode* right;
	int height;
} AVLNode, *pAVLNODE;

pAVLNODE createAVLTreeNode(int);

// same 4 functions as the binary search tree
int preorderAVLTree(pAVLNODE);
int getAVLTreeNodeHeight(pAVLNODE);
int getMinValueOfAVLTree(pAVLNODE);
int getMaxValueOfAVLTree(pAVLNODE);
void destroyAVLTree(pAVLNODE);

int getBalanceFactor(pAVLNODE);

pAVLNODE rotateLeft(pAVLNODE);
pAVLNODE rotateRight(pAVLNODE);

pAVLNODE rebalance(pAVLNODE, int);
pAVLNODE insertValueOfAVLTree(pAVLNODE, int);
pAVLNODE removeValueOfAVLTree(pAVLNODE, int);