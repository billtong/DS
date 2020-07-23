#include "stdafx.h"

/*
Write a function to find the longest common prefix string amongst an array of strings.
If there is no common prefix, return an empty string "".

Example 1:
	Input: ["flower","flow","flight"]
	Output: "fl"
Example 2:
	Input: ["dog","racecar","car"]
	Output: ""
Explanation: There is no common prefix among the input strings.

Note: All given inputs are in lowercase letters a-z.
*/

class Solution14 {
public:

	/*
	iterating through the list,
	match 0th and 1st get lcp#1
	then match lcp#1 with the next element
	...
	if meet "" return ""
	*/
	string longestCommonPrefix(vector<string>& strs) {
		int n = strs.size();
		if (n == 0)
			return "";
		else if (n == 1)
			return strs[0];
		else {
			string rslt = this->lcp(strs[0], strs[1]);
			for (int i = 2; i < n; i++) {
				if (rslt.empty()) return rslt;
				rslt = this->lcp(rslt, strs[i]);
			}
			return rslt;
		}
	}

	string lcp(string a, string b) {
		if (a.length() > b.length()) // length of string b is always larger
			return lcp(b, a);
		int i = 0;
		while (i < a.length() && a[i] == b[i])
			i++;
		return a.substr(0, i);
	}
};

//void main() {
//	Solution14 s;
//	cout << s.lcp("zaabcdefddg", "abcdddefg");
//}
