#include "stdafx.h"
/**
 * Given a string s containing only lower case English letters and the '?' character, 
 * convert all the '?' characters into lower case letters such that the final string does not contain any consecutive repeating characters. 
 * You cannot modify the non '?' characters.
 * It is guaranteed that there are no consecutive repeating characters in the given string except for '?'.
 * Return the final string after all the conversions (possibly zero) have been made. 
 * If there is more than one solution, return any of them. 
 * It can be shown that an answer is always possible with the given constraints.
 */

class Solution
{
public:
	string modifyString(string s)
	{
		int n = s.length();
		for (int i = 0; i < n; i++)
		{
			if (s[i] == '?')
			{
				for (char j = 'a'; j <= 'z'; j++)	//check all the characters with left and right
				{
					if ((i - 1 >= 0 && j == s[i - 1]) || (i + 1 < n && j == s[i + 1]))
						continue;
					s[i] = j;
					break;
				}
			}
		}
		return s;
	}
};