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
����1: ���root�ǿվ�return null

����2:�������root->key���ѣ��ݹ飩�ұ�
����3:���С��root->key���ѣ��ݹ飩���

������������Ⱦͷ���root
*/
binarytreenode* findBinarySearchTree(binarytreenode* root, int key);

/*��binary search tree����ֵ
����1: ���root�ǿվʹ���root

����2: �ж�root->key��key�Ĵ�С��ϵ ѡ��root���Լ���ݹ�root��������֮һ���нڵ㴴��(�˴��õ��ݹ�)
	-���root->child�����ھͻ��������һ�������µĽڵ㲢���ص���һ��ݹ���
	-����root->child ���ھͻ��������2��3 �����ݹ�

����3: ���root����
*/
binarytreenode* insertBinarySearchTree(binarytreenode* root, int value, int key);

/*��ȡһ��searching tree
{30{20{4{}{13{}{}}}{23{}{}}}{32{31{}{}}{103{34{33{}{}}{}}{}}}}
*/
binarysearchtree* getSampleBinarySearchTree();


/* delete node
condition1
root��ֵΪ�գ����ؿ���

condition2
root��keyֵ��key�������ӵݹ�

condition3
root��keyֵ��keyС�����Һ��ӵݹ�

condition4
root��ֵ����Ҫɾ���Ǹ�
	1��root������Ϊ��
	2��root���Һ���Ϊ��
	3������Ϊ�գ��ҵ�������root->key��ֵ�����滻��Ȼ��delete�ݹ���Ǹ���������node���Ƚ���ߵ������ұߵ���С��

condition5
��������������û�з��ض���
�ͷ���root
*/
binarytreenode* deleteBinarySearchTree(binarytreenode* root, int key);



#endif // !BINARYSEARCHTREE_H
#pragma once
