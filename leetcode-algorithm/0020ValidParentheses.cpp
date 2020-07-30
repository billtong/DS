#include "stdafx.h"

/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Note that an empty string is also considered valid.
*/

class Solution20 {
public:

    //
    bool isValid(string s) {
        map<char, int> parentheses;
        parentheses['('] = -1;
        parentheses[')'] = 1;
        parentheses['['] = -2;
        parentheses[']'] = 2;
        parentheses['{'] = -3;
        parentheses['}'] = 3;

        vector<int> stack;
        for (int i = 0; i < s.size(); i++) {
            if (!stack.empty() && stack.back() + parentheses[s[i]] == 0)
                stack.pop_back();
            else 
                stack.push_back(parentheses[s[i]]);
        }
        return stack.size() == 0;
    }
};

