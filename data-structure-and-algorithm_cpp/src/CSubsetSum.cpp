#include <cstdlib>
#include <utility>
#include "../include/CSubsetSum.h"
#include "../include/CSort.h"

using std::cout, std::endl, std::to_string;

CSet::CSet(int m_nSum, vector<int> m_gElements) : m_nSum(m_nSum), m_gElements(std::move(m_gElements)) {}

string CSet::toString()
{
	string str;
	str += ("sum:" + to_string(m_nSum) + "\nelements:");
	for (int i = 0; i < m_gElements.size(); i++) {
		str += (to_string(m_gElements[i]) + "\t");
	}
	return str;
}

CSet CSet::operator+(const CSet &operant) {
    vector<int> temp(&m_gElements[0], &m_gElements[m_gElements.size()]);
    temp.insert(temp.end(), operant.m_gElements.begin(), operant.m_gElements.end());
    CSet sum(m_nSum + operant.m_nSum, temp);
    return sum;
}

void CSet::operator=(const CSet &operant) {
    CSet::m_nSum = operant.m_nSum;
    CSet::m_gElements = operant.m_gElements;
}

bool CSet::operator>(const CSet &operant) { return CSet::m_nSum > operant.m_nSum; }

bool CSet::operator<(const CSet &operant) { return CSet::m_nSum < operant.m_nSum; }

bool CSet::operator==(const CSet &operant) { return CSet::m_nSum == operant.m_nSum; }

bool CSet::operator>=(const CSet &operant) { return CSet::m_nSum >= operant.m_nSum; }

CSet::CSet()
{
    CSet::m_nSum = 0;
}

int* CSubsetSum::pair_sum(vector<CSet> set1, vector<CSet> set2, int k)
{
	int ptr1 = 0;
	int ptr2 = set2.size() - 1;
	while (ptr1 < set1.size() && ptr2 >= 0)
	{
		int t = set1[ptr1].m_nSum + set2[ptr2].m_nSum;
		if (t == k)
		{
            return new int[2] {ptr1, ptr2};
        }
		else if (t < k)
			ptr1++;
		else
			ptr2--;
	}
    int  a[] = {-1, -1};
    return new int[2] {-1, -1};
}

void CSubsetSum::bfi_subset_sum(vector<int> s, int k)
{
    cout << "start bfi subset sum function" << endl;
	vector<CSet> subsets(10, * new CSet(0, * new vector<int>));
	for (int i = 0; i < s.size(); i++)
	{
		vector<CSet> newSubsets;
		for (auto & subset : subsets)
		{
			CSet new_u(subset.m_nSum, subset.m_gElements);
			new_u.m_gElements.push_back(s[i]);
			new_u.m_nSum += s[i];
			if (new_u.m_nSum == k)
			{
				cout << new_u.toString() << endl;
                cout << "stop bfi subset sum function" << endl << endl;
				return;
			}
			else 
			{
				newSubsets.push_back(subset);
				newSubsets.push_back(new_u);
			}
		}
		subsets = newSubsets;
	}
    cout << "not found sum" << endl;
    cout << "stop hs subset sum function" << endl << endl;
}

void CSubsetSum::hs_subset_sum(vector<int> s, int k)
{
    cout << "start hs subset sum function" << endl;
	vector<int> subsets_left(&s[0], &s[s.size() / 2 + 1]);
	vector<int> subsets_right(&s[s.size()/2], &s[s.size() + 1]);
	vector<CSet> sum_left = get_bfi_subset_sum_list(subsets_left);
	vector<CSet> sum_right = get_bfi_subset_sum_list(subsets_right);
	for (CSet left : sum_left) {
		if (left.m_nSum == k) {
            cout << left.toString() << endl;
            cout << "stop bfi subset sum function" << endl << endl;
            return;
		}

	}
	for (CSet right : sum_right)
	{
		if (right.m_nSum == k) {
            cout << right.toString() << endl;
            cout << "stop bfi subset sum function" << endl << endl;
            return;
		}
	}
    CSort<CSet>::MergeSort(sum_left);
	CSort<CSet>::MergeSort(sum_right);
	int * result = pair_sum(sum_left, sum_right, k);
	if (*result != -1 && *(result+1) != -1)
	{
		cout << (sum_left[result[0]] + sum_right[result[1]]).toString() << endl;
	} else {
        cout << "not found sum" << endl;
	}
    cout << "stop bfi subset sum function" << endl << endl;
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
