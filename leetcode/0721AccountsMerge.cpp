#include "stdafx.h"

/**
 * Given a list accounts, each element accounts[i] is a list of strings, where the first element accounts[i][0] is a name,
 * and the rest of the elements are emails representing emails of the account.
 * Now, we would like to merge these accounts.
 * Two accounts definitely belong to the same person if there is some email that is common to both accounts.
 * Note that even if two accounts have the same name, they may belong to different people as people could have the same name.
 * A person can have any number of accounts initially, but all of their accounts definitely have the same name.
 * After merging the accounts, return the accounts in the following format:
 * the first element of each account is the name, and the rest of the elements are emails in sorted order.
 * The accounts themselves can be returned in any order.
 */

 // user1's email: a,b,c; user2's email: d, b, e
 // a->a, b->b, c->c, d->d, e->e
 // a->d, b->a, c->a, d->d, e->d
 // d->[a, b, c, d, e]

class Solution
{
private:
	string findParent(unordered_map<string, string>& parents, string s)
	{
		if (parents[s] != s)
			parents[s] = findParent(parents, parents[s]);
		return parents[s];
	}

public:
	vector<vector<string>> accountsMerge(vector<vector<string>>& accounts)
	{
		unordered_map<string, string> parents;		 //key is the emails string, value is its parent node's email string
		unordered_map<string, string> owns;				 //key is the email string, value is the owner
		unordered_map<string, set<string>> unions; //key is the parrent node's email string, value is a list of all the nodes.
		vector<vector<string>> res;								 //return result

		for (int i = 0; i < accounts.size(); i++)
		{
			for (int j = 1; j < accounts[i].size(); j++)
			{
				parents[accounts[i][j]] = accounts[i][j]; // set all the emails node's parent to themselves
				owns[accounts[i][j]] = accounts[i][0];		//set the emails' owner name string
			}
		}

		for (int i = 0; i < accounts.size(); i++)
		{
			string parent = findParent(parents, accounts[i][1]); //set the first element of a email list as other's parents
			for (int j = 2; j < accounts[i].size(); j++)
				parents[findParent(parents, accounts[i][j])] = parent; //update the other email in the list as well as the nested parent nodes
		}

		for (int i = 0; i < accounts.size(); i++)
			for (int j = 1; j < accounts[i].size(); j++)
				unions[findParent(parents, accounts[i][j])].insert(accounts[i][j]);

		for (auto& pair : unions)
		{
			vector<string> emails(pair.second.begin(), pair.second.end());
			emails.insert(emails.begin(), owns[pair.first]);
			res.push_back(emails);
		}

		return res;
	}
};