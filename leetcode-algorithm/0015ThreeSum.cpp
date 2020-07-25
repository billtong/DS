#include "stdafx.h"

/*
Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:

The solution set must not contain duplicate triplets.

Example:

Given array nums = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
*/

using namespace std;

/*
1. sort the array
2. lock down the current element you are at, 
then sweep the rest of the sorted array 
for two numbers that add up to zero minus the element locked down

pass all the duplicate triplets by 3 while loop
*/
class Solution15 {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> rslt;
        int n = nums.size();
        if (n >= 3)
        {
            this->quick_sort_rec(nums, 0, n - 1);
            for (int i = 0; i < n - 2; i++) {
                if (i == 0 || (i > 0 && nums[i] != nums[i - 1])) //prevent duplicate triplets with same i
                {
                    int left = i + 1;
                    int right = n - 1;
                    while (left < right)
                    {
                        if (nums[i] + nums[left] + nums[right] == 0) {
                            vector<int> m = { nums[i], nums[left], nums[right] };
                            rslt.push_back(m);
                            while (left < right && nums[left] == nums[left + 1]) //prevent duplicate triplets with same left
                                left++;
                            while (left < right && nums[right] == nums[right - 1]) //prevent duplicate triplets with same right
                                right--;
                            left++;
                            right--;
                        }
                        else if (nums[i] + nums[left] + nums[right] > 0) {
                            right--;
                        }
                        else {
                            left++;
                        }
                    }
                }
            }
        }
        return rslt;
    }
    void quick_sort_rec(vector<int>& arr, int left, int right) {
        if (left < right) {
            int i = left;
            int j = right;
            int pivot = arr[left];
            while (i < j) {
                while (arr[j] >= pivot && j > i)
                    j--;
                if (i < j)
                    arr[i++] = arr[j];
                while (arr[i] <= pivot && j > i)
                    i++;
                if (i < j)
                    arr[j--] = arr[i];
            }
            arr[i] = pivot;
            quick_sort_rec(arr, left, j - 1);
            quick_sort_rec(arr, j + 1, right);
        }
    }
};

void main()
{
    Solution15 s;
    vector<int> a = { 0, 0, 0 };
    s.threeSum(a);
}
