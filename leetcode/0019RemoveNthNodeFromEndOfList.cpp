#include "stdafx.h"

/*
Given a linked list, remove the n-th node from the end of list and return its head.
Example:
Given linked list: 1->2->3->4->5, and n = 2.
After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:
Given n will always be valid.
header store the first node data
*/

class Solution
{
public:
	/*
	Maintain two pointers and update one with a delay of n steps.
	*/
	ListNode* removeNthFromEnd(ListNode* head, int n)
	{
		ListNode* fast = head, * slow = fast;
		for (int j = 0; j < n; j++)
			fast = fast->next;
		if (fast == NULL) //n is equal to the length of the list, remove header
			return head->next;
		while (fast->next)
		{ //make sure the final position is one node a head of the target
			fast = fast->next;
			slow = slow->next;
		}
		slow->next = slow->next->next;
		return head;
	}
};