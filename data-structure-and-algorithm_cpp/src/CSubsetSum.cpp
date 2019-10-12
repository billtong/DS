#include <cstdlib>
#include <utility>
#include "../include/CSubsetSum.h"
#include "CSort.hpp"
#include "cmath"

using std::cout, std::endl, std::to_string;

CSet::CSet(int m_nSum, vector<int> m_gElements) : m_nSum(m_nSum), m_gElements(std::move(m_gElements)) {}

/**
 * format print output
 * @return
 */
string CSet::toString()
{
	string str;
	str += ("sum:" + to_string(m_nSum) + "\nelements:");
	for (int i = 0; i < m_gElements.size(); i++) {
		str += (to_string(m_gElements[i]) + "\t");
	}
	return str;
}

/**
 *
 * @param operant
 * @return
 */
CSet CSet::operator+(const CSet &operant) {
    vector<int> temp(&m_gElements[0], &m_gElements[m_gElements.size()]);
    temp.insert(temp.end(), operant.m_gElements.begin(), operant.m_gElements.end());
    CSet sum(m_nSum + operant.m_nSum, temp);
    return sum;
}

/**
 *
 * @param operant
 */
void CSet::operator=(const CSet &operant) {
    CSet::m_nSum = operant.m_nSum;
    CSet::m_gElements = operant.m_gElements;
}

/**
 *
 * @param operant
 * @return
 */
bool CSet::operator>(const CSet &operant) { return CSet::m_nSum > operant.m_nSum; }

/**
 *
 * @param operant
 * @return
 */
bool CSet::operator<(const CSet &operant) { return CSet::m_nSum < operant.m_nSum; }

/**
 *
 * @param operant
 * @return
 */
bool CSet::operator==(const CSet &operant) { return CSet::m_nSum == operant.m_nSum; }

/**
 *
 * @param operant
 * @return
 */
bool CSet::operator>=(const CSet &operant) { return CSet::m_nSum >= operant.m_nSum; }

CSet::CSet()
{
    CSet::m_nSum = 0;
}

/**
 * # Values_1 and Values_2 are sorted
 * # indexing starts at 1 because I am a dinosaur
 * p1 = 1
 * p2 = length(Values_2)
 * while (p1 <= length(Values_1) and (p2 >= 1):
 *      t = Values_1[p1] + Values_2[p2]
 *      if t == k:
 *          return (p1, p2)
 *      else if t < k:
 *          p1 = p1 + 1
 *      else:
 *          p2 = p2 – 1
 * return (-1, -1)
 * @param set1
 * @param set2
 * @param k
 * @return
 */
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

/**
 * pseudo code:
 * BFI_Subset_Sum(S,k):
 *      let subsets be an empty list of Set objects
 *      add empty_set to subsets
 *      for i = 1 to n:
 *          let new_subsets be an empty list of Set objects
 *          for each subset old_u in subsets:
 *              create a new Set object new_u with
 *              new_u.elements = old_u.elements with appended
 *              new_u.sum = old_u.sum + Si
 *              if new_u.sum == k:
 *                  STOP – new_u is the solution; print new_u
 *              else:
 *                  append old_u to new_subsets
 *                  append new_u to new_subsets
 *          subsets = new_subsets
 *  # no solution found
 *  print “no subset sums to the target value”
 * @param s
 * @param k
 */
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

/**
 * pseudocode
 * divide S into S_left and S_right, with n/2 elements in each (or as close as possible)
 * use (modified) BFI_Subset_Sum to get a list of all the subsets and their sums from S_left . Call these Subsets_Left and Sums_Left
 * do the same for S_right. Call the results Subsets_Right and Sums_Right
 * if k is in Sums_Left or Sums_Right:
 *      print the corresponding subset that sums to k
 * else:
 *      sort Sums_Left
 *      sort Sums_Right
 *      use the Pair_Sum algorithm (see below) to search for a value x in
 *      Sums_Left and a value y in Sums_Right such that x + y = k
 *      if found:
 *          print the corresponding subsets from Subsets_Left and Subsets_Right
 *      else:
 *          print “no subset sums to the target value”
 * @param s
 * @param k
 */
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

/**
 * calling be the HS_Subset_Sum function,
 * the modified  BFI_Subset_Sum function to get a list of all the subsets and their
 * sum from the left subset or right subset.
 * @param s
 * @return
 */
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

void CSubsetSum::bfi_subset_sum_opt(vector<int> s, int k, int &count)
{
    //cout << "start bfi subset sum function" << endl;
    count = 0;  // initialize the counter
    vector<CSet> subsets(10, * new CSet(0, * new vector<int>));
    count += 3; // moving data
    for (int i = 0; i < s.size(); i++)
    {
        count += 2; // incrementing i and compare i with size
        vector<CSet> newSubsets;
        for (auto & subset : subsets)
        {
            count += 2; // increment counter and compare size
            CSet new_u(subset.m_nSum, subset.m_gElements);
            new_u.m_gElements.push_back(s[i]);
            count += 2;   // accessing and moving data;
            new_u.m_nSum += s[i];
            count += 2;   // accessing and moving data;
            if (new_u.m_nSum == k)
            {
                count +=2; //accessing and comparing data
                //cout << new_u.toString() << endl;
                //cout << "stop bfi subset sum function" << endl << endl;
                return;
            }
            else
            {
                newSubsets.push_back(subset);
                count += 2; //accessing and ,moving
                newSubsets.push_back(new_u);
                count += 2; //same
            }
        }
        subsets = newSubsets;
        count++; // moving
    }
    //cout << "not found sum" << endl;
    //cout << "stop hs subset sum function" << endl << endl;
}

void CSubsetSum::hs_subset_sum_opt(vector<int> s, int k, int &count)
{
    count = 0;
    //cout << "start hs subset sum function" << endl;
    vector<int> subsets_left(&s[0], &s[s.size() / 2 + 1]);
    count += 2;
    vector<int> subsets_right(&s[s.size()/2], &s[s.size() + 1]);
    count += 2;
    vector<CSet> sum_left = get_bfi_subset_sum_list_opt(subsets_left, count);
    vector<CSet> sum_right = get_bfi_subset_sum_list_opt(subsets_right, count);
    for (CSet left : sum_left) {
        count += 2;
        if (left.m_nSum == k) {
            count += 2;
            //cout << left.toString() << endl;
            //cout << "stop bfi subset sum function" << endl << endl;
            return;
        }

    }
    for (CSet right : sum_right)
    {
        count += 2;
        if (right.m_nSum == k) {
            //cout << right.toString() << endl;
            //cout << "stop bfi subset sum function" << endl << endl;
            return;
        }
        count += 2;
    }
    CSort<CSet>::MergeSort(sum_left);
    count += (3 * sum_left.size() * log(sum_left.size()));
    CSort<CSet>::MergeSort(sum_right);
    count += (3 * sum_left.size() * log(sum_left.size()));
    int ptr1 = 0;
    int ptr2 = sum_left.size() - 1;
    int * result;
    while (ptr1 < sum_right.size() && ptr2 >= 0)
    {
        count += 2;
        int t = sum_right[ptr1].m_nSum + sum_left[ptr2].m_nSum;
        count += 2;
        if (t == k)
        {
            count ++;
            result = new int[2] {ptr1, ptr2};
            break;
        }
        else if (t < k) {
            ptr1++;
            count += 2;
        }
        else {
            ptr2--;
            count += 2;
        }
    }
    int  a[] = {-1, -1};
    if (*result != -1 && *(result+1) != -1)
    {
        //cout << (sum_left[result[0]] + sum_right[result[1]]).toString() << endl;
    } else {
        //cout << "not found sum" << endl;
    }
    count += 2;
    //cout << "stop bfi subset sum function" << endl << endl;
}

vector<CSet> CSubsetSum::get_bfi_subset_sum_list_opt(vector<int> s, int &count) {
    vector<CSet> subsets;
    subsets.push_back(*new CSet(0, *new vector<int>));
    count += 1;
    for (int i = 0; i < s.size(); i++)
    {
        count += 2;
        vector<CSet> newSubsets;
        for (int j = 0; j < subsets.size(); j++)
        {
            count += 2;
            CSet new_u(subsets[j].m_nSum, subsets[j].m_gElements);
            count += 2;
            new_u.m_gElements.push_back(s[i]);
            count += 2;
            new_u.m_nSum += s[i];
            count += 2;
            newSubsets.push_back(subsets[j]);
            count += 1;
            newSubsets.push_back(new_u);
            count += 1;
        }
        subsets = newSubsets;
        count += 1;
    }
    return subsets;
}
