// Source : https://leetcode.com/problems/two-sum/
// Author : Jiahao Liang
// Date   : 01-18-2022

/*********************************************************************************** 

Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.

Example 1:
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

Example 2:
Input: nums = [3,2,4], target = 6
Output: [1,2]

Example 3:
Input: nums = [3,3], target = 6
Output: [0,1]
 
Constraints:
2 <= nums.length <= 104
-109 <= nums[i] <= 109
-109 <= target <= 109
Only one valid answer exists.

***********************************************************************************/ 

/*
Time Complexity:O(nlogn)
Time Complexity:O(n)
题目要求我们必须输出元素在数组中的位置，因为排序会改变元素在数组中的位置，所以这里使用了stl pair类型的vector；
这里的思路就是一头一尾两个指针；
每次判断的时候，我们将左右两个指针指向的元素加起来的和与我们要找的 target 对比，如果比 target 小，也就是说明如果在左指针不变的情况下，左指针加上左右指针中间的任意一个元素都会比 target 小，这也说明左指针不可能是我们要找的答案，因此向右移动左指针。
如果是加起来和我们要找的 target 对比，比 target 大，分析类似，这时需要将右指针向左移动。
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>> vec;
        if(nums.empty())
        {
            return {};
        }
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        for(size_t i = 0; i < nums.size(); ++i)
        {
            vec.push_back({nums.at(i),i});
        }
        std::sort(vec.begin(), vec.end());
        int leftIndex = 0;
        int rightIndex = vec.size()-1;
        int index1 = 0;
        int index2 = 0;
        while(leftIndex < rightIndex)
        {
            if(vec[leftIndex].first + vec[rightIndex].first == target)
            {
                index1 = vec[leftIndex].second;
                index2 = vec[rightIndex].second;
                break;
            }
            else if(vec[leftIndex].first + vec[rightIndex].first < target)
            {
                ++leftIndex;
            }
            else if(vec[leftIndex].first + vec[rightIndex].first > target)
            {
                --rightIndex;
            }
        }
        return {index1, index2};
    }
};
