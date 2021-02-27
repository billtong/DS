#pragma once

// util
#include <iostream>
#include <string>
#include <functional>
#include <sstream>

// data structure
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <unordered_set>
#include <algorithm>

//threads
#include <mutex>
#include <condition_variable>
#include <thread>

#include "MyUtil.h"

using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// question 0430 doubly linked list
class Node
{
public:
	int val;
	Node *prev;
	Node *next;
	Node *child;
};

//Definition for a binary tree node. q0938
struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
