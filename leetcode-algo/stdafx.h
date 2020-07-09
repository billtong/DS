#pragma once

#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};