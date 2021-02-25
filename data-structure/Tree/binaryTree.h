/*		
	TREE CONCEPT
- ROOT: node without parent
- INTERNAL NODE: node with at least one child
- LEAF: node without children(degree zero)
- SUBTREE: tree consisting of a node and its decendats
- NODE_DEGREE: the number of the subtrees associated with that node
- PATH: a non-empty sequence of nodes	P = {r1, r2, ..., rk} the lenght of path is k-1
- ANCESTOR/DECENDANT: if there exits a path from r1 to r2, then r1 is an ancestor of r2, r2 is an decendant of r1. r1 is an ancestor/decendant of itself.
- PROPER ANCESTOR/DECENDANT: if path length from r1 to r2 is non-zero.
 - NODE_DEPTH(LEVEL): the length of the unique path in the tree from its root to the node.  the root depth(level) is zero
 - NODE_HEIGHT: the length of the longest path from the wanted node to a leaf
- TREE_HEIGHT: the NODE_HEIGHT of the root of the tree.

	BINARY TREE CONCEPT
1. properties:
- either the set is empty; or the set consists of a root, r, and exactly two distnct binary trees.

2. relations between TREE_HEIGHT, and NODE_NUMs
- a binary tree of height h>=0 has at most 2^(h+1)-1 nodes
- the height of a binary tree with n nodes at least log2(n+1)-1

3.relations between TREE_HEIGHT, and LEAF_NUMs
- a binary tree of height h>=0 has at most 2^(h) leaves
-  with #leaf of leaves, the height of a inary tree is at least log2(#leaf)
*/
#pragma once

#include "../stdafx.h"
#include "../Queue/linkedQueue.h"

typedef struct sBinaryTreeNode
{
	int key;
	struct sBinaryTreeNode *left;
	struct sBinaryTreeNode *right;
} BTNode, *pBTNode;

pBTNode createBinaryTreeNode(int);
int getBinaryTreeNodeHeight(pBTNode);
void preorderBinaryTree(pBTNode);
void inorderBinaryTree(pBTNode);
void postorderBinaryTree(pBTNode);
void breathFirstTraverseBinaryTree(pBTNode);
void destroyBinaryTree(pBTNode);

/*
get sample tree
	   10
	 /    \
	20	   30
   /  \   /   \
 40	 50  60   70
	 /        /
	80       90
*/
void getSampleBinaryTree(pBTNode *);