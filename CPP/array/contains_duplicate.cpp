// Source : https://leetcode.com/problems/contains-duplicate/
// Author : Jiahao Liang
// Date   : 01-17-2022

/*********************************************************************************** 

Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

Example 1:
Input: nums = [1,2,3,1]
Output: true

Example 2:
Input: nums = [1,2,3,4]
Output: false

Example 3:
Input: nums = [1,1,1,3,3,4,3,2,4,2]
Output: true
 
Constraints:
1 <= nums.length <= 105
-109 <= nums[i] <= 109

***********************************************************************************/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if(nums.empty() || nums.size() == 1)
        {
            return false;
        }
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        std::sort(nums.begin(), nums.end());
        for(size_t i = 0; i < nums.size()-1; ++i)
        {
            if(nums.at(i) == nums.at(i+1))
            {
                return true;
            }
        }
        return false;
    }
};
