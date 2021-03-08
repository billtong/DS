#include "stdafx.h"

/**
 * You are given a doubly linked list which in addition to the next and previous pointers,
 * it could have a child pointer, which may or may not point to a separate doubly linked list.
 * These child lists may have one or more children of their own, and so on, to produce a multilevel data structure, as shown in the example below.
 * Flatten the list so that all the nodes appear in a single-level, doubly linked list.
 * You are given the head of the first level of the list.
 */

class Node
{
public:
	int val;
	Node* prev;
	Node* next;
	Node* child;
};


class Solution
{
private:
	Node* ans;

public:
	Node* flatten(Node* head)
	{
		return dfs(head, nullptr);
	}

	Node* dfs(Node* head, Node* rest)
	{
		if (!head) // reach to the end of this child list.
			return rest;
		//meaning of below flattened(head->rest) ==> head->flattened(head->child)->flattened(head->next)->rest
		head->next = dfs(head->child, dfs(head->next, rest));
		if (head->next) // point next node's prev to head.
			head->next->prev = head;
		head->child = nullptr; //remove childs
		return head;
	}
};