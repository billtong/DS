#include "stdafx.h"

/*
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.
*/
class Solution
{
public:
    /*
    Backtracking is an algorithm for finding all solutions by exploring all potential candidates. 
    If the solution candidate turns to be not a solution (or at least not the last one), 
    backtracking algorithm discards it by making some changes on the previous step, i.e. backtracks and then try again.
    Here is a backtrack function backtrack(combination, next_digits) 
    which takes as arguments an ongoing letter combination and the next digits to check.
    */
    vector<string> letterCombinations(string digits)
    {
        map<string, string> phoneMap;
        phoneMap["2"] = "abc";
        phoneMap["3"] = "def";
        phoneMap["4"] = "ghi";
        phoneMap["5"] = "jkl";
        phoneMap["6"] = "mno";
        phoneMap["7"] = "pqrs";
        phoneMap["8"] = "tuv";
        phoneMap["9"] = "wxyz";

        vector<string> output;
        if (!digits.empty())
            backTracking("", digits, output, phoneMap);
        return output;
    }

    void backTracking(string combination, string nextDigits, vector<string> &output, map<string, string> phone)
    {
        if (nextDigits.empty())
            output.push_back(combination);
        else
        {
            string digit = nextDigits.substr(0, 1);
            string letters = phone[digit];
            for (int i = 0; i < letters.size(); i++)
            {
                string letter = phone[digit].substr(i, 1);
                backTracking(combination + letter, nextDigits.substr(1, nextDigits.size() - 1), output, phone);
            }
        }
    }
};