#ifndef AVLBINARYSEARCHTREE_H
#define AVLBINARYSEARCHTREE_H
#include "binarytree.h"
#include "binarysearchtree.h"
#include <stdlib.h>
#include<stdio.h>


typedef struct _AVLBinarySearchTree
{
	binarytreenode *root;

}avlbinarysearchtree;

avlbinarysearchtree *initAVLBinaryTree();

void calculateHeight(binarytreenode *root);

//左孩子的高度-右孩子的高度
int getBalanceFactor(binarytreenode *root);

binarytreenode *rotateLeft(binarytreenode *root);
binarytreenode *rotateRight(binarytreenode *root);


binarytreenode * rebalance(binarytreenode * root, int key);

//这里是如何使用到binarysearch tree的函数来完成呢？？
binarytreenode * insertAVLBinaryTree(binarytreenode * root, int value, int key);
binarytreenode *deleteAVLBinaryTree(binarytreenode *root, int key);



#endif // !AVLBINARYSEARCHTREE_H
#pragma once
