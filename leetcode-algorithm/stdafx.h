#pragma once

// util
#include <iostream>
#include <string>
#include <functional>

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

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};
