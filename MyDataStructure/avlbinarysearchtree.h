#ifndef AVLBINARYSEARCHTREE_H
#define AVLBINARYSEARCHTREE_H

#include "BinaryTree.h"

typedef struct _AVLBinarySearchTree
{
	binarytreenode *root;

}avlbinarysearchtree;

avlbinarysearchtree *initAVLBinaryTree();

void calculateHeight(binarytreenode *root);

//���ӵĸ߶�-�Һ��ӵĸ߶�
int getBalanceFactor(binarytreenode *root);

binarytreenode *rotateLeft(binarytreenode *root);

binarytreenode *rotateRight(binarytreenode *root);

//need change to all rebanlance,this one only change the leafs
binarytreenode * rebalance(binarytreenode * root, int key);

//���������ʹ�õ�binarysearch tree�ĺ���������أ���
binarytreenode * insertAVLBinaryTree(binarytreenode * root, int value, int key);

binarytreenode *deleteAVLBinaryTree(binarytreenode *root, int key);

#endif // !AVLBINARYSEARCHTREE_H
#pragma once
