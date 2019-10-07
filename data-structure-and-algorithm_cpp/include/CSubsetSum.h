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
	CSet(int, vector<int>);
	string toString();
};

class CSubsetSum
{
private:
	static int * pair_sum(vector<CSet> set1, vector<CSet> set2, int k);
public:
	static void bfi_subset_sum(const int s[], int size, int k);
	static void hs_subset_sum(const int s[],int size, int k);
	static vector<CSet> get_bfi_subset_sum_list(vector<int> s);
};

