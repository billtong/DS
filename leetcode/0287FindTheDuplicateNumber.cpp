#include "stdafx.h"

/**
 * Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.
 * There is only one repeated number in nums, return this repeated number.
 */ 

class Solution
{
public:
	int findDuplicate(vector<int> &nums)
	{
		for (int i = 0; i < nums.size(); i++)
		{
			int index = abs(nums[i]) - 1;
			nums[index] *= -1; //turn value to negative to mark that this value has been visited without losing the original value.
			if (nums[index] > 0)
				return abs(nums[i]);
		}
		return -1; //should not be reached
	}
};
