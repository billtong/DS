#include "stdafx.h"

/**
 * You are given a string s of even length consisting of digits from 0 to 9, and two integers a and b.
 * You can apply either of the following two operations any number of times and in any order on s:
 * -	Add a to all odd indices of s (0-indexed). Digits post 9 are cycled back to 0. For example, if s = "3456" and a = 5, s becomes "3951"
 * -	Rotate s to the right by b positions. For example, if s = "3456" and b = 1, s becomes "6345".
 * Return the lexicographically smallest string you can obtain by applying the above operations any number of times on s.
 * A string a is lexicographically smaller than a string b (of the same length) if in the first position where a and b differ, string a has a letter that appears earlier in the alphabet than the corresponding letter in b. For example, "0158" is lexicographically smaller than "0190" because the first position they differ is at the third letter, and '5' comes before '9'.
 */

class Solution {
public:

	// use bfs
    string findLexSmallestString(string s, int a, int b) {
        unordered_set<string> seq;	//Keep track of already generated sequences so they are not processed again.
		queue<string> q;
		q.push(s);
		seq.insert(s);
		string ans = s;
		string temp;
		while(!q.empty()) {
			temp = add(q.front(), a);
			if (seq.find(temp) == seq.end()) {
				seq.insert(temp);
				q.push(temp);
			}
			temp = rotateRight(q.front(), b);
			if (seq.find(temp) == seq.end()) {
				seq.insert(temp);
				q.push(temp);
			}
			temp = q.front();
			ans = min(temp, ans); //generate all possible sequences and take their minimum.
			q.pop();
			
		}
		return ans;
    }

 	string add(string s, int a) {
        for (int i = 1; i < s.length(); i +=2 ) {
            s[i] = (s[i] -'0' + a) % 10 + '0';
        }
		return s;
    }

	string rotateRight(string s, int b) {
		int n = s.length();
		string temp = s;
		for (int i = 0; i < n; i++) {
			s[i] = temp[(i + b) % n];
		}
		return s;
	}

};
