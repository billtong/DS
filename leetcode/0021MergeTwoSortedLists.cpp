#include "stdafx.h"

/*
Merge two sorted linked lists and return it as a new sorted list. The new list should be made by splicing together the nodes of the first two lists.
Example:
	Input: 1->2->4, 1->3->4
	Output: 1->1->2->3->4->4
*/

class Solution
{
public:
	// the head is for storing the result address;
	// the linked can be light copied, no need to deep copy
	ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
	{
		ListNode *res = new ListNode(0), *head = res;
		while (l1 && l2)
		{
			if (l1->val < l2->val)
			{
				res->next = l1;
				l1 = l1->next;
			}
			else
			{
				res->next = l2;
				l2 = l2->next;
			}
			res = res->next;
		}
		res->next = l1 ? l1 : l2;
		return head->next;
	}
};