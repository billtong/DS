#include "stdafx.h"

/**
 * Given an array nums and two types of queries where you should update the value of an index in the array,
 * and retrieve the sum of a range in the array
 * 
 * NumArray(int[] nums) Initializes the object with the integer array nums.
 * void update(int index, int val) Updates the value of nums[index] to be val.
 * int sumRange(int left, int right) Returns the sum of the subarray nums[left, right] 
 * (i.e., nums[left] + nums[left + 1], ..., nums[right]).
 * 
 */

class NumArray
{
	/**
	 * Sqrt Decomposition
	 * the idea is to split the array in blocks with length of sqrt(n).
	 * Then calculate the sum of each block and store it in auxiliary memory b.
	 * To query RSQ(i, j), we will add sums of all the blocks lying insides and those that partially overlap with range [i..j]
	 */
private:
	vector<int> nums;
	vector<int> b; // the size of b also the witdth of the block

public:
	NumArray(vector<int> &nums)
	{
		this->nums = nums;
		int len = (int)ceil(sqrt(nums.size()));
		this->b = vector<int>(len, 0);
		for (int i = 0; i < nums.size(); i++)
		{
			b[i / len] += nums[i];
		}
	}

	void update(int index, int val)
	{
		b[index / b.size()] -= (nums[index] - val); //remove the changes
		nums[index] = val;
	}

	int sumRange(int left, int right)
	{
		int sum = 0;
		int startBlock = left / b.size();
		int endBlock = right / b.size();
		if (startBlock == endBlock)
		{
			for (int i = left; i <= right; i++)
				sum += nums[i];
		}
		else
		{
			for (int i = left; i <= (startBlock + 1) * b.size() - 1; i++)
				sum += nums[i];
			for (int i = startBlock + 1; i <= endBlock - 1; i++)
				sum += b[i];
			for (int i = endBlock * b.size(); i <= right; i++)
				sum += nums[i];
		}
		return sum;
	}
};
