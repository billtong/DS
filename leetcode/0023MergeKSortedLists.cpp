#include "stdafx.h"

/*
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
Example:
Input:
[
  1->4->5,
  1->3->4,
  2->6
]
Output: 1->1->2->3->4->4->5->6
*/

class Solution23
{
public:
	/*Merge with Divide and Conquer improved
	remove all the erase and push_back operation
	using index to set position
	*/
	ListNode* mergeKLists(vector<ListNode*>& lists)
	{
		if (lists.empty())
			return NULL;
		int n = lists.size();
		while (n > 1)
		{
			for (int i = 0; i < n / 2; i++)
				lists[i] = mergeTwoLists(lists[i], lists[n - i - 1]); //replace the front element with the merged one
			n = (n + 1) / 2;
		}
		return lists.front();
	}

	/*
	Merge with Divide and Conquer
	my way
	*/
	ListNode* mergeKLists_2(vector<ListNode*>& lists)
	{
		int n = lists.size();
		if (lists.size() == 0)
			return NULL;
		if (lists.size() == 1)
			return lists[0];
		if (lists.size() == 2)
		{
			return mergeTwoLists(lists[0], lists[1]);
		}
		else
		{
			for (int i = n - 1; i > 0; i -= 2)
			{
				ListNode* l1 = lists[i];
				ListNode* l2 = lists[i - 1];
				lists.erase(lists.begin() + i - 1, lists.begin() + i + 1);
				lists.push_back(mergeTwoLists(l1, l2));
			}
			return mergeKLists_2(lists);
		}
	}

	/*
	Merge lists one by one
	Convert merge \text{k}k lists problem to merge 2 lists (\text{k-1}k-1) times. Here is the merge 2 lists problem page
	*/
	ListNode* mergeKLists_3(vector<ListNode*>& lists)
	{
		if (lists.empty())
			return NULL;
		int n = lists.size();
		if (n == 1)
			return lists[0];
		ListNode* l1 = lists[0];
		ListNode* l2 = lists[1];
		ListNode* res = mergeTwoLists(l1, l2);
		if (lists.size() == 2)
		{
			return res;
		}
		else
		{
			lists.erase(lists.begin(), lists.begin() + 2);
			lists.insert(lists.begin(), res);
			return mergeKLists(lists);
		}
	}

	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
	{
		ListNode* res = new ListNode(0), * head = res;
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