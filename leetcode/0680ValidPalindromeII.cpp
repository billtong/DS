#include "stdafx.h"

/**
 * Given a non-empty string s, you may delete at most one character.
 * Judge whether you can make it a palindrome.
 */

 /*
 first check s[i] == s[j]
 then check s[i+1] == s[j] || s[i] == s[j+1],
 be careful about special case s[i+1] == s[j] && s[i] == s[j+1], need to judge remove which element
 example: ...ucup...upuc..., need to delete left not right here.
 */
class Solution
{
public:
	bool validPalindrome(string s)
	{
		int i = 0, j = s.length() - 1, deleteNum = 0;
		bool ans = true;
		while (i < j && ans && deleteNum <= 1)
		{
			if (s[i] == s[j])
			{
				i++;
				j--;
			}
			else if (s[i + 1] == s[j] && (i + 1 == j || (s[i] != s[j - 1] || s[i + 2] == s[j - 1])))
			{
				deleteNum++;
				i++;
			}
			else if (s[i] == s[j - 1] && (i == j - 1 || (s[i + 1] != s[j] || s[i + 1] == s[j - 2])))
			{
				deleteNum++;
				j--;
			}
			else
			{
				ans = false;
			}
		}
		return (deleteNum <= 1) && ans;
	}
};
