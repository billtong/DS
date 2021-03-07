#include "stdafx.h"
/*
Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.
Example 1:
Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.
Example 2:
Input: "cbbd"
Output: "bb"
*/

class Solution5
{
public:
	/*
	Dynamic Programming
	using table[i, j] to store whether substring s[i,j] is Palindromic

	table[i, j] = (P(i+1, j-1) AND s[i] == s[j])

	Base case are "x" and "xx"
	table[i, i] = true
	table[i, i+1] = (s[i] == s[i+1])

	This solution here use bottom to top solution. (finish base cases initially)
	*/
	string longestPalindrome1(string s)
	{
		if (s.empty())
			return s;
		int start = 0, max_len = 1;
		int n = s.length();
		bool** table = new bool* [n];
		for (int i = 0; i < n; i++)
			table[i] = new bool[n];
		for (int i = n - 1; i >= 0; i--)
		{
			for (int j = i; j < n; j++)
			{
				if (i == j) // p[i, i] = True
					table[i][j] = true;
				else if (j - i == 1) //p[i, i+1] = s[i] == s[i+1]
					table[i][j] = s.at(i) == s.at(j);
				else
					table[i][j] = s.at(i) == s.at(j) && table[i + 1][j - 1]; //check if the s[j] s[i] same character, and then if substring s[i+1, j-1] palindromic
				if (table[i][j] && j - i + 1 > max_len)										 //record the pos of palindrome substring
				{
					start = i;
					max_len = j - i + 1;
				}
			}
		}
		return s.substr(start, max_len);
	}

	/* a cleaner version of the first function
	using 2d vector, iterating in a more nature sequence.
	combine if statements into condition operation
	0,0
	0,1 1,1
	0,2 1,2 2,2
	...
	*/
	string longestPalindrome2(string s)
	{
		if (s.empty())
			return s;
		int n = s.length();
		vector<vector<bool>> table(n, vector<bool>(n, false));
		int start = 0, max_len = 1;
		for (int j = 0; j < n; j++)
		{
			for (int i = j; i >= 0; i--)
			{
				table[i][j] = (i == j) || ((j - i == 1 || table[i + 1][j - 1]) && s.at(i) == s.at(j));
				if (table[i][j] && max_len < j - i + 1)
				{
					start = i;
					max_len = j - i + 1;
				}
			}
		}
		return s.substr(start, max_len);
	}

	/*
	check every char within string that whether they can form a palindrome
	clear and easy one
	*/
	string longestPalindrome3(string s)
	{
		if (s.empty())
			return s;
		int start = 0, max_len = 0;
		int m = s.length();
		for (int i = 0; i < m; i++)
		{
			int len1 = expandAroundCenter(s, i, i);			//search "a" type
			int len2 = expandAroundCenter(s, i, i + 1); //search "aa" type
			int len = len1 > len2 ? len1 : len2;
			if (len > max_len)
			{
				start = i - (len - 1) / 2;
				max_len = len;
			}
		}
		return s.substr(start, max_len);
	}

	int expandAroundCenter(string s, int l, int r)
	{
		while (l >= 0 && r < s.length() && s.at(l) == s.at(r)) //needs a symetric condition for both left and right border
		{
			l--;
			r++;
		}
		return r - l - 1; //this is interesting. a common value for both border and normal conditions
	}
};

//int main()
//{
//	cout << lp("babad");
//}

////a dynamic programming reference
//string find_lcs(string a, string b)
//{
//	int m = a.length() + 1;
//	int n = b.length() + 1;
//	int** table = new int* [m];
//	int result = 0, a_index = 0;
//	for (unsigned i = 0; i < m; i++)
//	{
//		table[i] = new int[n];
//		memset(table[i], 0, n * sizeof(int));
//	}
//	for (unsigned i = 1; i < m; i++)
//	{
//		for (unsigned j = 1; j < n; j++)
//		{
//			table[i][j] = a.at(i - 1) == b.at(j - 1) ? table[i - 1][j - 1] + 1 : 0;
//			if (table[i][j] > result)
//			{
//				result = table[i][j];
//				a_index = i - result;
//			}
//		}
//	}
//	return a.substr(a_index, result);
//}
