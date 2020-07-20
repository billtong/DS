#include "stdafx.h"
/*
Given an input string (s) and a pattern (p), implement regular expression matching with support for '.' and '*'.
	'.' Matches any single character.
	'*' Matches zero or more of the preceding element.
The matching should cover the entire input string (not partial).

Note:
	s could be empty and contains only lowercase letters a-z.
	p could be empty and contains only lowercase letters a-z, and characters like . or *.
*/

using namespace std;

class Solution10
{
public:

	/*
	Dynamic Programming Method (Bottom-Up)
	dp(i, j): does text[i:] and pattern[j:] match
	*/
	bool isMatch(string s, string p)
	{
		int m = s.length(), n = p.length();
		bool** t = new bool* [m + 1];
		for (int i = 0; i < m + 1; i++)
		{
			t[i] = new bool[n + 1];
			memset(t[i], false, n + 1);
		}
		t[m][n] = true;
		for (int i = m; i >= 0; i--)
		{
			for (int j = n-1; j >= 0; j--) // here -1 becase the pattern needs 2 char to match each iteration
			{
				bool first_match = i < s.length() && (s.at(i) == p.at(j) || p.at(j) == '.');
				if (j + 1 < p.length() && p.at(j + 1) == '*')
					t[i][j] = t[i][j + 2] || (first_match && t[i + 1][j]);
				else
					t[i][j] = first_match && t[i + 1][j + 1];
			}
		}
		return t[0][0];
	}


	/*
	Recursive Method
	Note: If a star is present in the pattern, it'll be in the second position pattern[1], then we may:
		1. Ignore this part of the pattern
		2. delete a matching character in the text
	*/
	bool isMatch_rec(string s, string p)
	{
		if (p.empty())
			return s.empty();
		bool first_match = !s.empty() && (s.at(0) == p.at(0) || p.at(0) == '.');
		int m = s.length(), n = p.length();
		if (p.length() >= 2 && p.at(1) == '*') // Kleene star condition
			return isMatch(s, p.substr(2, n - 2)) || (first_match && isMatch(s.substr(1, m - 1), p));
		else
			return first_match and isMatch(s.substr(1, m - 1), p.substr(1, n - 1));
	}
};

void main()
{
	Solution10 s;
	cout << s.isMatch("aa", "a") << endl;	//false
	cout << s.isMatch("aa", "a*") << endl;	//true
	cout << s.isMatch("ab", ".*") << endl;	//true
	cout << s.isMatch("aab", "c*a*b") << endl;	//true
	cout << s.isMatch("mississippi", "mis*is*p*.") << endl; //false
}