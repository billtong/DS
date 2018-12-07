#include"ZHeader.h"

binarytreenode * initBinaryTreeNode(int value, int key)
{
	binarytreenode *node = (binarytreenode *)malloc(sizeof(binarytreenode));
	node->key = key;
	node->value = value;
	node->left = NULL;
	node->right = NULL;
	node->height = 0;
	return node;
}

binarytree * initBinaryTree()
{
	binarytree *bt = (binarytree *)malloc(sizeof(binarytree));
	bt->root = NULL;
	return bt;
}

binarytreenode *insertLevelNode(arraylist *al, binarytreenode *root, int i, int nodeNum) {

	if (i < nodeNum && al) {
		root = initBinaryTreeNode(10, al->arr[i]);
		root->left = insertLevelNode(al, root->left, 2*i+1, nodeNum);
		root->right = insertLevelNode(al, root->right, 2*i+2, nodeNum);
	}
	return root;
}

binarytree * getBinaryTree(int nodeNum)
{
	
	arraylist *al = initArrayList();
	for (int i = 0; i < nodeNum; i++) {
		append(al, i + 1);
	}
	
	binarytree *bt = initBinaryTree();
	bt->root = insertLevelNode(al, bt->root, 0, nodeNum);
	return bt;
}

int getBinaryTreeHeight(binarytreenode * root)
{
	//int height = -1;
	if (root == NULL) {
		return -1;
	} else 
	{
		int leftHeight = getBinaryTreeHeight(root->left);
		int rightHeight = getBinaryTreeHeight(root->right);
		return (leftHeight > rightHeight ? leftHeight : rightHeight)+1;
	}

}


binarytreenode * findParentNode(binarytreenode * root, int key)
{
	if (root == NULL)
		return NULL;

	if ((root->left && root->left->key == key) || (root->right && root->right->key == key)) {
		return root;
	}
	else {
		binarytreenode* left = findParentNode(root->left, key);
		binarytreenode* right = findParentNode(root->right, key);
		

		//这里和findNodeByKey方法一样
		if (left) {
			return left;
		}
		if (right) {
			return right;
		}
		return NULL;
	}
}

binarytreenode *findNodeByKey(binarytreenode *root, int key)
{
	/*
	先判断root的话，在往后的逻辑中就不用再判断root是不是为空了
	*/
	if (root == NULL) {
		return NULL;
	}
	
	if (root->key == key) {
		return root;
	}
	else {
		binarytreenode *left = findNodeByKey(root->left, key);
		binarytreenode *right = findNodeByKey(root->right, key);
	
		//这里的两句是否为空的判断是防止
		//返回null，将找到的结果覆盖掉
		if (left)
			return left;
		if (right)
			return right;
	
		
		//其他如果什么都没找到的话就返回null了
		return NULL;
	}
	
}

void preoderPrintBinaryTree(binarytreenode *root)
{
	printf("{");
	if (root) {
		printf("%d", root->key);
		preoderPrintBinaryTree(root->left);
		preoderPrintBinaryTree(root->right);
	}
	printf("}");
}

void inorderPrintBinaryTree(binarytreenode * root)
{
	printf("{");
	if (root) {
		inorderPrintBinaryTree(root->left);
		printf("%d ",root->key);
		inorderPrintBinaryTree(root->right);
	}
	printf("}");
}

void postorderPrintBinaryTree(binarytreenode * root)
{
	printf("{");
	if (root) {
		postorderPrintBinaryTree(root->left);
		postorderPrintBinaryTree(root->right);
		printf("%d",root->key);
	}
	printf("}");
}


void breathfirstPrintBinaryTree(binarytree *bt)
{
	printf("breathfirstPrint:	");
	linkedqueue *lq = initLinkedQueue();
	if (bt->root) {
		linkedEnqueue(lq, bt->root->key);
		while (!isLinkedQueueEmpty(lq)) {
			binarytreenode* r = findNodeByKey(bt->root, linkedDequeue(lq));
			printf("%d  ",r->key );
			if (r->left) {
				linkedEnqueue(lq, r->left->key);
			}
			if (r->right) {
				linkedEnqueue(lq, r->right->key);
			}
			
		}
	}
	printf("\n");
}


void freeBinaryTree(binarytreenode * root)
{
	if (root) {
		freeBinaryTree(root->left);
		freeBinaryTree(root->right);
		free(root);
	}
}

