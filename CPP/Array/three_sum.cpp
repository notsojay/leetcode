// Source : https://leetcode.com/problems/3sum/submissions/
// Author : Jiahao Liang
// Date   : 01-22-2022

/*********************************************************************************** 

Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
Notice that the solution set must not contain duplicate triplets.

Example 1:
Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]

Example 2:
Input: nums = []
Output: []

Example 3:
Input: nums = [0]
Output: []

Constraints:
0 <= nums.length <= 3000
-105 <= nums[i] <= 105

***********************************************************************************/ 

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::vector<std::vector<int>> result;
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        std::sort(nums.begin(), nums.end());
        for(size_t i = 0; i < nums.size(); ++i)
        {
            int target = -nums[i], front = i+1, back = nums.size()-1;
            while(front < back)
            {
                int sum = nums[front] + nums[back];
                if(sum < target)
                {
                    ++front;
                }
                else if(sum > target)
                {
                    --back;
                }
                else
                {
                    std::vector<int> temp = {nums[i], nums[front], nums[back]};
                    result.push_back(temp);
                    while(front < back && nums[front] == temp[1])
                    {
                        ++front;
                    }
                    while(front < back && nums[back] == temp[2])
                    {
                        --back;
                    }
                }
            }
            while(i+1 < nums.size() && nums[i+1] == nums[i])
            {
                ++i;
            }
        }
        return result;
    }
};
