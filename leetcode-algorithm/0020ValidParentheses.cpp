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

    // the left half of parentheses should always appear first
    bool isValid1(string s) {
        stack<char> stk;
        for (char& c : s) {
            switch (c) {
            case '(':
                stk.push(')');
                break;
            case '[':
                stk.push(']');
                break;
            case '{': 
                stk.push('}');
                break;
            default:
                if (stk.empty() || c != stk.top())
                    return false;
                else
                    stk.pop();
            }
        }
        return stk.empty();
    }

    //my sol
    bool isValid(string s) {
        map<char, int> parentheses;
        parentheses['('] = -1;
        parentheses[')'] = 1;
        parentheses['['] = -2;
        parentheses[']'] = 2;
        parentheses['{'] = -3;
        parentheses['}'] = 3;

        stack<int> stk;
        for (int i = 0; i < s.size(); i++) {
            if (!stk.empty() && stk.top() + parentheses[s[i]] == 0)
                stk.pop();
            else 
                stk.push(parentheses[s[i]]);
        }
        return stk.empty();
    }
};

