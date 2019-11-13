/**
 * You are given two non-empty linked lists representing two non-negative integers. 
 * The digits are stored in reverse order and each of their nodes contain a single digit. 
 * Add the two numbers and return it as a linked list.
 * You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 * Example:
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 * Explanation: 342 + 465 = 807.
 */

#include "header.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    //my solution
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* iter1 = l1, * iter2 = l2;
		while (iter1 && iter2) {
			if (!iter1->next)
			{
				iter1 = l1;
				iter2 = l2;
				int adder = 0;
				sum(iter2, iter1);
				return l2;
			}
			if (!iter2->next)
			{
				iter1 = l1;
				iter2 = l2;
				sum(iter1, iter2);
				return l1;
			}
			iter1 = iter1->next;
			iter2 = iter2->next;
		}
		return new ListNode(-1);    //should never reach here
	}
	inline void sum(ListNode*& target, ListNode*& iter)
	{
		ListNode* temp;
		int adder = 0;
		while (iter || target) {
			int x = target ? target->val : 0;
			int y = iter ? iter->val : 0;
			int sum = x + y + adder;
			adder = sum < 10 ? 0 : 1;
			target->val = sum % 10;
			temp = target;
			target = target->next;
			if (iter)
				iter = iter->next;
		}
		if (adder) {
			temp->next = new ListNode(1);
		}
	}

    //solution with short lines
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode header(0), *iter = &header;
	    int curry = 0;
		while (l1 || l2 || curry)
		{
			if (l1) curry += l1->val, l1 = l1->next;
			if (l2) curry += l2->val, l2 = l2->next;
			iter->next = new ListNode(curry % 10);
			curry /= 10;
			iter = iter->next;
		}
		return header.next;
    }

};