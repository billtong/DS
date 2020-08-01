#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <map>

#include "MyUtil.h"

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};