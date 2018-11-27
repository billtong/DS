#ifndef BINARYTREE_H
#define BINARYTREE_H

/*		TREE BASIC CONCEPT
1. ROOT: node without parent
2. INTERNAL NODE: node with at least one child
3. LEAF: node without children(degree zero)
4. SUBTREE: tree consisting of a node and its decendats
5. NODE_DEGREE: the number of the subtrees associated with that node

6. PATH: a non-empty sequence of nodes	P = {r1, r2, ..., rk} the lenght of path is k-1
7. ANCESTOR/DECENDANT: if there exits a path from r1 to r2, then r1 is an ancestor of r2, r2 is an decendant of r1. r1 is an ancestor/decendant of itself.
PROPER ANCESTOR/DECENDANT: if path length from r1 to r2 is non-zero.

8. NODE_DEPTH(LEVEL): the length of the unique path in the tree from its root to the node.  the depth(level) is zero
9. NODE_HEIGHT: the length of the longest path from the wanted node to a leaf
10.TREE_HEIGHT: the NODE_HEIGHT of the root of the tree.
*/

/*Binary Tree
1. properties:
either the set is empty; or the set consists of a root, r, and exactly two distnct binary trees.

2. relations between TREE_HEIGHT, and NODE_NUMs
a binary tree of height h>=0 has at most 2^(h+1)-1 nodes
the height of a binary tree with n nodes at least log2(n+1)-1

3.relations between TREE_HEIGHT, and LEAF_NUMs
a binary tree of height h>=0 has at most 2^(h) leaves
the height of a inary tree with l leaves at least log2(l)
*/


typedef struct _BinaryTreeNode
{
	int value;
	int key;
	_BinaryTreeNode *left;
	_BinaryTreeNode *right;
	int height;
} binarytreenode;

typedef struct _MyBinaryTree
{
	binarytreenode *root;
}binarytree;

binarytreenode *initBinaryTreeNode(int value, int key);
binarytree *initBinaryTree();


//这里另外有一个递归函数封装在了cpp文件里

binarytree *getBinaryTree(int nodeNum);

//获取左右子节点高度的最大值，它加一就是高度
//空的话就返回-1

int getBinaryTreeHeight(binarytreenode *root);

/*
找节点用递归
每次递归中：先查看根节点的key是否是wanted，然后再查看孩子们的情况
注意的是：孩子们的情况一定要if判断，如果是非空的说明已经找到wanted的了一定要return到上一次递归中；
这样保证如果找到值后就能不断被return到上一层，而不会被NULL覆盖
*/
binarytreenode *findNodeByKey(binarytreenode *root, int key);


//先打印根节点。看着最容易

void preoderPrintBinaryTree(binarytreenode *root);
void inorderPrintBinaryTree(binarytreenode *root);
void postorderPrintBinaryTree(binarytreenode *root);

/*
一次循环中，根出队列，同时打印出该值；其孩子们就进入队列。
为了能够找到这个离开队列的根节点的地址，需要写一个通过key找到根节点的方法， 即findNodeByKey
*/
void breathfirstPrintBinaryTree(binarytree *bt);

//和findnode类似
binarytreenode *findParentNode(binarytreenode *root, int key);

/*
为了方便，最好用postorder
先free孩子再free根节点
*/
void freeBinaryTree(binarytreenode *root);

#endif // !BINARYTREE_H
#pragma once
