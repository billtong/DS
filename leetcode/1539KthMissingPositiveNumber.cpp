#include "stdafx.h"

/**
* Given any array arr of positive integers sorted in a strictly increasing order, and an integer K.
* Find the kth positive integer that is missing from this array
* 
*  <
*/

class Solution 
{
private:
    vector<int> missings;
public:

    /*
    if k is smaller than first element of arr, then k is the result
    for other conditions: arr=[5, 8, 12], k = 10
    normal intergers: [1, 2, 3, 4, {5}, 6, 7, {8}, 9, 10, 11, {12}], but with arr[5, 8, 12] unreachable
    k is the index of the lefted elements in the array after remove arr
    if we add all the missing ones back we can trace back to the normal integer, which is the result
    */
    int findKthPositive(vector<int>& arr, int k)
    {
        for (auto a : arr) if (a <= k) k++;
        return k;
    }

    // my retarded code, please don't look
    int findKthPositive_bad(vector<int>& arr, int k) 
    {
        int count = 0;
        if (arr[0] > 1)
		{
            int between = arr[0] - 1;
            if (k <= between) {
                return k;
            }
            else {
                count += between;
            }
        }

		for (int i = 1; i < arr.size(); i++)
        {
            int between = arr[i] - arr[i - 1] - 1;

            if (k <= count + between)
            {
                return arr[i - 1] + k - count;
            }
            else
            {
                count += between;
            }
        }
        return arr[arr.size() - 1] + k - count; // should never be reached for k <= arr.size()
    }
};