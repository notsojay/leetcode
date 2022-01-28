// Source : https://leetcode.com/problems/sum-of-square-numbers/
// Author : Jiahao Liang
// Date   : 01-27-2022

/*********************************************************************************** 

Given a non-negative integer c, decide whether there're two integers a and b such that a2 + b2 = c.

Example 1:
Input: c = 5
Output: true
Explanation: 1 * 1 + 2 * 2 = 5

Example 2:
Input: c = 3
Output: false
 
Constraints:
0 <= c <= 231 - 1

***********************************************************************************/ 

class Solution {
public:
    bool judgeSquareSum(int c) {
        if(c < 0)
        {
            return false;
        }
        long int left = 0, right = sqrt(c);
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        while(left <= right)
        {
            long int current = left * left + right * right;
            if(current < c)
            {
                ++left;
            }
            else if(current > c)
            {
                --right;
            }
            else
            {
                return true;
            }
        }
        return false;
    }
};
