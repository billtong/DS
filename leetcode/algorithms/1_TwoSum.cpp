/**
 * Given an array of integers, return indices of the two numbers 
 * such that they add up to a specific target.
 * You may assume that each input would have exactly one solution, 
 * and you may not use the same element twice.
 * Example:
 * Given nums = [2, 7, 11, 15], target = 9,
 * Because nums[0] + nums[1] = 2 + 7 = 9,
 * return [0, 1].
 */

/**
 * One-pass Hash Table
 * While we iterate and inserting elements into the table,
 * we also look back to check if current element's complement 
 * already exists in the table. If it exists, we have found a 
 * solution and return immediately
 */
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> hashMap;
        for (int i = 0; i < nums.size(); i++)
        {
            int complement = target - nums[i];
            if (hashMap.count(complement) > 0)
                return vector<int> {i, hashMap.at(complement)};
            hashMap[nums[i]] = i;
        }
        return vector<int>{};  /*should never be reached*/
    }
};
