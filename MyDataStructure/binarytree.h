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


//����������һ���ݹ麯����װ����cpp�ļ���

binarytree *getBinaryTree(int nodeNum);

//��ȡ�����ӽڵ�߶ȵ����ֵ������һ���Ǹ߶�
//�յĻ��ͷ���-1

int getBinaryTreeHeight(binarytreenode *root);

/*
�ҽڵ��õݹ�
ÿ�εݹ��У��Ȳ鿴���ڵ��key�Ƿ���wanted��Ȼ���ٲ鿴�����ǵ����
ע����ǣ������ǵ����һ��Ҫif�жϣ�����Ƿǿյ�˵���Ѿ��ҵ�wanted����һ��Ҫreturn����һ�εݹ��У�
������֤����ҵ�ֵ����ܲ��ϱ�return����һ�㣬�����ᱻNULL����
*/
binarytreenode *findNodeByKey(binarytreenode *root, int key);


//�ȴ�ӡ���ڵ㡣����������

void preoderPrintBinaryTree(binarytreenode *root);
void inorderPrintBinaryTree(binarytreenode *root);
void postorderPrintBinaryTree(binarytreenode *root);

/*
һ��ѭ���У��������У�ͬʱ��ӡ����ֵ���亢���Ǿͽ�����С�
Ϊ���ܹ��ҵ�����뿪���еĸ��ڵ�ĵ�ַ����Ҫдһ��ͨ��key�ҵ����ڵ�ķ����� ��findNodeByKey
*/
void breathfirstPrintBinaryTree(binarytree *bt);

//��findnode����
binarytreenode *findParentNode(binarytreenode *root, int key);

/*
Ϊ�˷��㣬�����postorder
��free������free���ڵ�
*/
void freeBinaryTree(binarytreenode *root);

#endif // !BINARYTREE_H
#pragma once
