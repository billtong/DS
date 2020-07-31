#include "stdafx.h"

/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
For example, given n = 3, a solution set is:
[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
*/

class Solution22 {
public:
    vector<string> res;
    int n;
    vector<string> generateParenthesis(int n) {
        this->n = n;
        backTrack("", 0, 0);
        return res;
    }

    void backTrack(string s, int left, int right) {
        if (s.length() == n * 2) {
            res.push_back(s);
            return;
        }
        if (left < n) //add left parenthese first
            backTrack(s + "(", left + 1, right);
        if (right < left) //right parenthese should always be less then left before ends.
            backTrack(s + ")", left, right + 1);
    }
};