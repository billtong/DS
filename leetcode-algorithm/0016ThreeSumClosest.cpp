#include "stdafx.h"

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

class Solution16 {
public:
	int threeSUmCloset(vector<int>& nums, int target) {
		int n = nums.size();
		int diff = INT_MAX;
		sort(nums.begin(), nums.end(), nums);
		for (int i = 0; i < n - 2 && diff != 0; i++) {
			int l = i + 1, r = n - 1;
			while (l < r) {
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

	void quick_sort_rec(vector<int>& arr, int left, int right) {
		int l = left, r = right, p = arr[left];
		while (l < r) {
			while (arr[r] >= p && l < r)
				r--;
			if (l < r)
				arr[l++] = arr[r];
			while (arr[l] <= p && l < r)
				l++;
			if (l < r)
				arr[r--] = arr[l];
		}
		arr[l] = p;
		quick_sort_rec(arr, l, l - 1);
		quick_sort_rec(arr, r, l + 1);
	}
};
