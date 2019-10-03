#include "CSubsetSum.h"

using std::cout;
using std::endl;
using std::to_string;

CSet::CSet(int m_nSum, vector<int> m_gElements) : m_nSum(m_nSum), m_gElements(m_gElements) {}

string CSet::toString()
{
	string str;
	str += ("sum: " + to_string(m_nSum) + "\nelements: ");
	for (int i = 0; i < m_gElements.size(); i++) {
		str += (to_string(m_gElements[i]) + "\t");
	}
	return str;
}

int* CSubsetSum::pair_sum(vector<CSet> set1, vector<CSet> set2, int k)
{
	int ptr1 = 0;
	int ptr2 = set2.size() - 1;
	while (ptr1 < set1.size && ptr2 >= 0)
	{
		int t = set1[ptr1].m_nSum + set2[ptr2].m_nSum;
		if (t == k)
			return new int[2]{ ptr1, ptr2 };
		else if (t < k)
			ptr1++;
		else
			ptr2++;
	}
	return new int[2]{ -1, -1 };
}

void CSubsetSum::bfi_subset_sum(const int s[],int size, int k)
{
	vector<CSet> subsets;
	subsets.push_back(* new CSet(0, * new vector<int>));
	for (int i = 0; i < size; i++) 
	{
		vector<CSet> newSubsets;
		for (int j = 0; j < subsets.size(); j++) 
		{
			CSet new_u(subsets[j].m_nSum, subsets[j].m_gElements);
			new_u.m_gElements.push_back(s[i]);
			new_u.m_nSum += s[i];
			if (new_u.m_nSum == k)
			{
				cout << new_u.toString() << endl;
				return;
			}
			else 
			{
				newSubsets.push_back(subsets[j]);
				newSubsets.push_back(new_u);
			}
		}
		subsets = newSubsets;
	}
	cout << "no subset sums to the target value" << endl;
}

void CSubsetSum::hs_subset_sum(const int s[], int size, int k)
{
	vector<int> subsets_left;
	vector<int> subsets_right;
	for (int i = 0; i < size; i++) {
		if (i < size / 2)
			subsets_left.push_back(s[i]);
		else
			subsets_right.push_back(s[i]);
	}
	vector<CSet> sum_left = get_bfi_subset_sum_list(subsets_left);
	vector<CSet> sum_right = get_bfi_subset_sum_list(subsets_right);
	for (int i = 0; i < subsets_left.size(); i++) {
		if (sum_left[i].m_nSum == k)
		{
			cout << sum_left[i].toString() << endl;
			return;
		}
	}
	for (int i = 0; i < subsets_right.size(); i++)
	{
		if (sum_right[i].m_nSum == k)
		{
			cout << sum_right[i].toString() << endl;
			return;
		}
	}
	/*
		sort sum_left & sum_right
	*/
	int *rslt = pair_sum(sum_left, sum_right, k);
	if (rslt[0] != -1 && rslt[1] != -1)
	{
		/*
			combine two sets into one 
		*/
	}
	else {
		cout << "no subset sums to the target value" << endl;
	}

}

vector<CSet> CSubsetSum::get_bfi_subset_sum_list(vector<int> s)
{
	vector<CSet> subsets;
	subsets.push_back(*new CSet(0, *new vector<int>));
	for (int i = 0; i < s.size(); i++)
	{
		vector<CSet> newSubsets;
		for (int j = 0; j < subsets.size(); j++)
		{
			CSet new_u(subsets[j].m_nSum, subsets[j].m_gElements);
			new_u.m_gElements.push_back(s[i]);
			new_u.m_nSum += s[i];
			newSubsets.push_back(subsets[j]);
			newSubsets.push_back(new_u);
		}
		subsets = newSubsets;
	}
	return subsets;
}
