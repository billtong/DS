#include "stdafx.h"

/**
 * Given an array of integers nums, find the maximum length of a subarray where the product of all its elements is positive.
 * A subarray of an array is a consecutive sequence of zero or more values taken out of that array.
 * Return the maximum length of a subarray with positive product.
 */

class Solution
{
	/**
	 * divide the array into sections by 0s, and try to find maax subarray length of each section
	 */
public:
	int getMaxLen(vector<int> &nums)
	{
		int res = 0;
		for (int i = 0; i < nums.size();) // i is the start index of the section divided by 0s
		{
			while (i < nums.size() && !nums[i])
				i++;								 //ignore leading 0s
			bool isNegEven = true; //flag for even or odd number of negative we've seen in this section
			int first = -1, last = -1;	//indices of first and last negative number so far
			int j = i;
			for (; j < nums.size(); j++)	// j is the end index of the section divided by 0s
			{
				if (!nums[j])
					break; //if meet 0 this section ends
				if (nums[j] < 0)
				{
					isNegEven = !isNegEven;
					(first < 0) && (first = j);
					last = j;
				}
			}
			// if the neg is even, all number of this section
			// if the neg is odd, withou first or last negative number
			//		from the start of section to the number before last negative number
			//		from the next number after first negative till end of the section
			res = max(res, isNegEven ? j - i : max(last - i, j - first - 1));
			i = j + 1;
		}
		return res;
	}
};
