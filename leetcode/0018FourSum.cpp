#include "stdafx.h"

/*
Given an array nums of n integers and an integer target, are there elements a, b, c, and d in nums such that a + b + c + d = target? 
Find all unique quadruplets in the array which gives the sum of target.
Note:
The solution set must not contain duplicate quadruplets.

Example:
Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.
A solution set is:
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]
*/
class Solution18
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        this->sort(nums, 0, nums.size() - 1);
        return this->kSum(nums, 0, 4, target);
    }

    vector<vector<int>> kSum(vector<int> &arr, int start, int k, int target)
    {
        int n = arr.size();
        vector<vector<int>> res;
        if (k >= 2 && start != n && arr[start] * k <= target && arr[n - 1] * k >= target)
        { //check if the target is possible
            if (k == 2)
                res = twoSum(arr, start, target); //base condition: two sum
            else
            {
                for (int i = start; i < n; i++) //iterate from the index start
                {
                    if (i == start || (i > 0 && arr[i] != arr[i - 1])) //check the uniqueness of arr[i] from start
                    {
                        for (vector<int> &set : kSum(arr, i + 1, k - 1, target - arr[i])) //iterate through the result of the (k-1)sum
                        {
                            set.insert(set.begin(), arr[i]); //add new set to result
                            res.push_back(set);
                        }
                    }
                }
            }
        }
        // for testing
        /*cout << "start:" << start << "; k:" << k << "; target:" << target << endl;
        for (auto set : res)
        {
            for (auto e : set)
                cout << e << " ";
            cout << endl;
        }*/
        return res;
    }

    // two pointer method check q15 3sum for details
    vector<vector<int>> twoSum(vector<int> &arr, int start, int target)
    {
        int n = arr.size();
        int lo = start, hi = n - 1;
        vector<vector<int>> res;
        while (lo < hi)
        {
            int sum = arr[lo] + arr[hi];
            if (sum < target || lo > start && arr[lo] == arr[lo - 1])
                lo++;
            else if (sum > target || hi < n - 1 && arr[hi] == arr[hi + 1])
                hi--;
            else //the left condition is sum == target & unique pair of lo&hi
                res.push_back({arr[lo++], arr[hi--]});
        }
        return res;
    }

    /*
    quick sort code
    */
    void sort(vector<int> &arr, int left, int right)
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
            sort(arr, left, lo - 1);
            sort(arr, lo + 1, right);
        }
    }
};

//void main()
//{
//    //vector<int> four = { 1,0,-1,0,-2,2 };
//    vector<int> four = { 0, 0, 0, 0 };
//    Solution18 s;
//    vector<vector<int>> ts = s.fourSum(four, 0);
//}