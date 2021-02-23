#include "stdafx.h"

/**
 * In a group of N people (labelled 0, 1, 2, ..., N-1), each person has different amounts of money, and different levels of quietness.
 * For convenience, we'll call the person with label x, simply "person x".
 * We'll say that richer[i] = [x, y] if person x definitely has more money than person y.  Note that richer may only be a subset of valid observations.
 * Also, we'll say quiet[x] = q if person x has quietness q.
 * Now, return answer, where answer[x] = y if y is the least quiet person (that is, the person y with the smallest value of quiet[y]), 
 * among all people who definitely have equal to or more money than person x.
*/

class Solution {
public:
		vector<int> quiet;
		vector<int> ans;
		vector<vector<int>> adjust;
    
		//O(N^2)
		vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
				vector<int> ans(quiet.size(), -1);
				this->ans = ans;
				adjust.resize(quiet.size());
				this->quiet = quiet;
				for (auto pair : richer)
					adjust[pair[1]].push_back(pair[0]);
				for (int i=0; i<quiet.size(); i++) {
					dfs(i);
				}
				return this->ans;
    }

		int dfs(int& x) { // the quietness of person y 
			if (ans[x] == -1) {
				ans[x] = x;
				for (auto person : adjust[x]) {
				    int temp = dfs(person);
				    if (quiet[temp] < quiet[ans[x]])
					    ans[x] = temp;
				}
			}
			return ans[x];
		}

};