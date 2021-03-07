#include "stdafx.h"

/*
Given an array nums of n integers and an integer target,
find three integers in nums such that the sum is closest to target.
Return the sum of the three integers.
You may assume that each input would have exactly one solution.

Example 1:
Input: nums = [-1,2,1,-4], target = 1
Output: 2
Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
Constraints:
3 <= nums.length <= 10^3
-10^3 <= nums[i] <= 10^3
-10^4 <= target <= 10^4
*/

class Solution16
{
public:
	int threeSUmCloset(vector<int>& nums, int target)
	{
		int n = nums.size();
		int diff = INT_MAX;
		quick_sort_rec(nums, 0, n - 1);
		for (int i = 0; i < n - 2 && diff != 0; i++)
		{
			int l = i + 1, r = n - 1;
			while (l < r)
			{
				int sum = nums[i] + nums[l] + nums[r];
				if (abs(target - sum) < abs(diff))
					diff = target - sum;
				else if (target > sum) // the sum is too small, can increase l to increase it
					l++;
				else //the sum is too big, can decrease r to decrease it
					r--;
			}
		}
		return target - diff;
	}

	void quick_sort_rec(vector<int>& arr, int left, int right)
	{
		if (left < right)
		{
			int lo = left, hi = right;
			int p = arr[left];
			while (lo < hi)
			{
				while (lo < hi && arr[hi] >= p)
					hi--;
				if (lo < hi)
					arr[lo++] = arr[hi];
				while (lo < hi && arr[lo] <= p)
					lo++;
				if (lo < hi)
					arr[hi--] = arr[lo];
			}
			arr[lo] = p; //at this time lo and hi should be the same
			quick_sort_rec(arr, left, lo - 1);
			quick_sort_rec(arr, lo + 1, right);
		}
	}
};
