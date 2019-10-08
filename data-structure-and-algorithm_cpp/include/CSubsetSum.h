#pragma once
#include<vector>
#include<iostream>
#include<string>

using std::string, std::vector;

class CSet
{
public:
	int m_nSum;
	vector<int> m_gElements;
    CSet();
	CSet(int, vector<int>);
	CSet operator+(const CSet &operant);
	void operator=(const CSet &operant);
	bool operator>(const CSet &operant);
	bool operator<(const CSet &operant);
	bool operator==(const CSet &operant);
	bool operator>=(const CSet &operant);
	string toString();
};

class CSubsetSum
{
private:
	static int * pair_sum(vector<CSet> set1, vector<CSet> set2, int k);
public:
	static void bfi_subset_sum(vector<int> s, int k);
	static void hs_subset_sum(vector<int> s, int k);
	static vector<CSet> get_bfi_subset_sum_list(vector<int> s);
};

