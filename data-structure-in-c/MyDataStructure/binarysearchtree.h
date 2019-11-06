#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include "BinaryTree.h"

typedef struct _BinarySearchTree
{
	binarytreenode* root;
} binarysearchtree;

binarysearchtree* initBinarySearchTree();

binarytreenode* findMinBinarySearchTree(binarytreenode* root);

binarytreenode* findMaxBinarySearchTree(binarytreenode* root);

/*find node
条件1: 如果root是空就return null

条件2:如果大于root->key就搜（递归）右边
条件3:如果小于root->key就搜（递归）左边

其他：即是相等就返回root
*/
binarytreenode* findBinarySearchTree(binarytreenode* root, int key);

/*向binary search tree插入值
条件1: 如果root是空就创建root

条件2: 判断root->key和key的大小关系 选择root（以及其递归root）的左右之一进行节点创造(此处用到递归)
	-如果root->child不存在就会进入条件一，生成新的节点并返回到上一层递归中
	-若果root->child 存在就会进入条件2或3 继续递归

条件3: 最后将root返回
*/
binarytreenode* insertBinarySearchTree(binarytreenode* root, int value, int key);

/*获取一个searching tree
{30{20{4{}{13{}{}}}{23{}{}}}{32{31{}{}}{103{34{33{}{}}{}}{}}}}
*/
binarysearchtree* getSampleBinarySearchTree();


/* delete node
condition1
root的值为空，返回空置

condition2
root的key值比key大，向左孩子递归

condition3
root的key值比key小，向右孩子递归

condition4
root的值就是要删的那个
	1）root的左孩子为空
	2）root的右孩子为空
	3）都不为空：找到最贴近root->key的值进行替换，然后delete递归掉那个最贴近的node（比较左边的最大和右边的最小）

condition5
以上所有情况如果没有返回东西
就返回root
*/
binarytreenode* deleteBinarySearchTree(binarytreenode* root, int key);



#endif // !BINARYSEARCHTREE_H
#pragma once
