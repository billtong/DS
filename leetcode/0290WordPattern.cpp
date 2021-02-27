#include "stdafx.h"


/**
 * Given a pattern and a string s, find if s follows the same pattern.
 * Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in s.
 */

class Solution
{
public:
	bool wordPattern(string pattern, string str)
	{
		map<char, int> p2i;
		map<string, int> w2i;
		istringstream in(str);
		int i = 0, n = pattern.size();
		for (string word; in >> word; ++i)
		{
			if (i == n || p2i[pattern[i]] != w2i[word])
				return false;
			 // 1-based indexing since map assigns 0 as a default value for keys not found.
			p2i[pattern[i]] = w2i[word] = i + 1;
		}
		return i == n;
	}
};
